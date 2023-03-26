#include <string>
#include <memory>

#include "math_node.hpp"
#include "visitor.hpp"

MathNode::MathNode(int line, std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode>right, char op, std::string ret_type) :
        ExpNode(line, "op", ret_type), op(op) {
    this->left = std::move(left);
    this->right = std::move(right);
}

ExpNode* MathNode::getLeft() {
    return this->left.get();
}
ExpNode* MathNode::getRight() {
    return this->right.get();
}
char MathNode::getOp() {
    return this->op;
}
bool MathNode::isConst() {
    return false;
}

void MathNode::accept(Visitor& v) {
    v.visit(this);
}

void MathNode::delete_mem() {
    this->left->delete_mem();
    this->right->delete_mem();
}