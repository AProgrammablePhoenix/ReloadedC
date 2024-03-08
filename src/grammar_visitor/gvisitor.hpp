#pragma once

#include <iostream>
#include <string>

#include <memory>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <fmt/core.h>
#include <fmt/color.h>

#include "antlr4-runtime.h"
#include "../grammar/relcgrammarParser.h"

#include "../nodes/NodesLib.hpp"
#include "../internal_types.hpp"
#include "../symbols.hpp"

bool is_implicit_convertible(const _typeinfo_t& t_in, const _typeinfo_t& t_out, bool in_out = true);
bool is_valid_arithmetic(const _typeinfo_t& t1, const _typeinfo_t& t2, char op);
bool is_pointer_addition(const _typeinfo_t& t1, const _typeinfo_t& t2, char op);
_typeinfo_t get_ptr_serialized_type(bool constness);
_internal_conversion_t get_assignment_implicit_conversion(const _typeinfo_t& _t_in, const _typeinfo_t& _t_out);
_implicit_conversion_t get_expression_implicit_conversion(const _typeinfo_t& _t_left, const _typeinfo_t& _t_right);

namespace {
    [[noreturn]] inline void report_err(std::string message, size_t line) {
        std::string err = fmt::format("{} (line {}): {}\n",
            fmt::styled("error", fg(fmt::color::red)),
            line,
            message
        );
        throw std::runtime_error(err);
    }
}

class gvisitor {
public:
    std::shared_ptr<ProgramNode> visitProgram(relcgrammarParser::ProgramContext *ctx, const std::string& tu_name);
    void visitGlobal_statement(relcgrammarParser::Global_statementContext *ctx);

    std::shared_ptr<StatementNode> visitStatement(relcgrammarParser::StatementContext* ctx);
    std::pair<std::string, std::shared_ptr<ExpNode>> visitAssignment(relcgrammarParser::AssignmentContext* ctx);
    std::pair<std::string, std::shared_ptr<ExpNode>> visitInitialization(relcgrammarParser::InitializationContext *ctx);

    _typeinfo_t visitType(relcgrammarParser::TypeContext* ctx);
    std::shared_ptr<ExpNode> visitExp(relcgrammarParser::ExpContext *ctx);

    std::vector<StatementNode> visitScope(relcgrammarParser::ScopeContext *ctx);
    std::vector<StatementNode> visitBordered_scope(relcgrammarParser::Bordered_scopeContext *ctx);

    std::shared_ptr<ExpNode> visitNative_call(relcgrammarParser::Native_callContext *ctx);
    std::vector<std::shared_ptr<ExpNode>> visitArguments_list(relcgrammarParser::Arguments_listContext *ctx);

    void visitParameter(relcgrammarParser::ParameterContext *ctx);
    void visitParameters_list(relcgrammarParser::Parameters_listContext *ctx);

    std::tuple<std::string, std::string, funcproto> visitNative_func_prototype(relcgrammarParser::Native_func_prototypeContext *ctx);
    std::pair<std::string, funcproto> visitFunc_prototype(relcgrammarParser::Func_prototypeContext *ctx);
    std::pair<std::string, _typeinfo_t> visitFunc_declaration(relcgrammarParser::Func_declarationContext *ctx);
    std::vector<StatementNode> visitFunc_scope(relcgrammarParser::Func_scopeContext *ctx);

    std::pair<std::string, funcsym> visitFunc_body(relcgrammarParser::Func_bodyContext *ctx);
private:
    inline bool is_var_defined(const std::string _s) {
        for (const auto& _vdef : function_local_vars) {
            if (_vdef._name == _s) {
                return true;
            }
        }
        for (const auto& _vdef : function_parameters) {
            if (_vdef._name == _s) {
                return true;
            }
        }

        return false;
    }
    inline const _typeinfo_t& fetch_var_type(std::string _vname, size_t line) {
        for (const auto& e : function_local_vars) {
            if (e._name == _vname) {
                return e._tinfo;
            }
        }
        for (const auto& e : function_parameters) {
            if (e._name == _vname) {
                return e._tinfo;
            }
        }
        report_err("undefined variable: " + _vname, line);
    }
    inline const _variable_def_t& fetch_var_data(std::string _vname, size_t line) {
        for (const auto& e : function_local_vars) {
            if (e._name == _vname) {
                return e;
            }
        }
        for (const auto& e : function_parameters) {
            if (e._name == _vname) {
                return e;
            }
        }
        report_err("undefined variable: " + _vname, line);
    }

    std::vector<_variable_def_t> function_local_vars;
    params_def_list function_parameters;

    std::unordered_map<std::string, funcproto> prototypes;
    std::unordered_map<std::string, std::pair<std::string, funcproto>> native_prototypes;

    std::shared_ptr<ProgramNode> temp_program;
};