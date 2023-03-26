#pragma once

#include <memory>
#include <vector>

#include "node.hpp"
#include "exp_node.hpp"

class FunctionCall : public ExpNode {
public:
    FunctionCall(int line, std::string func_name, std::vector<std::shared_ptr<ExpNode>>& parameters, std::string ret_type);
    const std::string& getName() const;
    const std::vector<std::shared_ptr<ExpNode>>& getParameters() const;
    bool isConst();

    void accept(class Visitor& v);
    void delete_mem();
private:
    std::string func_name;
    std::vector<std::shared_ptr<ExpNode>> parameters;
};

class NativeFunctionCall : public ExpNode {
public:
    NativeFunctionCall(int line, std::string nfunc_name, std::string lib, std::vector<std::shared_ptr<ExpNode>>& parameters, std::string ret_type);
    const std::string& getName() const;
    const std::string& getLib() const;
    const std::vector<std::shared_ptr<ExpNode>>& getParameters() const;
    bool isConst();

    void accept(class Visitor& v);
    void delete_mem();
private:
    std::string nfunc_name, lib;
    std::vector<std::shared_ptr<ExpNode>> parameters;
};