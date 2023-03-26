#include <iostream>
#include <string>
#include <optional>

#include <array>
#include <vector>

#include <fmt/core.h>
#include <fmt/color.h>

#include "bytecode_gen.hpp"
#include "instructions_set.hpp"

using namespace VM_Bytecode;
using namespace VM_Bytecode::Assembling;

namespace {
    [[noreturn]] inline void report_err(const std::string& message, size_t line) {
        std::string err = fmt::format("{} (line {}): {}\n",
            fmt::styled("error", fg(fmt::color::red)),
            line,
            message
        );
        throw std::runtime_error(err);
    }

    std::unordered_map<std::string, uint64_t> labels;
}

bytecode_gen::bytecode_gen(const std::string& filename) {
    this->in_source = std::ifstream(filename);
}

const std::vector<uint8_t>& bytecode_gen::generate() {
    if (!in_source.is_open()) report_err("incorrect IL file was passed to bytecode generator", 0);

    std::unordered_map<std::string, std::pair<size_t, size_t>> labelsReprocessing;

    std::string raw_line;
    for(size_t lineno = 0; std::getline(this->in_source, raw_line); ++lineno) {
        std::string_view line{raw_line};

        std::optional<uint8_t> prefix = std::nullopt;

        if (line.empty() || line.starts_with("//")) continue;
        else if (line.starts_with("label ")) {
            labels.insert({line.substr(6).data(), this->bytecode.size() - 1});
            continue;
        }
        else if (line.starts_with("[[BITS8]] ")) {
            prefix = 0x8;
            line = line.substr(10);
        }
        else if (line.starts_with("[[BITS16]] ")) {
            prefix = 0x10;
            line = line.substr(11);
        }
        else if (line.starts_with("[[BITS32]] ")) {
            prefix = 0x20;
            line = line.substr(11);
        }
        else if (line.starts_with("[[BITS64]] ")) {
            // default mode, no prefix change
            line = line.substr(11);
        }
        else if (line.starts_with("[[BITS")) {
            report_err("invalid size prefix", lineno + 1);
        }
        
        size_t ws_pos = line.find(' ');
        std::string op = std::string(line.substr(0, ws_pos));

        if (prefix.has_value() && !size_prefixed_ops.count(op)) {
            report_err(fmt::format("operation '{}' can't be prefixed by a size prefix", op), lineno + 1);
        }
        else if (prefix.has_value()) {
            this->bytecode.push_back(prefix.value());
        }    
        this->bytecode.push_back(opcodes.at(op));

        if (ws_pos == std::string::npos) continue;
        else if (one_operand_ops.count(op)) {
            if (op == "load_c") {
                std::string_view arg = line.substr(ws_pos + 1);
                uint64_t n = std::stoi(arg.data());

                std::array<uint8_t, sizeof(uint64_t)> buf;
                std::copy(&n, &n + sizeof(uint64_t), buf.data());

                this->bytecode.insert(this->bytecode.end(), buf.cbegin(), buf.cend());
            }
            else if (op == "load_v" || op == "store") {
                std::string_view arg = line.substr(ws_pos + 1);
                uint16_t n = std::stoi(arg.data());

                std::array<uint8_t, sizeof(uint16_t)> buf;
                std::copy(&n, &n + sizeof(uint16_t), buf.data());

                this->bytecode.insert(this->bytecode.end(), buf.cbegin(), buf.cend());
            }
            else if (op == "call") {
                std::string_view arg = line.substr(ws_pos + 1);
                if (!labels.count(arg.data())) {
                    labelsReprocessing.insert({arg.data(), {lineno + 1, this->bytecode.size()}});
                    this->bytecode.resize(this->bytecode.size() + sizeof(uint64_t));
                    continue;
                }
                
                uint64_t addr = labels.at(arg.data());

                std::array<uint8_t, sizeof(uint64_t)> buf;
                std::copy(&addr, &addr + sizeof(uint64_t), buf.data());

                this->bytecode.insert(this->bytecode.end(), buf.cbegin(), buf.cend());
            }
        }
        else if (two_operand_ops.count(op)) {
            if (op == "natcall") {
                std::string_view operands = line.substr(ws_pos + 1);
                size_t ws2_pos = operands.find(',');
                if (ws2_pos == std::string::npos) report_err("missing second operand on natcall", lineno + 1);

                std::string_view lib = operands.substr(0, ws2_pos);
                std::string_view sym = operands.substr(ws2_pos);
            }
        }
    }

    for (const auto& label_pair : labelsReprocessing) {
        if (!labels.count(label_pair.first)) report_err(fmt::format("unknown label: '{}'", label_pair.first), label_pair.second.first);

        uint64_t addr = labels.at(label_pair.first);
        std::copy(&addr, &addr + sizeof(uint64_t), &this->bytecode[label_pair.second.second]);
    }

    return this->bytecode;
}