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
                    if (arg_list[i]->getRetType() != temp_program->getFunctions().at(sym_name).getParamsList()[i].second) {
                        report_err(
                            "wrong type of argument was provided (arg " + std::to_string(i + 1) + ") when calling function: " + sym_name,
                            sym_line
                        );
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
            std::string s_type = fetch_var_type(sym_name, sym_line);

            return std::make_shared<IdentifierNode>(sym_line, sym_name, s_type);
        }
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
        return std::make_shared<CharNode>(ctx->CHAR()->getSymbol()->getLine(), c);
    }
    else if (ctx->exp().size() == 2) {
        auto* left_exp_ctx  = ctx->exp(0);
        auto* right_exp_ctx = ctx->exp(1);

        auto left_exp  = visitExp(left_exp_ctx);
        auto right_exp = visitExp(right_exp_ctx);

        size_t line = left_exp_ctx->getStart()->getLine();

        if (ctx->PLUS()) {
            if (left_exp->getRetType() != right_exp->getRetType()) {
                report_err(
                    fmt::format(
                        "can't add an expression of type '{}' to another of type '{}'",
                        left_exp->getRetType(),
                        right_exp->getRetType()
                    ),
                    ctx->PLUS()->getSymbol()->getLine()
                );
            }
            return std::make_shared<MathNode>(line, std::move(left_exp), std::move(right_exp), '+', left_exp->getRetType());
        }
        else if (ctx->MINUS()) {
            if (left_exp->getRetType() != right_exp->getRetType()) {
                report_err(
                    fmt::format(
                        "can't subtract an expression of type '{}' to another of type '{}'",
                        left_exp->getRetType(),
                        right_exp->getRetType()
                    ),
                    ctx->PLUS()->getSymbol()->getLine()
                );
            }
            return std::make_shared<MathNode>(line, std::move(left_exp), std::move(right_exp), '-', left_exp->getRetType());
        }
        else if (ctx->MULT()) {
            if (left_exp->getRetType() != right_exp->getRetType()) {
                report_err(
                    fmt::format(
                        "can't multiply an expression of type '{}' to another of type '{}'",
                        left_exp->getRetType(),
                        right_exp->getRetType()
                    ),
                    ctx->PLUS()->getSymbol()->getLine()
                );
            }
            return std::make_shared<MathNode>(line, std::move(left_exp), std::move(right_exp), '*', left_exp->getRetType());
        }
        else if (ctx->DIV()) {
            if (left_exp->getRetType() != right_exp->getRetType()) {
                report_err(
                    fmt::format(
                        "can't divide an expression of type '{}' to another of type '{}'",
                        left_exp->getRetType(),
                        right_exp->getRetType()
                    ),
                    ctx->PLUS()->getSymbol()->getLine()
                );
            }
            return std::make_shared<MathNode>(line, std::move(left_exp), std::move(right_exp), '/', left_exp->getRetType());
        }
    }
    else if (ctx->exp().size() == 1 && ctx->LPAREN() && ctx->RPAREN()) {
        auto* exp_ctx = ctx->exp(0);
        auto exp = visitExp(exp_ctx);
        
        return std::move(exp);
    }
    
    report_err("Expression is ill-formed", ctx->getStart()->getLine());
}