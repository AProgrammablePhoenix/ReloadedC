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
        return std::make_unique<StatementNode>(
            ctx->assignment()->getStart()->getLine(),
            stmt.second,
            AssignmentDestData(stmt.first)
        );
    }
    else if (ctx->initialization()) {
        auto stmt = visitInitialization(ctx->initialization());
        return std::make_unique<StatementNode>(
            ctx->initialization()->getStart()->getLine(),
            stmt.second,
            stmt.first
        );
    }
    else if (ctx->exp()) {
        auto stmt = visitExp(ctx->exp());
        return std::make_unique<StatementNode>(
            ctx->exp()->getStart()->getLine(),
            stmt,
            AssignmentDestData("")
        );
    }

    return nullptr;
}
std::pair<AssignmentDestData, std::shared_ptr<ExpNode>> gvisitor::visitAssignment(relcgrammarParser::AssignmentContext* ctx) {
    if (ctx->ID()) {
        std::string vname = ctx->ID()->getText();
        std::shared_ptr<ExpNode> exp = visitExp(ctx->exp()[0]);

        size_t vname_line = ctx->ID()->getSymbol()->getLine();
        const auto& vdata = fetch_var_data(vname, vname_line);
        
        if (!is_implicit_convertible(exp->getRetType(), vdata._tinfo)) {
            report_err(fmt::format("can't assign a value of type '{}' to a variable of type '{}'", exp->getRetType()._type, vdata._tinfo._type), vname_line);
        }
        else if (vdata._tinfo._isconst) {
            report_err(fmt::format("assignment of read-only variable '{}'", vname), vname_line);
        }
        else if (vdata._tinfo._type != exp->getRetType()._type) {
            exp = std::make_shared<ConversionNode>(exp->getline(), std::move(exp), vdata._tinfo);
        }

        return std::make_pair(AssignmentDestData(vname), exp);
    }
    else {
        auto raw_dest_exp = ctx->exp()[0];

        if (!ctx->ptrderef) {
            report_err(
                "cannot assign a value to an rvalue expression: " + raw_dest_exp->getText(),
                raw_dest_exp->getStart()->getLine()
            );
        }
        std::shared_ptr<ExpNode> dest_exp = visitExp(raw_dest_exp);
        std::shared_ptr<ExpNode> exp = visitExp(ctx->exp()[1]);

        const _typeinfo_t exp_type = exp->getRetType();
        const _typeinfo_t ptr_underlying_type = *dest_exp->getRetType().ptrderef_tinfo;

        if (!is_implicit_convertible(exp_type, ptr_underlying_type)) {
            report_err(
                fmt::format(
                    "cannot assign a value of type '{}' to a variable stored in a pointer of type '{}'",
                    exp->getRetType()._type,
                    dest_exp->getRetType()._type
                ),
                ctx->ptrderef->getLine()
            );
        }
        else if (ptr_underlying_type._isconst) {
            report_err(
                fmt::format(
                    "Cannot assign a value to pointer to const '{}'",
                    raw_dest_exp->getText()
                ),
                ctx->ptrderef->getLine()
            );
        }
        else if (exp_type._type != ptr_underlying_type._type) {
            exp = std::make_shared<ConversionNode>(exp->getline(), std::move(exp), ptr_underlying_type);
        }


        return std::make_pair(AssignmentDestData(dest_exp), exp);
    }
}
std::pair<std::string, std::shared_ptr<ExpNode>> gvisitor::visitInitialization(relcgrammarParser::InitializationContext* ctx) {
    std::string vname = ctx->ID()->getText();
    _typeinfo_t vtype = visitType(ctx->type());

    std::shared_ptr<ExpNode> exp = visitExp(ctx->exp());
    size_t vname_line = ctx->ID()->getSymbol()->getLine();

    if (vtype._type == "void") {
        report_err(fmt::format("illegal creation of a 'void' variable '{}'", vname), vname_line);
    }
    else if (!is_implicit_convertible(exp->getRetType(), vtype)) {
        report_err(fmt::format("can't assign a value of type '{}' to a variable of type '{}'", exp->getRetType()._type, vtype._type), vname_line);
    }
    else if (is_var_defined(vname)) {
        report_err("redifition of variable: " + vname, vname_line);
    }
    else if (vtype._type != exp->getRetType()._type) {
        exp = std::make_shared<ConversionNode>(exp->getline(), std::move(exp), vtype);
    }
    
    function_local_vars.push_back({
        ._name = vname,
        ._tinfo = vtype
    });
    return std::make_pair(vname, exp);
}