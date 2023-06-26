#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>

#include "cmake_env.hpp"

#include "preprocessor.hpp"

namespace {
    static std::unordered_set<std::string> included_files;
}

std::string read_file(const std::string& filename) {
    std::ifstream hfile(filename);

    if (hfile) {
        std::string content;
        size_t content_len = std::filesystem::file_size(filename);

        content.resize(content_len);
        hfile.read(content.data(), content_len);

        return content;
    } else {
        std::string err = fmt::format("{}: could not not open file: '{}'\n",
            fmt::styled("error", fg(fmt::color::red)),
            filename
        );
        throw std::runtime_error(err);
    }
}

std::vector<std::string> split_lines(const std::string& s) {
    std::vector<std::string> ret;
    
    std::stringstream ss(s);
    for (std::string line; std::getline(ss, line);) {
        ret.emplace_back(line);
    }

    return ret;
}

std::vector<std::string> preprocess_file(std::vector<std::string> lines) {
    // TODO: implement preprocessor
    std::vector<std::string> ret;
    ret.reserve(lines.size());

    for (auto it = lines.begin(); it != lines.end(); ++it) {
        const auto& l = *it;

        if (l.empty()) continue;
        else if (!l.starts_with("#")) {
            std::string line;

            for (char c : l) {
                if (c == '\t' || c == '\r' || c== '\f') continue;
                line += c;
            }
            while (!line.empty() && line[0] == ' ') {
                line = line.substr(1);
            }
            if (line.empty() || line.starts_with("//")) continue;

            ret.push_back(line);
        }
        else {
            if (l.starts_with("#include ")) {
                size_t i = 9;
                while (l[i] == ' ') ++i;

                std::string header = l.substr(i);
                if (header.front() == '<' && header.back() == '>') {
                    std::string header_name = header.substr(1, header.size() - 2);
                    std::string full_header_path = std::filesystem::path(VLIBC_HEADERS_LOC) / header_name;

                    if (included_files.contains(full_header_path)) {
                        continue;
                    }

                    included_files.insert(full_header_path);

                    auto header_lines = split_lines(read_file(full_header_path));
                    it = lines.insert(it + 1, header_lines.cbegin(), header_lines.cend());
                    --it;
                }
                else if (header.front() == '"' && header.back() == '"') {
                    std::string header_name = header.substr(1, header.size() - 2);
                    std::string full_header_path = std::filesystem::canonical(header_name);

                    if (included_files.contains(full_header_path)) {
                        continue;
                    }

                    included_files.insert(full_header_path);

                    auto header_lines = split_lines(read_file(full_header_path));
                    it = lines.insert(it + 1, header_lines.cbegin(), header_lines.cend());
                    --it;
                }
                else {
                    std::string err = fmt::format("{}: ill-formed include statement: '{}'\n",
                        fmt::styled("error", fg(fmt::color::red)),
                        l
                    );
                    throw std::runtime_error(err);
                }
            }
        }
    }

    return ret;
}