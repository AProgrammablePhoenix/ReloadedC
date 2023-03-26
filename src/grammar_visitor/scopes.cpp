#include <iostream>
#include <string>

#include <memory>
#include <vector>

#include "antlr4-runtime.h"
#include "../grammar/relcgrammarParser.h"

#include "../nodes/NodesLib.hpp"

#include "gvisitor.hpp"

std::vector<StatementNode> gvisitor::visitScope(relcgrammarParser::ScopeContext *ctx) {
    std::vector<StatementNode> ret;

    for (auto* stmt_ctx : ctx->statement()) {
        ret.push_back(*visitStatement(stmt_ctx));
    }

    return ret;
}
std::vector<StatementNode> gvisitor::visitBordered_scope(relcgrammarParser::Bordered_scopeContext *ctx) {
    return visitScope(ctx->scope());
}