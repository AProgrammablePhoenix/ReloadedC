#include <string>

#include "program_node.hpp"
#include "visitor.hpp"

#include "../symbols.hpp"

ProgramNode::ProgramNode(int line, const std::string& translation_unit_name) : Node(line), tu_name(translation_unit_name) {}

void ProgramNode::addFunction(std::string _fname, funcsym _fsymbol) {
    this->functions_table.insert(std::make_pair(_fname, _fsymbol));
}
std::unordered_map<std::string, funcsym>& ProgramNode::getFunctions() {
    return this->functions_table;
}

const std::string& ProgramNode::getTUName() {
    return this->tu_name;
}

void ProgramNode::accept(Visitor& v) {
    v.visit(this);
}
void ProgramNode::delete_mem() {
    for (auto& e : this->functions_table) {
        e.second.delete_mem();
    }
}