#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "statement_node.hpp"
#include "../symbols.hpp"

class ProgramNode: public Node {
public:
    ProgramNode(int line, const std::string& translation_unit_name);

    void addFunction(std::string _fname, funcsym _fsymbol);
    std::unordered_map<std::string, funcsym>& getFunctions();

    const std::string& getTUName();

    void accept(Visitor& v);
    void delete_mem();
private:
    std::unordered_map<std::string, funcsym> functions_table;
    std::string tu_name;
};