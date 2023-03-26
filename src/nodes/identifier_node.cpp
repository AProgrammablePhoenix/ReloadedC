#include <iostream>
#include <string>

#include "identifier_node.hpp"
#include "visitor.hpp"

IdentifierNode::IdentifierNode(int line, std::string name, std::string ret_type) :
    ExpNode(line, "var", ret_type), name(name) {}

std::string IdentifierNode::getName() {
    return this->name;
}
bool IdentifierNode::isConst() {
    return false;
}

void IdentifierNode::accept(Visitor& v) {
    v.visit(this);
}
