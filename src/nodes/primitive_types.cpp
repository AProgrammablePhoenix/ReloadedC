#include "primitive_types.hpp"
#include "visitor.hpp"

void IntegerNode::accept(Visitor& v) {
    v.visit(this);
}
void LongNode::accept(Visitor& v) {
    v.visit(this);
}
void FloatNode::accept(Visitor& v) {
    v.visit(this);
}
void CharNode::accept(Visitor& v) {
    v.visit(this);
}