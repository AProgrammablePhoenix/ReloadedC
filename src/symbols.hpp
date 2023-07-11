#pragma once

#include "nodes/expressions.hpp"
#include "internal_types.hpp"

#include <string>
#include <unordered_map>
#include <vector>

typedef std::vector<_variable_def_t> params_def_list;

class funcsym {
public:
    funcsym(const _typeinfo_t& ret_type, const params_def_list& parameters_list, const std::vector<StatementNode>& inner_statements);
    void addVarSym(const std::string& _vname, const _typeinfo_t& _vtype);
    
    const _typeinfo_t& getRetType() const;
    const params_def_list& getParamsList() const;
    std::vector<StatementNode>& getStatements();
    const std::unordered_map<std::string, _typeinfo_t>& getVarTable() const;

    void delete_mem();
private:
    _typeinfo_t ret_type;
    params_def_list parameters_list;
    std::unordered_map<std::string, _typeinfo_t> vartypes_table;
    std::vector<StatementNode> inner_statements;
};

class funcproto {
public:
    funcproto(const _typeinfo_t& ret_type, const params_def_list& parameters_list);
    funcproto(const _typeinfo_t& ret_type, const params_def_list& parameters_list, bool isres);

    void setAsResolved();
    bool isResolved() const;
    
    const _typeinfo_t& getRetType() const;
    const params_def_list& getParamsList() const;
private:
    bool resolved = false;

    _typeinfo_t ret_type;
    params_def_list parameters_list;
};