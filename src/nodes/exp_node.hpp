#pragma once

#include <string>

#include "node.hpp"

class ExpNode: public Node {
public:
    ExpNode(int line, std::string exp_type, std::string ret_type);
    std::string getExpType();
    std::string getRetType();
    virtual bool isConst() = 0;
private:
    std::string exp_type, ret_type;
};