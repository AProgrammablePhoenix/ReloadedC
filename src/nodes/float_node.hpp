#pragma once

#include "exp_node.hpp"

class FloatNode: public ExpNode {
public:
    FloatNode(int line, float value);
    void accept(class Visitor& v);
    float getValue();
    bool isConst();
private:
    float value;
};