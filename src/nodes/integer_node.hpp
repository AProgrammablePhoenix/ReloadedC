#pragma once

#include "node.hpp"
#include "exp_node.hpp"

class IntegerNode: public ExpNode {
public:
    IntegerNode(int line, int value);
    void accept(class Visitor& v);
    int getValue();
    bool isConst();
private:
    int value;
};