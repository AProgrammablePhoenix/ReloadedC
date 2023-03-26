#include "float_node.hpp"
#include "visitor.hpp"

FloatNode::FloatNode(int line, float value) :
    ExpNode(line, "imm_flt", "float"), value(value) {}

float FloatNode::getValue() {
    return this->value;
}
bool FloatNode::isConst() {
    return true;
}

void FloatNode::accept(Visitor& v) {
    v.visit(this);
}