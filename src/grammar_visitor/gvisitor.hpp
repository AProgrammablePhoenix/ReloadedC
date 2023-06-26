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
#include "../symbols.hpp"

struct _internal_conversion_t {
    size_t _size_in  = 0;
    size_t _size_out = 0;

    bool _right_converted = 0;
    bool _left_converted = 0;

    bool _is_signed    = false;
    bool _float_to_int = false;
    bool _int_to_float = false;
};

struct _implicit_conversion_t {
    _internal_conversion_t _conv;
    bool _left_to_right = false;
};

class gvisitor {
public:
    std::shared_ptr<ProgramNode> visitProgram(relcgrammarParser::ProgramContext *ctx, const std::string& tu_name);
    void visitGlobal_statement(relcgrammarParser::Global_statementContext *ctx);

    std::shared_ptr<StatementNode> visitStatement(relcgrammarParser::StatementContext* ctx);
    std::pair<std::string, std::shared_ptr<ExpNode>> visitAssignment(relcgrammarParser::AssignmentContext* ctx);
    std::pair<std::string, std::shared_ptr<ExpNode>> visitInitialization(relcgrammarParser::InitializationContext *ctx);

    std::shared_ptr<ExpNode> visitExp(relcgrammarParser::ExpContext *ctx);

    std::vector<StatementNode> visitScope(relcgrammarParser::ScopeContext *ctx);
    std::vector<StatementNode> visitBordered_scope(relcgrammarParser::Bordered_scopeContext *ctx);

    std::shared_ptr<ExpNode> visitNative_call(relcgrammarParser::Native_callContext *ctx);
    std::vector<std::shared_ptr<ExpNode>> visitArguments_list(relcgrammarParser::Arguments_listContext *ctx);

    void visitParameter(relcgrammarParser::ParameterContext *ctx);
    void visitParameters_list(relcgrammarParser::Parameters_listContext *ctx);

    std::tuple<std::string, std::string, funcproto> visitNative_func_prototype(relcgrammarParser::Native_func_prototypeContext *ctx);
    std::pair<std::string, funcproto> visitFunc_prototype(relcgrammarParser::Func_prototypeContext *ctx);
    std::pair<std::string, std::string> visitFunc_declaration(relcgrammarParser::Func_declarationContext *ctx);
    std::vector<StatementNode> visitFunc_scope(relcgrammarParser::Func_scopeContext *ctx);

    std::pair<std::string, funcsym> visitFunc_body(relcgrammarParser::Func_bodyContext *ctx);
private:
    [[noreturn]] inline void report_err(std::string message, size_t line) {
        std::string err = fmt::format("{} (line {}): {}\n",
            fmt::styled("error", fg(fmt::color::red)),
            line,
            message
        );
        throw std::runtime_error(err);
    }
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
    inline const std::string& fetch_var_type(std::string _vname, size_t line) {
        for (const auto& e : function_local_vars) {
            if (e._name == _vname) {
                return e._type;
            }
        }
        for (const auto& e : function_parameters) {
            if (e._name == _vname) {
                return e._type;
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
    inline bool is_implicit_convertible(const std::string& t1, const std::string& t2) {
        static const std::unordered_set<std::string> primitive_types = { "char", "int", "long" /*"float"*/ };

        if ((!primitive_types.contains(t1) || !primitive_types.contains(t2)) && t1 != t2) {
            return false;
        }

        return true;
    }
    inline _internal_conversion_t get_assignment_implicit_conversion(const std::string& _t_in, const std::string& _t_out) {
        static const std::unordered_map<std::string, size_t> types_size = {
            { "char", 1 },
            { "int", 4},
            { "long", 8}
        };

        return _internal_conversion_t {
            ._size_in = types_size.at(_t_in),
            ._size_out = types_size.at(_t_out),
            ._is_signed = true
        };
    }
    inline _implicit_conversion_t get_expression_implicit_conversion(const std::string& _t_left, const std::string& _t_right) {
        static const std::unordered_map<std::string, size_t> types_precedence = {
            { "char", 0 },
            { "int",  1 },
            { "long", 2 },
            { "float", 3},
            { "double", 4}
        };

        if (types_precedence.at(_t_left) > types_precedence.at(_t_right)) {
            return _implicit_conversion_t {
                ._conv = get_assignment_implicit_conversion(_t_right, _t_left),
                ._left_to_right = false
            };
        }

        return _implicit_conversion_t { 
            ._conv = get_assignment_implicit_conversion(_t_left, _t_right),
            ._left_to_right = true
        };
    }

    std::vector<_variable_def_t> function_local_vars;
    params_def_list function_parameters;

    std::unordered_map<std::string, funcproto> prototypes;
    std::unordered_map<std::string, std::pair<std::string, funcproto>> native_prototypes;

    std::shared_ptr<ProgramNode> temp_program;
};