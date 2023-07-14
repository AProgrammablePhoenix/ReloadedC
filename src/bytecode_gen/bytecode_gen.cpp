#include <iostream>
#include <string>
#include <sstream>
#include <optional>

#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
    template <class T> inline void hash_combine(std::size_t & seed, const T & v) {
        std::hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    template<typename S, typename T> struct pair_hash {
        inline std::size_t operator()(const std::pair<S, T> & v) const {
            std::size_t seed = 0;
            hash_combine(seed, v.first);
            hash_combine(seed, v.second);
            return seed;
        }
    };
    template<typename T> union raw_bytes {
        uint8_t raw[sizeof(T)];
        T v;
    };
    template<typename T> raw_bytes<T> get_raw_bytes(T v) {
        return raw_bytes{.v = v};
    }
    class mapped_vector {
    public:
        mapped_vector() = default;
        void insert(const std::pair<std::string, std::string>& value) {
            this->_container.push_back(value);
            this->_set.insert(value);
        }
        bool contains(const std::pair<std::string, std::string>& value) const {
            return this->_set.contains(value);
        }
        size_t indexof(const std::pair<std::string, std::string>& value) const {
            for (size_t i = 0; i < this->_container.size(); ++i) {
                if (this->_container[i] == value) {
                    return i;
                }
            }

            throw std::out_of_range("Key not found in mapped vector");
        }
        size_t size() const {
            return this->_container.size();
        }
        const std::pair<std::string, std::string>& operator[](size_t i) const {
            return this->_container[i];
        }
        std::pair<std::string, std::string>& operator[](size_t i) {
            return this->_container[i];
        }
    private:        
        std::vector<std::pair<std::string, std::string>> _container;
        std::unordered_set<std::pair<std::string, std::string>, pair_hash<std::string,std::string>> _set;
    };

    std::unordered_map<std::string, uint64_t> labels;
}

bytecode_gen::bytecode_gen(const std::string& filename) {
    this->in_source = std::ifstream(filename);
}

const std::vector<uint8_t>& bytecode_gen::generate() {
    if (!in_source.is_open()) report_err("incorrect IL file was passed to bytecode generator", 0);

    constexpr size_t sizeof_header = sizeof(bytecode_header);
    bytecode_header header;

    std::unordered_map<std::string, std::pair<size_t, size_t>> labelsReprocessing;
    mapped_vector natcall_symbol_table;

    std::vector<uint8_t> data_section;
    std::unordered_map<size_t, size_t> data_index_map;

    std::string raw_line;
    for(size_t lineno = 0; std::getline(this->in_source, raw_line); ++lineno) {
        std::string_view line{raw_line};

        std::optional<uint8_t> prefix = std::nullopt;

        if (line.empty() || line.starts_with("//")) continue;
        else if (line.starts_with("label ")) {
            labels.emplace(line.substr(6).data(), sizeof_header + this->bytecode.size() - 1);
            continue;
        }
        else if (line.starts_with(".string ")) {
            std::string _str = line.substr(8).data();
            data_index_map.emplace(data_index_map.size(), data_section.size());

            std::stringstream ss(_str);
            size_t _temp_char;
            
            while (ss >> _temp_char) {
                data_section.push_back(_temp_char);
            }

            data_section.push_back(0);
            continue;
        }
        else if (line.starts_with("[[BITS8]] ")) {
            prefix = prefix8;
            line = line.substr(10);
        }
        else if (line.starts_with("[[BITS16]] ")) {
            prefix = prefix16;
            line = line.substr(11);
        }
        else if (line.starts_with("[[BITS32]] ")) {
            prefix = prefix32;
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

        if (prefix.has_value() && !size_prefixed_ops.contains(op)) {
            report_err(fmt::format("operation '{}' can't be prefixed by a size prefix {:#x}", op, prefix.value()), lineno + 1);
        }
        else if (prefix.has_value()) {
            this->bytecode.push_back(prefix.value());
        }
        this->bytecode.push_back(opcodes.at(op));

        if (ws_pos == std::string::npos) continue;
        else if (one_operand_ops.count(op)) {
            std::string_view arg = line.substr(ws_pos + 1);

            if (op == "load_c") {                
                uint64_t n = std::stoull(arg.data());

                if (!prefix.has_value()) {                
                    raw_bytes raw64 = get_raw_bytes<uint64_t>(n);
                    this->bytecode.insert(this->bytecode.end(), raw64.raw, raw64.raw + sizeof(uint64_t));
                } else if (prefix == prefix8) {
                    this->bytecode.emplace_back(n);
                } else if (prefix == prefix16) {
                    raw_bytes raw16 = get_raw_bytes<uint16_t>((uint16_t)n);
                    this->bytecode.insert(this->bytecode.end(), raw16.raw, raw16.raw + sizeof(uint16_t));
                }
                else if (prefix == prefix32) {
                    raw_bytes raw32 = get_raw_bytes<uint32_t>((uint32_t)n);
                    this->bytecode.insert(this->bytecode.end(), raw32.raw, raw32.raw + sizeof(uint32_t));
                }
            }
            else if (op == "load_v" || op == "mkptr" || op == "store") {
                uint16_t n = (uint16_t)std::stoul(arg.data());
                raw_bytes raw16 = get_raw_bytes<uint16_t>(n);
                this->bytecode.insert(this->bytecode.end(), raw16.raw, raw16.raw + sizeof(uint16_t));
            }
            else if (op == "ldptr") {
                uint64_t idx = (uint64_t)std::stoull(arg.data());
                uint64_t real_idx = data_index_map.at(idx);
                raw_bytes raw64 = get_raw_bytes<uint64_t>(real_idx);
                this->bytecode.insert(this->bytecode.end(), raw64.raw, raw64.raw + sizeof(uint64_t));
            }
            else if (op == "drptr") {
                uint64_t n = (uint64_t)std::stoull(arg.data());
                raw_bytes raw64 = get_raw_bytes<uint64_t>(n);
                this->bytecode.insert(this->bytecode.end(), raw64.raw, raw64.raw + sizeof(uint64_t));
            }
            else if (Assembling::control_flow.contains(op)) {
                if (!labels.count(arg.data())) {
                    labelsReprocessing.emplace(arg.data(), std::make_pair(lineno + 1, this->bytecode.size()));
                    this->bytecode.resize(this->bytecode.size() + sizeof(uint64_t));
                    continue;
                }
                
                uint64_t addr = labels.at(arg.data());
                raw_bytes raw64 = get_raw_bytes<uint64_t>(addr);

                this->bytecode.insert(this->bytecode.end(), raw64.raw, raw64.raw + sizeof(uint64_t));
            }
        }
        else if (two_operand_ops.count(op)) {
            if (op == "natcall") {
                std::string_view operands = line.substr(ws_pos + 1);
                size_t ws2_pos = operands.find(',');
                if (ws2_pos == std::string::npos) report_err("missing second operand on natcall", lineno + 1);

                std::string lib = std::string(operands.substr(0, ws2_pos));
                std::string sym = std::string(operands.substr(ws2_pos + 1));

                const auto symbol = std::make_pair(lib, sym);

                if (natcall_symbol_table.contains(symbol)) {
                    uint64_t entry_n = natcall_symbol_table.indexof(symbol);
                    raw_bytes raw64 = get_raw_bytes<uint64_t>(entry_n);
                    this->bytecode.insert(this->bytecode.end(), raw64.raw, raw64.raw + sizeof(uint64_t));
                }
                else {
                    uint64_t entry_n = natcall_symbol_table.size();
                    natcall_symbol_table.insert(symbol);
                    raw_bytes raw64 = get_raw_bytes<uint64_t>(entry_n);
                    this->bytecode.insert(this->bytecode.end(), raw64.raw, raw64.raw + sizeof(uint64_t));
                }
            }
        }
    }

    for (const auto& label_pair : labelsReprocessing) {
        if (!labels.count(label_pair.first)) report_err(fmt::format("unknown label: '{}'", label_pair.first), label_pair.second.first);

        uint64_t addr = labels.at(label_pair.first);
        raw_bytes raw_addr = get_raw_bytes<uint64_t>(addr);
        std::copy(raw_addr.raw, raw_addr.raw + sizeof(uint64_t), &this->bytecode[label_pair.second.second]);
    }

    header.bytecode_size = this->bytecode.size();
    raw_bytes raw_size = get_raw_bytes<bytecode_header>(header);
    std::vector<uint8_t> raw_header(raw_size.raw, raw_size.raw + sizeof(bytecode_header));

    std::vector<uint8_t> raw_symbol_table;
    for (size_t i = 0; i < natcall_symbol_table.size(); ++i) {
        const auto& symbol = natcall_symbol_table[i];
        raw_bytes lib_length = get_raw_bytes<uint64_t>(symbol.first.size());
        raw_bytes sym_length = get_raw_bytes<uint64_t>(symbol.second.size());

        raw_symbol_table.insert(raw_symbol_table.end(), lib_length.raw, lib_length.raw + sizeof(uint64_t));
        raw_symbol_table.insert(raw_symbol_table.end(), (uint8_t*)symbol.first.data(), (uint8_t*)symbol.first.data() + lib_length.v);
        raw_symbol_table.insert(raw_symbol_table.end(), sym_length.raw, sym_length.raw + sizeof(uint64_t));
        raw_symbol_table.insert(raw_symbol_table.end(), (uint8_t*)symbol.second.data(), (uint8_t*)symbol.second.data() + sym_length.v);
    }

    this->bytecode.insert(this->bytecode.begin(), raw_header.cbegin(), raw_header.cend());
    this->bytecode.insert(this->bytecode.end(), raw_symbol_table.cbegin(), raw_symbol_table.cend());

    (*(bytecode_header*)this->bytecode.data()).data_section_offset = this->bytecode.size();
    this->bytecode.insert(this->bytecode.end(), data_section.cbegin(), data_section.cend());

    return this->bytecode;
}