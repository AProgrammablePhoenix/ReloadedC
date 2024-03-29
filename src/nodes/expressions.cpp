#include <any>
#include <string>

#include "node.hpp"
#include "expressions.hpp"
#include "visitor.hpp"
#include "../internal_types.hpp"

ExpNode::ExpNode(int line, const std::string& exp_type, const _typeinfo_t& ret_type) :
    Node(line), exp_type(exp_type), ret_type(ret_type) {}
const std::string& ExpNode::getExpType() {
    return this->exp_type;
}
const _typeinfo_t& ExpNode::getRetType() {
    return this->ret_type;
}

ConversionNode::ConversionNode(int line, std::shared_ptr<ExpNode> exp_in, const _typeinfo_t& ret_type) : ExpNode(line, "op", ret_type) {
    this->exp_in = std::move(exp_in);
}
ExpNode* ConversionNode::getExp() {
    return this->exp_in.get();
}
constexpr bool ConversionNode::isConst() const {
    //return this->exp_in->isConst();
    return false;
}
void ConversionNode::accept(Visitor& v) {
    v.visit(this);
}
void ConversionNode::delete_mem() {
    this->exp_in->delete_mem();
}

PointerAdditionNode::PointerAdditionNode(int line, std::shared_ptr<ExpNode> ptr, std::shared_ptr<ExpNode> offset) : ExpNode(line, "op", ptr->getRetType()) {
    this->ptr = std::move(ptr);
    this->offset = std::move(offset);
}
constexpr bool PointerAdditionNode::isConst() const {
    return false;
}
void PointerAdditionNode::accept(Visitor& v) {
    v.visit(this);
}
ExpNode* PointerAdditionNode::getPtr() {
    return this->ptr.get();
}
ExpNode* PointerAdditionNode::getOffset() {
    return this->offset.get();
}
void PointerAdditionNode::delete_mem() {
    this->ptr->delete_mem();
    this->offset->delete_mem();
}

PointerSubtractionNode::PointerSubtractionNode(int line, std::shared_ptr<ExpNode> ptr_l, std::shared_ptr<ExpNode> ptr_r) :
        ExpNode(line, "op", _serlialized_ptr_t(false)) {
    this->ptr_l = std::move(ptr_l);
    this->ptr_r = std::move(ptr_r);
}
constexpr bool PointerSubtractionNode::isConst() const {
    return false;
}
void PointerSubtractionNode::accept(Visitor& v) {
    v.visit(this);
}
ExpNode* PointerSubtractionNode::getPtrL() {
    return this->ptr_l.get();
}
ExpNode* PointerSubtractionNode::getPtrR() {
    return this->ptr_r.get();
}
void PointerSubtractionNode::delete_mem() {
    this->ptr_l->delete_mem();
    this->ptr_r->delete_mem();
}

MathNode::MathNode(int line, std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode>right, char op, const _typeinfo_t& ret_type) :
        ExpNode(line, "op", ret_type), op(op) {
    this->left = std::move(left);
    this->right = std::move(right);
}
ExpNode* MathNode::getLeft() {
    return this->left.get();
}
ExpNode* MathNode::getRight() {
    return this->right.get();
}
char MathNode::getOp() {
    return this->op;
}
constexpr bool MathNode::isConst() const {
    //return this->left->isConst() && this->right->isConst();
    return false;
}
void MathNode::accept(Visitor& v) {
    v.visit(this);
}
void MathNode::delete_mem() {
    this->left->delete_mem();
    this->right->delete_mem();
}

IdentifierNode::IdentifierNode(int line, const std::string& name, const _typeinfo_t& ret_type) :
    ExpNode(line, "var", ret_type), name(name) {}

const std::string& IdentifierNode::getName() {
    return this->name;
}
constexpr bool IdentifierNode::isConst() const {
    return false;
}
void IdentifierNode::accept(Visitor& v) {
    v.visit(this);
}

DereferenceNode::DereferenceNode(int line, std::shared_ptr<ExpNode> exp, const _typeinfo_t& ret_type) :
        ExpNode(line, "op", ret_type) {
    this->exp = std::move(exp);
}
ExpNode* DereferenceNode::getExp() {
    return this->exp.get();
}
constexpr bool DereferenceNode::isConst() const {
    return false;
}
void DereferenceNode::accept(Visitor& v) {
    v.visit(this);
}
void DereferenceNode::delete_mem() {
    this->exp->delete_mem();
}

AddressofNode::AddressofNode(int line, std::shared_ptr<IdentifierNode> exp, const _typeinfo_t& ret_type) :
        ExpNode(line, "op", ret_type) {
    this->exp = std::move(exp);
}
ExpNode* AddressofNode::getExp() {
    return this->exp.get();
}
constexpr bool AddressofNode::isConst() const {
    return false;
}
void AddressofNode::accept(Visitor& v) {
    v.visit(this);
}
void AddressofNode::delete_mem() {
    this->exp->delete_mem();
}

// User defined functions
FunctionCall::FunctionCall(int line, const std::string& func_name, std::vector<std::shared_ptr<ExpNode>>& parameters, const _typeinfo_t& ret_type) :
        ExpNode(line, "op", ret_type), func_name(func_name) {
    this->parameters = std::move(parameters);
}
const std::string& FunctionCall::getName() const {
    return this->func_name;
}
const std::vector<std::shared_ptr<ExpNode>>& FunctionCall::getParameters() const {
    return this->parameters;
}
constexpr bool FunctionCall::isConst() const {
    return false;
}

void FunctionCall::accept(Visitor& v) {
    v.visit(this);
}

void FunctionCall::delete_mem() {
    for (size_t i = 0; i < parameters.size(); ++i) {
        parameters[i]->delete_mem();
    }
}

// Standard language functions
NativeFunctionCall::NativeFunctionCall(int line,
        const std::string& nfunc_name,
        const std::string& lib,
        std::vector<std::shared_ptr<ExpNode>>& parameters,
        const struct _typeinfo_t& ret_type) : ExpNode(line, "op", ret_type), nfunc_name(nfunc_name), lib(lib) {
    this->parameters = std::move(parameters);
}
const std::string& NativeFunctionCall::getName() const {
    return this->nfunc_name;
}
const std::string& NativeFunctionCall::getLib() const {
    return this->lib;
}
const std::vector<std::shared_ptr<ExpNode>>& NativeFunctionCall::getParameters() const {
    return this->parameters;
}
constexpr bool NativeFunctionCall::isConst() const {
    return false;
}

void NativeFunctionCall::accept(Visitor& v) {
    v.visit(this);
}

void NativeFunctionCall::delete_mem() {
    for (size_t i = 0; i < parameters.size(); ++i) {
        parameters[i]->delete_mem();
    }
}

AssignmentDestData::AssignmentDestData(const std::string& out_var) {
    this->out_var = out_var;
    this->underlying_type = _type::LEGACY;
}
AssignmentDestData::AssignmentDestData(std::shared_ptr<ExpNode> out_exp) {
    this->out_exp = std::move(out_exp);
    this->underlying_type = _type::DEREFERENCE;
}
AssignmentDestData::_type AssignmentDestData::getType() const {
    return this->underlying_type;
}
std::any AssignmentDestData::getDestData() const {
    if (this->underlying_type == _type::LEGACY) {
        return std::any(this->out_var);
    }
    else {
        return std::any(std::move(this->out_exp));
    }
}
void AssignmentDestData::delete_mem() {
    if (this->underlying_type == _type::DEREFERENCE) {
        this->out_exp->delete_mem();
    }
}

StatementNode::StatementNode(StatementNode&& _stmt) : Node(_stmt.getline()), dest_data(_stmt.dest_data) {
    exp = std::move(_stmt.exp);
}
StatementNode::StatementNode(const StatementNode& _stmt) : Node(_stmt.getline()), dest_data(_stmt.dest_data) {
    exp = _stmt.exp;
}
StatementNode::StatementNode(int line, std::shared_ptr<ExpNode> exp, const AssignmentDestData& dest_data) :
        Node(line), dest_data(dest_data) {
    this->exp = std::move(exp);
}
ExpNode* StatementNode::getExp() {
    return this->exp.get();
}
const AssignmentDestData& StatementNode::getDestData() {
    return this->dest_data;
}
void StatementNode::accept(Visitor& v) {
    v.visit(this);
}
void StatementNode::delete_mem() {
    this->dest_data.delete_mem();
    this->exp->delete_mem();
}
