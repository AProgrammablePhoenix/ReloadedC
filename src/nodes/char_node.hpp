#pragma once

#include "exp_node.hpp"

class CharNode: public ExpNode {
public:
    CharNode(int line, char value);
    void accept(class Visitor& v);
    char getValue();
    bool isConst();
private:
    char value;
};