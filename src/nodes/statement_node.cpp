#include <string>
#include <memory>

#include "statement_node.hpp"
#include "visitor.hpp"

StatementNode::StatementNode(StatementNode&& _stmt) : Node(_stmt.getline()) {
    exp = std::move(_stmt.exp);
    out_var = _stmt.out_var;
}
StatementNode::StatementNode(const StatementNode& _stmt) : Node(_stmt.getline()) {
    exp = _stmt.exp;
    out_var = _stmt.out_var;
}

StatementNode::StatementNode(int line, std::shared_ptr<ExpNode> exp, std::string out_var) :
        Node(line), out_var(out_var) {
    this->exp = std::move(exp);
}

ExpNode* StatementNode::getExp() {
    return this->exp.get();
}
const std::string& StatementNode::getOutVar() {
    return this->out_var;
}

void StatementNode::accept(Visitor& v) {
    v.visit(this);
}

void StatementNode::delete_mem() {
    this->exp->delete_mem();
}