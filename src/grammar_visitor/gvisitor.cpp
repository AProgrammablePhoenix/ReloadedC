#include <iostream>
#include <string>

#include <memory>
#include <vector>

#include "antlr4-runtime.h"
#include "../grammar/relcgrammarParser.h"

#include "../nodes/NodesLib.hpp"
#include "../symbols.hpp"

#include "gvisitor.hpp"

std::shared_ptr<ProgramNode> gvisitor::visitProgram(relcgrammarParser::ProgramContext *ctx, const std::string& tu_name) {
    size_t line = ctx->getStart()->getLine();
    temp_program = std::make_shared<ProgramNode>(line, tu_name);

    for (auto* gstmt : ctx->global_statement()) {
        visitGlobal_statement(gstmt);
    }

    for (const auto& proto : prototypes) {
        if (!proto.second.isResolved()) {
            report_err("Unresolved function: " + proto.first, 0);
        }
    }

    if (!temp_program->getFunctions().count("main")) {
        report_err("No entry point was found ( expecting function 'int main()' )", 0);
    }
    else if (!temp_program->getFunctions().at("main").getParamsList().empty()) {
        report_err("Definition of 'main' is not consistent with prototype 'int main()' ", 0);
    }

    return std::move(temp_program);
}

void gvisitor::visitGlobal_statement(relcgrammarParser::Global_statementContext *ctx) {
    if (ctx->native_func_prototype()) { // contains a native function prototype
        auto nproto = visitNative_func_prototype(ctx->native_func_prototype());
        auto& [nfname, nflib, nfproto] = nproto;

        if (native_prototypes.count(nfname)) report_err(fmt::format("redifition of native function '{}'", nfname), ctx->getStart()->getLine());

        native_prototypes.emplace(nfname, std::make_pair(nflib, nfproto));

        function_parameters.clear();
    }
    else if (ctx->func_prototype()) { // contains a user-defined function prototype
        auto proto = visitFunc_prototype(ctx->func_prototype());
        funcproto& fproto = proto.second;

        if (prototypes.count(proto.first)) report_err("redifition of function '" + proto.first + "'", ctx->getStart()->getLine());

        prototypes.emplace(proto.first, fproto);

        function_parameters.clear();
    }
    else { // otherwise, contains a func_body
        auto func = visitFunc_body(ctx->func_body());
        funcsym& fsym = func.second;

        for (const auto& _vdef : function_local_vars) {
            fsym.addVarSym(_vdef._name, _vdef._tinfo);
        }
        temp_program->addFunction(func.first, fsym);

        if (prototypes.count(func.first)) prototypes.at(func.first).setAsResolved();

        function_local_vars.clear();
        function_parameters.clear();
    }
}