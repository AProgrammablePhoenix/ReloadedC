#include <iostream>
#include <string>

#include <memory>
#include <vector>

#include "antlr4-runtime.h"
#include "../grammar/relcgrammarParser.h"

#include "../nodes/NodesLib.hpp"

#include "gvisitor.hpp"

std::shared_ptr<ExpNode> gvisitor::visitExp(relcgrammarParser::ExpContext *ctx) {
    if (ctx->native_call()) return visitNative_call(ctx->native_call());
    else if (ctx->ID()) {
        std::string sym_name = ctx->ID()->getText();
        size_t sym_line = ctx->ID()->getSymbol()->getLine();

        if (ctx->LPAREN()) {
            if (!ctx->arguments_list()) {
                if (is_var_defined(sym_name)) report_err("can't call non-callable object: " + sym_name, sym_line);
                else if (!temp_program->getFunctions().count(sym_name)) report_err("undefined callable object: " + sym_name, sym_line);
                else if (!temp_program->getFunctions().at(sym_name).getParamsList().empty()) {
                    report_err("too few arguments were provided when calling function: " + sym_name, sym_line);
                }
                
                std::vector<std::shared_ptr<ExpNode>> empty_arg_list;

                return std::make_shared<FunctionCall>(
                    sym_line,
                    sym_name,
                    empty_arg_list,
                    temp_program->getFunctions().at(sym_name).getRetType()
                );
            }
            else {
                auto arg_list = visitArguments_list(ctx->arguments_list());

                if (is_var_defined(sym_name)) report_err("can't call non-callable object: " + sym_name, sym_line);
                else if (!temp_program->getFunctions().count(sym_name)) report_err("undefined callable object: " + sym_name, sym_line);
                else if (temp_program->getFunctions().at(sym_name).getParamsList().size() != arg_list.size()) {
                    report_err("wrong number of arguments were provided when calling function: " + sym_name, sym_line);
                }

                for (size_t i = 0; i < arg_list.size(); ++i) {
                    const _typeinfo_t& _arg_t = arg_list[i]->getRetType();
                    const _typeinfo_t& _param_t = temp_program->getFunctions().at(sym_name).getParamsList()[i]._tinfo;

                    if (!is_implicit_convertible(_arg_t, _param_t)) {
                        report_err(
                            "wrong type of argument was provided (arg " + std::to_string(i + 1) + ") when calling function: " + sym_name,
                            sym_line
                        );
                    }
                    else if (_arg_t._type != _param_t._type) {
                        arg_list[i] = std::make_shared<ConversionNode>(arg_list[i]->getline(), arg_list[i], _param_t);
                    }
                }

                return std::make_shared<FunctionCall>(
                    sym_line,
                    sym_name,
                    arg_list,
                    temp_program->getFunctions().at(sym_name).getRetType()
                );
            }
        }
        else {
            if (!is_var_defined(sym_name)) report_err("undefined identifier: " + sym_name, sym_line);
            const _typeinfo_t& s_type = fetch_var_type(sym_name, sym_line);

            return std::make_shared<IdentifierNode>(sym_line, sym_name, s_type);
        }
    }
    else if (ctx->LONG_LITERAL()) {
        int64_t n = std::stoull(ctx->LONG_LITERAL()->getText());
        return std::make_shared<LongNode>(ctx->LONG_LITERAL()->getSymbol()->getLine(), n);
    }
    else if (ctx->INT_LITERAL()) {
        int64_t n = std::stoull(ctx->INT_LITERAL()->getText());
        return std::make_shared<IntegerNode>(ctx->INT_LITERAL()->getSymbol()->getLine(), n);
    }
    else if (ctx->FLOAT_LITERAL()) {
        float f = std::stof(ctx->FLOAT_LITERAL()->getText());
        return std::make_shared<FloatNode>(ctx->FLOAT_LITERAL()->getSymbol()->getLine(), f);
    }
    else if (ctx->CHAR()) {
        char c = ctx->CHAR()->getText()[1];

        if (c == '\\') {
            switch (ctx->CHAR()->getText()[2]) {
                case '\'': c = '\''; break;
                case '\"': c = '\"'; break;
                case '\?': c = '\?'; break;
                case '\\': c = '\\'; break;
                case 'a' : c = '\a'; break;
                case 'b' : c = '\b'; break;
                case 'f' : c = '\f'; break;
                case 'n' : c = '\n'; break;
                case 'r' : c = '\r'; break;
                case 't' : c = '\t'; break;
                case 'v' : c = '\v'; break;
                default: {
                    report_err("invalid escape sequence: " + ctx->CHAR()->getText(), ctx->CHAR()->getSymbol()->getLine());
                }
            }
        }

        return std::make_shared<CharNode>(ctx->CHAR()->getSymbol()->getLine(), c);
    }
    else if (ctx->ptrderef) {
        auto* exp_ctx = ctx->exp(0);
        auto  exp = visitExp(exp_ctx);

        if (!exp->getRetType()._isptr) {
            report_err("cannot dereference a non pointer expression: " + exp_ctx->getText(), exp_ctx->getStart()->getLine());
        }
        
        // implement dereference node (that deduces the type of the dereferenced value upon construction)
    }
    else if (ctx->ptrgetref) {
        auto* id_ctx = ctx->ID();
        const std::string& id = id_ctx->getText();

        if (!is_var_defined(id)) {
            report_err("lvalue required as unary '&' operand: &" + id, id_ctx->getSymbol()->getLine());
        }

        // implement addressof node (that deduces the type of the newly created pointer)
    }
    else if (ctx->exp().size() == 2) {
        auto* left_exp_ctx  = ctx->exp(0);
        auto* right_exp_ctx = ctx->exp(1);

        auto left_exp  = visitExp(left_exp_ctx);
        auto right_exp = visitExp(right_exp_ctx);

        size_t line = left_exp_ctx->getStart()->getLine();

        const _typeinfo_t& t1 = left_exp->getRetType();
        const _typeinfo_t& t2 = right_exp->getRetType();

        _implicit_conversion_t _conv_info;

        if (!is_implicit_convertible(t1, t2, false) || !is_valid_arithmetic(t1, t2)) {
            std::string _operation = "(undefined operation)";
            size_t _line = (size_t)-1;

            if (ctx->PLUS()) {
                _operation = "add";
                _line = ctx->PLUS()->getSymbol()->getLine();
            }
            else if (ctx->MINUS()) {
                _operation = "subtract";
                _line = ctx->MINUS()->getSymbol()->getLine();
            }
            else if (ctx->MULT()) {
                _operation = "multiply";
                _line = ctx->MULT()->getSymbol()->getLine();
            }
            else if (ctx->DIV()) {
                _operation = "divide";
                _line = ctx->DIV()->getSymbol()->getLine();
            }

            report_err(
                fmt::format(
                    "can't {} an expression of type '{}' to another of type '{}'",
                    _operation,
                    left_exp->getRetType()._type,
                    right_exp->getRetType()._type
                ),
                _line
            );
        }
        else if (t1._type != t2._type) {
            _conv_info = get_expression_implicit_conversion(t1, t2);
            if (_conv_info._left_to_right) {
                left_exp = std::make_shared<ConversionNode>(line, std::move(left_exp), right_exp->getRetType());
            }
            else {
                right_exp = std::make_shared<ConversionNode>(line, std::move(right_exp), left_exp->getRetType());
            }
        }

        if (ctx->PLUS()) {
            return std::make_shared<MathNode>(line, std::move(left_exp), std::move(right_exp), '+', left_exp->getRetType());
        }
        else if (ctx->MINUS()) {
            return std::make_shared<MathNode>(line, std::move(left_exp), std::move(right_exp), '-', left_exp->getRetType());
        }
        else if (ctx->MULT()) {
            return std::make_shared<MathNode>(line, std::move(left_exp), std::move(right_exp), '*', left_exp->getRetType());
        }
        else if (ctx->DIV()) {
            return std::make_shared<MathNode>(line, std::move(left_exp), std::move(right_exp), '/', left_exp->getRetType());
        }
    }
    else if (ctx->exp().size() == 1 && ctx->LPAREN() && ctx->RPAREN()) {
        auto* exp_ctx = ctx->exp(0);
        auto  exp = visitExp(exp_ctx);
        
        return std::move(exp);
    }
    
    report_err("Expression is ill-formed", ctx->getStart()->getLine());
}