#include <string>

#include "node.hpp"
#include "exp_node.hpp"

ExpNode::ExpNode(int line, std::string exp_type, std::string ret_type) :
    Node(line), exp_type(exp_type), ret_type(ret_type) {}
std::string ExpNode::getExpType() {
    return this->exp_type;
}
std::string ExpNode::getRetType() {
    return this->ret_type;
}