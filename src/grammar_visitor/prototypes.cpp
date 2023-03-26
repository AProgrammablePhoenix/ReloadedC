#include <iostream>
#include <string>

#include <memory>
#include <tuple>
#include <vector>

#include "antlr4-runtime.h"
#include "../grammar/relcgrammarParser.h"

#include "../nodes/NodesLib.hpp"
#include "../symbols.hpp"

#include "gvisitor.hpp"

std::tuple<std::string, std::string, funcproto> gvisitor::visitNative_func_prototype(relcgrammarParser::Native_func_prototypeContext *ctx) {
    auto nfproto = visitFunc_prototype(ctx->func_prototype());
    std::string lib = ctx->ID()->getText();

    return std::make_tuple(nfproto.first, lib, nfproto.second);
}
std::pair<std::string, funcproto> gvisitor::visitFunc_prototype(relcgrammarParser::Func_prototypeContext *ctx) {
    auto func_decl = visitFunc_declaration(ctx->func_declaration());

    auto fproto = funcproto(func_decl.second, this->function_parameters);

    return std::make_pair(func_decl.first, fproto);
}
