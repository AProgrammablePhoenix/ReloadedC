#include <string>
#include <unordered_map>
#include <vector>

#include "symbols.hpp"

funcsym::funcsym(const std::string& ret_type, params_def_list parameters_list, std::vector<StatementNode> inner_statements) : 
    ret_type(ret_type), parameters_list(parameters_list), inner_statements(inner_statements) {}
void funcsym::addVarSym(std::string _vname, const std::string& _vtype) {
    this->vartypes_table.insert({_vname, _vtype});
}

const std::string& funcsym::getRetType() const {
    return this->ret_type;
}
const params_def_list& funcsym::getParamsList() const {
    return this->parameters_list;
}
const std::unordered_map<std::string, std::string>& funcsym::getVarTable() const {
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


funcproto::funcproto(const std::string& ret_type, params_def_list parameters_list) : ret_type(ret_type), parameters_list(parameters_list) { };
funcproto::funcproto(const std::string& ret_type, params_def_list parameters_list, bool isres) :
    ret_type(ret_type), parameters_list(parameters_list), resolved(isres) { };

void funcproto::setAsResolved() {
    resolved = true;
}
bool funcproto::isResolved() const {
    return resolved;
}

const std::string& funcproto::getRetType() const {
    return this->ret_type;
}
const params_def_list& funcproto::getParamsList() const {
    return this->parameters_list;
}