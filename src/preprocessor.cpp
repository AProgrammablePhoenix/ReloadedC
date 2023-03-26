#include <iostream>
#include <string>
#include <vector>

#include "preprocessor.hpp"

std::vector<std::string> preprocess_file(const std::vector<std::string>& lines) {
    // TODO: implement preprocessor
    std::vector<std::string> ret;
    ret.reserve(lines.size());

    for (const auto& l : lines) {
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
    }

    return ret;
}