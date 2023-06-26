
// Generated from src/antlr_grammar/relcgrammar.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "relcgrammarVisitor.h"


/**
 * This class provides an empty implementation of relcgrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  relcgrammarBaseVisitor : public relcgrammarVisitor {
public:

  virtual std::any visitProgram(relcgrammarParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobal_statement(relcgrammarParser::Global_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(relcgrammarParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(relcgrammarParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitialization(relcgrammarParser::InitializationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp(relcgrammarParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNative_call(relcgrammarParser::Native_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments_list(relcgrammarParser::Arguments_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter(relcgrammarParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameters_list(relcgrammarParser::Parameters_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNative_func_prototype(relcgrammarParser::Native_func_prototypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_prototype(relcgrammarParser::Func_prototypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_declaration(relcgrammarParser::Func_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScope(relcgrammarParser::ScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBordered_scope(relcgrammarParser::Bordered_scopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_scope(relcgrammarParser::Func_scopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_body(relcgrammarParser::Func_bodyContext *ctx) override {
    return visitChildren(ctx);
  }


};

