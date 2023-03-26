#pragma once

#include <string>

#include "node.hpp"
#include "exp_node.hpp"

class IdentifierNode: public ExpNode {
public:
    IdentifierNode(int line, std::string name, std::string ret_type);
    void accept(class Visitor& v);
    std::string getName();
    bool isConst();
private:
    std::string name;
};
