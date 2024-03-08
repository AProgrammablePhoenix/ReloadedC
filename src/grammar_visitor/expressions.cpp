#include <iostream>
#include <string>

#include <memory>
#include <vector>

#include "antlr4-runtime.h"
#include "../grammar/relcgrammarParser.h"

#include "../nodes/NodesLib.hpp"

#include "gvisitor.hpp"

namespace {
    static char process_escape_sequence(char c, size_t line) {
        switch (c) {
            case '\'': return '\'';
            case '\"': return '\"';
            case '\?': return '\?';
            case '\\': return '\\';
            case 'a' : return '\a';
            case 'b' : return '\b';
            case 'f' : return '\f';
            case 'n' : return '\n';
            case 'r' : return '\r';
            case 't' : return '\t';
            case 'v' : return '\v';
            default: {
                report_err("invalid escape sequence: \\" + c, line);
            }
        }
    }
}

std::shared_ptr<ExpNode> gvisitor::visitExp(relcgrammarParser::ExpContext *ctx) {
    if (ctx->native_call()) return visitNative_call(ctx->native_call());
    else if (ctx->ID()) {
        std::string sym_name = ctx->ID()->getText();
        size_t sym_line = ctx->ID()->getSymbol()->getLine();

        if (ctx->ptrgetref) {
            auto* id_ctx = ctx->ID();
            const std::string& id = id_ctx->getText();
            size_t id_line = id_ctx->getSymbol()->getLine();

            if (!is_var_defined(id)) report_err("undefined identifier: " + id, id_line);
            const _typeinfo_t& id_type = fetch_var_type(id, id_line);
            auto id_node = std::make_shared<IdentifierNode>(id_line, id, id_type);

            if (!is_var_defined(id)) {
                report_err("lvalue required as unary '&' operand: &" + id, id_line);
            }

            _typeinfo_t ret_type;
            ret_type._isconst = false;
            ret_type._isptr = true;
            ret_type._isvoidptr = id_type._isvoidptr;
            ret_type._ptrlvl = id_type._ptrlvl + 1;
            ret_type._type = id_type._type + '*';
            ret_type.ptrderef_tinfo = std::make_shared<_typeinfo_t>(id_type);

            return std::make_shared<AddressofNode>(id_ctx->getSymbol()->getLine(), id_node, ret_type);
        }
        else if (ctx->LPAREN()) {
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

        if (c == '\'') {
            report_err("invalid character in character literal: " + c, ctx->CHAR()->getSymbol()->getLine());
        }
        else if (c == '\\') {
            c = process_escape_sequence(ctx->CHAR()->getText()[2], ctx->CHAR()->getSymbol()->getLine());
        }

        return std::make_shared<CharNode>(ctx->CHAR()->getSymbol()->getLine(), c);
    }
    else if (ctx->STRING()) {
        std::string raw = ctx->STRING()->getText();
        const size_t length = raw.size() - 1;

        std::string temp = "";
        temp.reserve(length + 1);
        
        for (size_t i = 1; i < length; ++i) {
            char c = raw[i];

            if (c == '\"') {
                report_err("invalid character in string literal: " + c, ctx->STRING()->getSymbol()->getLine());
            }
            else if (c == '\\') {
                c = process_escape_sequence(raw[i + 1], ctx->STRING()->getSymbol()->getLine());
                ++i;
            }

            temp += c;
        }

        return std::make_shared<StringNode>(ctx->STRING()->getSymbol()->getLine(), temp);
    }
    else if (ctx->ptrderef) {
        auto* exp_ctx = ctx->exp(0);
        auto  exp = visitExp(exp_ctx);

        if (!exp->getRetType()._isptr) {
            report_err("cannot dereference a non pointer expression: " + exp_ctx->getText(), exp_ctx->getStart()->getLine());
        }

        return std::make_shared<DereferenceNode>(exp_ctx->getStart()->getLine(), std::move(exp), *exp->getRetType().ptrderef_tinfo);
    }
    else if (ctx->exp().size() == 2) {
        static const std::unordered_set<char> op_tokens{ '+', '-', '*', '/' };

        auto* left_exp_ctx  = ctx->exp(0);
        auto* right_exp_ctx = ctx->exp(1);

        auto left_exp  = visitExp(left_exp_ctx);
        auto right_exp = visitExp(right_exp_ctx);

        size_t line = left_exp_ctx->getStart()->getLine();

        const _typeinfo_t& t1 = left_exp->getRetType();
        const _typeinfo_t& t2 = right_exp->getRetType();

        _implicit_conversion_t _conv_info;

        char op;

        if (ctx->PLUS()) {
            op = '+';
        }
        else if (ctx->MINUS()) {
            op = '-';
        }
        else if (ctx->MULT()) {
            op = '*';
        }
        else if (ctx->DIV()) {
            op = '/';
        }

        if (is_valid_arithmetic(t1, t2, op) && is_pointer_addition(t1, t2, op)) {
            if (t1._isptr) {
                _typeinfo_t ser_ptr_t = get_ptr_serialized_type(t1._isconst);
                if (t2._type != ser_ptr_t._type) {
                    right_exp = std::make_shared<ConversionNode>(line, std::move(right_exp), ser_ptr_t);
                }
                return std::make_shared<PointerAdditionNode>(line, left_exp, right_exp);
            }
            else {
                _typeinfo_t ser_ptr_t = get_ptr_serialized_type(t2._isconst);
                if (t1._type != ser_ptr_t._type) {
                    left_exp = std::make_shared<ConversionNode>(line, std::move(left_exp), ser_ptr_t);
                }
                return std::make_shared<PointerAdditionNode>(line, right_exp, left_exp);
            }
        }
        else if (!is_implicit_convertible(t1, t2, false) || !is_valid_arithmetic(t1, t2, op)) {
            std::string _operation = "(undefined operation)";
            size_t _line = (size_t)-1;

            if (op == '+') {
                _operation = "add";
                _line = ctx->PLUS()->getSymbol()->getLine();
            }
            else if (op == '-') {
                _operation = "subtract";
                _line = ctx->MINUS()->getSymbol()->getLine();
            }
            else if (op == '*') {
                _operation = "multiply";
                _line = ctx->MULT()->getSymbol()->getLine();
            }
            else if (op == '/') {
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

        if (t1._isptr && t2._isptr && op == '-') {
            //left_exp = std::make_shared<ConversionNode>(line, std::move(left_exp), _serlialized_ptr_t(t1._isconst));
            //right_exp = std::make_shared<ConversionNode>(line, std::move(right_exp), _serlialized_ptr_t(t2._isconst));

            return std::make_shared<PointerSubtractionNode>(line, std::move(left_exp), std::move(right_exp));
        }

        if (op_tokens.contains(op)) {
            return std::make_shared<MathNode>(line, std::move(left_exp), std::move(right_exp), op, left_exp->getRetType());
        }
    }
    else if (ctx->exp().size() == 1 && ctx->LPAREN() && ctx->RPAREN()) {
        auto* exp_ctx = ctx->exp(0);
        auto  exp = visitExp(exp_ctx);
        
        return std::move(exp);
    }
    
    report_err("Expression is ill-formed", ctx->getStart()->getLine());
}