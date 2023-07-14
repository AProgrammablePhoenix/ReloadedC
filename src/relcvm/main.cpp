#include <iostream>
#include <string>

#include <filesystem>
#include <fstream>
#include <vector>

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>

#include "engine/voperations.hpp"

#include "engine/engine.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Not enough arguments were provided\n";
        std::cerr << "usage: relc <filename>\n";
        return 1;
    }

    const std::string fbytecode_name = std::string(argv[1]);
    std::vector<uint8_t> bytecode;

    std::ifstream fbytecode(argv[1], std::ios::binary);
    if (fbytecode) {
        size_t fbytecode_size = std::filesystem::file_size(fbytecode_name);
        bytecode.resize(fbytecode_size);
        fbytecode.read((char*)bytecode.data(), fbytecode_size);
    } else {
        fmt::print("{}: couldn't not open file: '{}'\n",
            fmt::styled("error", fg(fmt::color::red)),
            argv[1]
        );
        return 2;
    }

    engine_execute(bytecode);
}