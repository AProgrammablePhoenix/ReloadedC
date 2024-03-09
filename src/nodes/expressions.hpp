#pragma once

#include <any>
#include <memory>
#include <string>
#include <vector>

#include "node.hpp"
#include "../internal_types.hpp"

class ExpNode: public Node {
public:
    ExpNode(int line, const std::string& exp_type, const _typeinfo_t& ret_type);
    const std::string& getExpType();
    const _typeinfo_t& getRetType();
    virtual constexpr bool isConst() const = 0;
private:
    std::string exp_type;
    _typeinfo_t ret_type;
};

class ConversionNode: public ExpNode {
public:
    ConversionNode(int line, std::shared_ptr<ExpNode> exp_in, const _typeinfo_t& ret_type);
    ExpNode* getExp();
    constexpr bool isConst() const;
    void accept(class Visitor& v);

    void delete_mem();
private:
    std::shared_ptr<ExpNode> exp_in;
};

class PointerAdditionNode : public ExpNode {
public:
    PointerAdditionNode(int line, std::shared_ptr<ExpNode> ptr, std::shared_ptr<ExpNode> offset);
    constexpr bool isConst() const;
    void accept(class Visitor& v);
    ExpNode* getPtr();
    ExpNode* getOffset();

    void delete_mem();
private:
    std::shared_ptr<ExpNode> ptr;
    std::shared_ptr<ExpNode> offset;
};

class PointerSubtractionNode : public ExpNode {
public:
    PointerSubtractionNode(int line, std::shared_ptr<ExpNode> ptr_l, std::shared_ptr<ExpNode> ptr_r);
    constexpr bool isConst() const;
    void accept(class Visitor& v);
    ExpNode* getPtrL();
    ExpNode* getPtrR();

    void delete_mem();
private:
    std::shared_ptr<ExpNode> ptr_l;
    std::shared_ptr<ExpNode> ptr_r;
};

class MathNode: public ExpNode {
public:
    MathNode(int line, std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode> right, char op, const _typeinfo_t& ret_type);
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
    IdentifierNode(int line, const std::string& name, const _typeinfo_t& ret_type);
    void accept(class Visitor& v);
    const std::string& getName();
    constexpr bool isConst() const;
private:
    std::string name;
};

class DereferenceNode: public ExpNode {
public:
    DereferenceNode(int line, std::shared_ptr<ExpNode> exp, const _typeinfo_t& ret_type);
    ExpNode* getExp();
    constexpr bool isConst() const;
    void accept(class Visitor& v);

    void delete_mem();
private:
    std::shared_ptr<ExpNode> exp;
};

class AddressofNode: public ExpNode {
public:
    AddressofNode(int line, std::shared_ptr<IdentifierNode> exp, const _typeinfo_t& ret_type);
    ExpNode* getExp();
    constexpr bool isConst() const;
    void accept(class Visitor& v);

    void delete_mem();
private:
    std::shared_ptr<ExpNode> exp;
};

class FunctionCall : public ExpNode {
public:
    FunctionCall(int line, const std::string& func_name, std::vector<std::shared_ptr<ExpNode>>& parameters, const _typeinfo_t& ret_type);
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
    NativeFunctionCall(int line, const std::string& nfunc_name, const std::string& lib, std::vector<std::shared_ptr<ExpNode>>& parameters, const _typeinfo_t& ret_type);
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

class AssignmentDestData {
public:
    enum class _type {
        LEGACY,
        DEREFERENCE
    };

    AssignmentDestData(const std::string& out_var);
    AssignmentDestData(std::shared_ptr<ExpNode> out_exp);

    _type getType() const;
    std::any getDestData() const;

    void delete_mem();
private:
    _type underlying_type;
    std::string out_var;
    std::shared_ptr<ExpNode> out_exp;
};

class StatementNode: public Node {
public:
    StatementNode(StatementNode&& _stmt);
    StatementNode(const StatementNode& _stmt);
    StatementNode(int line, std::shared_ptr<ExpNode> exp, const AssignmentDestData& dest_data);
    ExpNode* getExp();
    const AssignmentDestData& getDestData();
    void accept(class Visitor& v);

    void delete_mem();
private:
    std::shared_ptr<ExpNode> exp;
    AssignmentDestData dest_data;
};
