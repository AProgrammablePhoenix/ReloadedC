#include <iostream>
#include <string>

#include <memory>
#include <vector>

#include "antlr4-runtime.h"
#include "../grammar/relcgrammarParser.h"

#include "../nodes/NodesLib.hpp"

#include "gvisitor.hpp"

std::shared_ptr<StatementNode> gvisitor::visitStatement(relcgrammarParser::StatementContext* ctx) {
    if (!ctx->SEMI()) report_err("missing semicolon ';' at end of statement", ctx->getStart()->getLine());
    
    if (ctx->assignment()) {
        auto stmt = visitAssignment(ctx->assignment());
        return std::make_unique<StatementNode>(ctx->assignment()->getStart()->getLine(), stmt.second, stmt.first);
    }
    else if (ctx->initialization()) {
        auto stmt = visitInitialization(ctx->initialization());
        return std::make_unique<StatementNode>(ctx->initialization()->getStart()->getLine(), stmt.second, stmt.first);
    }
    else if (ctx->exp()) {
        auto stmt = visitExp(ctx->exp());
        return std::make_unique<StatementNode>(ctx->exp()->getStart()->getLine(), stmt, "");
    }

    return nullptr;
}
std::pair<std::string, std::shared_ptr<ExpNode>> gvisitor::visitAssignment(relcgrammarParser::AssignmentContext* ctx) {
    std::string vname = ctx->ID()->getText();
    std::shared_ptr<ExpNode> exp = visitExp(ctx->exp());

    size_t vname_line = ctx->ID()->getSymbol()->getLine();
    const std::string& vtype = fetch_var_type(vname, vname_line);
    
    if (vtype != exp->getRetType()) report_err(fmt::format("can't assign a value of type '{}' to a variable of type '{}'", exp->getRetType(), vtype), vname_line);
    else if (!is_var_defined(vname)) report_err("undefined variable: " + vname, vname_line);    

    return std::make_pair(vname, exp);
}
std::pair<std::string, std::shared_ptr<ExpNode>> gvisitor::visitInitialization(relcgrammarParser::InitializationContext *ctx) {
    std::string vtype = ctx->TYPE()->getText();
    std::string vname = ctx->ID()->getText();
    std::shared_ptr<ExpNode> exp = visitExp(ctx->exp());

    size_t vname_line = ctx->ID()->getSymbol()->getLine();

    if (vtype == "void") report_err(fmt::format("illegal creation of a 'void' variable (name: '{}')", vname), vname_line);
    else if (vtype != exp->getRetType()) report_err(fmt::format("can't assign a value of type '{}' to a variable of type '{}'", exp->getRetType(), vtype), vname_line);
    else if (is_var_defined(vname)) report_err("redifition of variable: " + vname, vname_line);
    
    function_local_vars.emplace_back(vname, vtype);
    return std::make_pair(vname, exp);
}