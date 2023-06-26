
// Generated from src/antlr_grammar/relcgrammar.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "relcgrammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by relcgrammarParser.
 */
class  relcgrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by relcgrammarParser.
   */
    virtual std::any visitProgram(relcgrammarParser::ProgramContext *context) = 0;

    virtual std::any visitGlobal_statement(relcgrammarParser::Global_statementContext *context) = 0;

    virtual std::any visitStatement(relcgrammarParser::StatementContext *context) = 0;

    virtual std::any visitAssignment(relcgrammarParser::AssignmentContext *context) = 0;

    virtual std::any visitInitialization(relcgrammarParser::InitializationContext *context) = 0;

    virtual std::any visitExp(relcgrammarParser::ExpContext *context) = 0;

    virtual std::any visitNative_call(relcgrammarParser::Native_callContext *context) = 0;

    virtual std::any visitArguments_list(relcgrammarParser::Arguments_listContext *context) = 0;

    virtual std::any visitParameter(relcgrammarParser::ParameterContext *context) = 0;

    virtual std::any visitParameters_list(relcgrammarParser::Parameters_listContext *context) = 0;

    virtual std::any visitNative_func_prototype(relcgrammarParser::Native_func_prototypeContext *context) = 0;

    virtual std::any visitFunc_prototype(relcgrammarParser::Func_prototypeContext *context) = 0;

    virtual std::any visitFunc_declaration(relcgrammarParser::Func_declarationContext *context) = 0;

    virtual std::any visitScope(relcgrammarParser::ScopeContext *context) = 0;

    virtual std::any visitBordered_scope(relcgrammarParser::Bordered_scopeContext *context) = 0;

    virtual std::any visitFunc_scope(relcgrammarParser::Func_scopeContext *context) = 0;

    virtual std::any visitFunc_body(relcgrammarParser::Func_bodyContext *context) = 0;


};

