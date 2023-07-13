#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <unordered_map>
#include <unordered_set>

struct bytecode_header {
    uint64_t bytecode_size = 0;
    uint64_t data_section_offset = 0;
};

class bytecode_gen {
public:
    bytecode_gen(const std::string& filename);
    const std::vector<uint8_t>& generate();
private:
    std::ifstream in_source;
    std::vector<uint8_t> bytecode;
};