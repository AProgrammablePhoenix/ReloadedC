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
    const auto& vdata = fetch_var_data(vname, vname_line);
    
    if (!is_implicit_convertible(vdata._type, exp->getRetType())) {
        report_err(fmt::format("can't assign a value of type '{}' to a variable of type '{}'", exp->getRetType(), vdata._type), vname_line);
    }
    else if (vdata._type != exp->getRetType()) {
        exp = std::make_shared<ConversionNode>(exp->getline(), std::move(exp), vdata._type);
    }
    else if (vdata._isconst) {
        report_err(fmt::format("assignment of read-only variable '{}'", vname), vname_line);
    }

    return std::make_pair(vname, exp);
}
std::pair<std::string, std::shared_ptr<ExpNode>> gvisitor::visitInitialization(relcgrammarParser::InitializationContext *ctx) {
    std::string vtype = ctx->TYPE()->getText();
    std::string vname = ctx->ID()->getText();
    bool vconstness = ctx->CONST() != NULL;

    std::shared_ptr<ExpNode> exp = visitExp(ctx->exp());

    if (vtype == "long long") {
        vtype = "long";
    }

    size_t vname_line = ctx->ID()->getSymbol()->getLine();

    if (vtype == "void") {
        report_err(fmt::format("illegal creation of a 'void' variable '{}'", vname), vname_line);
    }
    else if (!is_implicit_convertible(vtype, exp->getRetType())) {
        report_err(fmt::format("can't assign a value of type '{}' to a variable of type '{}'", exp->getRetType(), vtype), vname_line);
    }
    else if (is_var_defined(vname)) {
        report_err("redifition of variable: " + vname, vname_line);
    }
    else if (vtype != exp->getRetType()) {
        exp = std::make_shared<ConversionNode>(exp->getline(), std::move(exp), vtype);
    }
    
    function_local_vars.push_back({
        ._name = vname,
        ._type = vtype,
        ._isconst = vconstness
    });
    return std::make_pair(vname, exp);
}