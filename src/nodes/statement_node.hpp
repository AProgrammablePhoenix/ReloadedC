#pragma once

#include <string>
#include <memory>

#include "node.hpp"
#include "exp_node.hpp"

class StatementNode: public Node {
public:
    StatementNode(StatementNode&& _stmt);
    StatementNode(const StatementNode& _stmt);
    StatementNode(int line, std::shared_ptr<ExpNode> exp, std::string out_var);
    ExpNode* getExp();
    const std::string& getOutVar();
    void accept(class Visitor& v);

    void delete_mem();
private:
    std::shared_ptr<ExpNode> exp;
    std::string out_var;
};