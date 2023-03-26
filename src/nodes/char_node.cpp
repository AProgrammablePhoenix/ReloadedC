#include "char_node.hpp"
#include "visitor.hpp"

CharNode::CharNode(int line, char value) :
    ExpNode(line, "imm_chr", "char"), value(value) {}

char CharNode::getValue() {
    return this->value;
}
bool CharNode::isConst() {
    return true;
}
void CharNode::accept(Visitor& v) {
    v.visit(this);
}