#include "integer_node.hpp"
#include "visitor.hpp"

IntegerNode::IntegerNode(int line, int value) :
    ExpNode(line, "imm_num", "int"), value(value) {}

int IntegerNode::getValue() {
    return this->value;
}
bool IntegerNode::isConst() {
    return true;
}

void IntegerNode::accept(Visitor& v) {
    v.visit(this);
}