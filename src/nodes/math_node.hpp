#pragma once

#include <string>
#include <memory>

#include "node.hpp"
#include "exp_node.hpp"

class MathNode: public ExpNode {
public:
    MathNode(int line, std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode> right, char op, std::string ret_type);
    ExpNode* getLeft();
    ExpNode* getRight();
    char getOp();
    bool isConst();
    void accept(class Visitor& v);

    void delete_mem();
private:
    std::shared_ptr<ExpNode> left, right;
    char op;
};