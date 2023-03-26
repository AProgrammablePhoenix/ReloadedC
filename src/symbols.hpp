#pragma once

#include "nodes/statement_node.hpp"

#include <string>
#include <unordered_map>
#include <vector>

typedef std::vector<std::pair<std::string, std::string>> params_def_list;

class funcsym {
public:
    funcsym(const std::string& ret_type, params_def_list parameters_list, std::vector<StatementNode> inner_statements);
    void addVarSym(std::string _vname, const std::string& _vtype);
    
    const std::string& getRetType() const;
    const params_def_list& getParamsList() const;
    std::vector<StatementNode>& getStatements();
    const std::unordered_map<std::string, std::string>& getVarTable() const;

    void delete_mem();
private:
    std::string ret_type;
    params_def_list parameters_list;
    std::unordered_map<std::string, std::string> vartypes_table;
    std::vector<StatementNode> inner_statements;
};

class funcproto {
public:
    funcproto(const std::string& ret_type, params_def_list parameters_list);
    funcproto(const std::string& ret_type, params_def_list parameters_list, bool isres);

    void setAsResolved();
    bool isResolved() const;
    
    const std::string& getRetType() const;
    const params_def_list& getParamsList() const;
private:
    bool resolved = false;

    std::string ret_type;
    params_def_list parameters_list;
};