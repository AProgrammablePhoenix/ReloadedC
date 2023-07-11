#include <string>
#include <unordered_map>
#include <vector>

#include "internal_types.hpp"
#include "symbols.hpp"

funcsym::funcsym(const _typeinfo_t& ret_type, const params_def_list& parameters_list, const std::vector<StatementNode>& inner_statements) : 
    ret_type(ret_type), parameters_list(parameters_list), inner_statements(inner_statements) {}
void funcsym::addVarSym(const std::string& _vname, const _typeinfo_t& _vtype) {
    this->vartypes_table.emplace(_vname, _vtype);
}
const _typeinfo_t& funcsym::getRetType() const {
    return this->ret_type;
}
const params_def_list& funcsym::getParamsList() const {
    return this->parameters_list;
}
const std::unordered_map<std::string, _typeinfo_t>& funcsym::getVarTable() const {
    return this->vartypes_table;
}
std::vector<StatementNode>& funcsym::getStatements() {
    return this->inner_statements;
}
void funcsym::delete_mem() {
    for (auto& e : inner_statements) {
        e.delete_mem();
    }
}

funcproto::funcproto(const _typeinfo_t& ret_type, const params_def_list& parameters_list) : ret_type(ret_type), parameters_list(parameters_list) { };
funcproto::funcproto(const _typeinfo_t& ret_type, const params_def_list& parameters_list, bool isres) :
    ret_type(ret_type), parameters_list(parameters_list), resolved(isres) { };
void funcproto::setAsResolved() {
    resolved = true;
}
bool funcproto::isResolved() const {
    return resolved;
}
const _typeinfo_t& funcproto::getRetType() const {
    return this->ret_type;
}
const params_def_list& funcproto::getParamsList() const {
    return this->parameters_list;
}