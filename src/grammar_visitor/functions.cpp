#include <iostream>
#include <string>

#include <memory>
#include <vector>

#include "antlr4-runtime.h"
#include "../grammar/relcgrammarParser.h"

#include "../nodes/NodesLib.hpp"
#include "../symbols.hpp"

#include "gvisitor.hpp"

std::pair<std::string, funcsym> gvisitor::visitFunc_body(relcgrammarParser::Func_bodyContext *ctx) {
    auto func_decl = visitFunc_declaration(ctx->func_declaration());
    auto func_scope = visitFunc_scope(ctx->func_scope());

    auto fsym = funcsym(func_decl.second, this->function_parameters, func_scope);

    return std::make_pair(func_decl.first, fsym);
}
std::pair<std::string, std::string> gvisitor::visitFunc_declaration(relcgrammarParser::Func_declarationContext *ctx) {
    std::string ftype = ctx->TYPE()->getText();
    std::string fname = ctx->ID()->getText();

    auto* plist = ctx->parameters_list();
    if (plist) {
        visitParameters_list(plist);
    }

    if (prototypes.count(fname)) {
        const auto& proto_plist = prototypes.at(fname).getParamsList();
        if (proto_plist.size() != function_parameters.size()) {
            report_err("Function declaration is not consistent with the function prototype", ctx->TYPE()->getSymbol()->getLine());
        }

        for (size_t i = 0; i < proto_plist.size(); ++i) {
            // only check for types, not parameters names
            if (proto_plist[i].second != function_parameters[i].second) {
                report_err(
                    fmt::format("Function declaration is not consistent with the function prototype (types for argument {} differ)", i + 1),
                    ctx->TYPE()->getSymbol()->getLine()
                );
            }
        }
    }

    return std::make_pair(fname, ftype);
}
std::shared_ptr<ExpNode> gvisitor::visitNative_call(relcgrammarParser::Native_callContext *ctx) {
    std::string nfsym_name = ctx->ID()->getText();
    size_t nfsym_line = ctx->ID()->getSymbol()->getLine();

    if (!native_prototypes.count(nfsym_name)) {
        report_err(fmt::format("Native function '{}' has not been declared in this scope", nfsym_name), nfsym_line);
    }

    auto& [nflib, nproto] = native_prototypes.at(nfsym_name);
    const std::string& ret_type = nproto.getRetType();

    std::vector<std::shared_ptr<ExpNode>> args_list;

    if (ctx->arguments_list()) {
        args_list = visitArguments_list(ctx->arguments_list());
    }

    return std::make_shared<NativeFunctionCall>(nfsym_line, nfsym_name, nflib, args_list, ret_type);
}
std::vector<std::shared_ptr<ExpNode>> gvisitor::visitArguments_list(relcgrammarParser::Arguments_listContext *ctx) {
    std::vector<std::shared_ptr<ExpNode>> ret;

    for (auto* exp_ctx : ctx->exp()) {
        ret.push_back(visitExp(exp_ctx));
    }

    return ret;
}
void gvisitor::visitParameter(relcgrammarParser::ParameterContext *ctx) {
    std::string p_type = ctx->TYPE()->getText();
    std::string p_name = ctx->ID()->getText();

    function_parameters.emplace_back(p_name, p_type);
}
void gvisitor::visitParameters_list(relcgrammarParser::Parameters_listContext *ctx) {
    for (auto* param : ctx->parameter()) {
        visitParameter(param);
    }
}
std::vector<StatementNode> gvisitor::visitFunc_scope(relcgrammarParser::Func_scopeContext *ctx) {
    if (!ctx->bordered_scope()) { // means empty scope aka LCURL RCURL or { }
        return std::vector<StatementNode>();
    }
    return visitBordered_scope(ctx->bordered_scope());
}
