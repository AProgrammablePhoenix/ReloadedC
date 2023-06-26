#pragma once

#include <memory>
#include <string>
#include <vector>

#include "node.hpp"

class ExpNode: public Node {
public:
    ExpNode(int line, const std::string& exp_type, const std::string& ret_type);
    const std::string& getExpType();
    const std::string& getRetType();
    virtual constexpr bool isConst() const = 0;
private:
    std::string exp_type, ret_type;
};

class ConversionNode: public ExpNode {
public:
    ConversionNode(int line, std::shared_ptr<ExpNode> exp_in, const std::string& ret_type);
    ExpNode* getExp();
    constexpr bool isConst() const;
    void accept(class Visitor& v);

    void delete_mem();
private:
    std::shared_ptr<ExpNode> exp_in;
};

class MathNode: public ExpNode {
public:
    MathNode(int line, std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode> right, char op, const std::string& ret_type);
    ExpNode* getLeft();
    ExpNode* getRight();
    char getOp();
    constexpr bool isConst() const;
    void accept(class Visitor& v);

    void delete_mem();
private:
    std::shared_ptr<ExpNode> left, right;
    char op;
};

class IdentifierNode: public ExpNode {
public:
    IdentifierNode(int line, const std::string& name, const std::string& ret_type);
    void accept(class Visitor& v);
    const std::string& getName();
    constexpr bool isConst() const;
private:
    std::string name;
};

class FunctionCall : public ExpNode {
public:
    FunctionCall(int line, const std::string& func_name, std::vector<std::shared_ptr<ExpNode>>& parameters, const std::string& ret_type);
    const std::string& getName() const;
    const std::vector<std::shared_ptr<ExpNode>>& getParameters() const;
    constexpr bool isConst() const;

    void accept(class Visitor& v);
    void delete_mem();
private:
    std::string func_name;
    std::vector<std::shared_ptr<ExpNode>> parameters;
};

class NativeFunctionCall : public ExpNode {
public:
    NativeFunctionCall(int line, const std::string& nfunc_name, const std::string& lib, std::vector<std::shared_ptr<ExpNode>>& parameters, const std::string& ret_type);
    const std::string& getName() const;
    const std::string& getLib() const;
    const std::vector<std::shared_ptr<ExpNode>>& getParameters() const;
    constexpr bool isConst() const;

    void accept(class Visitor& v);
    void delete_mem();
private:
    std::string nfunc_name, lib;
    std::vector<std::shared_ptr<ExpNode>> parameters;
};

class StatementNode: public Node {
public:
    StatementNode(StatementNode&& _stmt);
    StatementNode(const StatementNode& _stmt);
    StatementNode(int line, std::shared_ptr<ExpNode> exp, const std::string& out_var);
    ExpNode* getExp();
    const std::string& getOutVar();
    void accept(class Visitor& v);

    void delete_mem();
private:
    std::shared_ptr<ExpNode> exp;
    std::string out_var;
};