#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <unordered_map>
#include <unordered_set>

class bytecode_gen {
public:
    bytecode_gen(const std::string& filename);
    const std::vector<uint8_t>& generate();
private:
    std::ifstream in_source;
    std::vector<uint8_t> bytecode;
};