#include <memory>
#include <vector>

#include "func_call_node.hpp"
#include "visitor.hpp"

// User defined functions
FunctionCall::FunctionCall(int line, std::string func_name, std::vector<std::shared_ptr<ExpNode>>& parameters, std::string ret_type) :
        ExpNode(line, "op", ret_type), func_name(func_name) {
    this->parameters = std::move(parameters);
}

const std::string& FunctionCall::getName() const {
    return this->func_name;
}
const std::vector<std::shared_ptr<ExpNode>>& FunctionCall::getParameters() const {
    return this->parameters;
}
bool FunctionCall::isConst() {
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
        std::string nfunc_name,
        std::string lib,
        std::vector<std::shared_ptr<ExpNode>>& parameters,
        std::string ret_type) : ExpNode(line, "op", ret_type), nfunc_name(nfunc_name), lib(lib) {
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
bool NativeFunctionCall::isConst() {
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