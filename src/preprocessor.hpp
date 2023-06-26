#pragma once

#include <string>
#include <vector>

std::string read_file(const std::string& filename);
std::vector<std::string> split_lines(const std::string& s);
std::vector<std::string> preprocess_file(std::vector<std::string> lines);