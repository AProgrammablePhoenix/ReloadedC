
// Generated from src/antlr_grammar/relcgrammar.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  relcgrammarParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, LONG_LITERAL = 2, INT_LITERAL = 3, FLOAT_LITERAL = 4, INTERNAL_TYPE = 5, 
    CONST = 6, NativeProtoDecl = 7, ID = 8, CHAR = 9, STRING = 10, PLUS = 11, 
    MINUS = 12, MULT = 13, DIV = 14, EQUAL = 15, SEMI = 16, COMMA = 17, 
    LPAREN = 18, RPAREN = 19, LCURL = 20, RCURL = 21, NATIVE_SCOPE = 22, 
    WS = 23
  };

  enum {
    RulePlain_type = 0, RulePointer_type = 1, RuleType = 2, RuleProgram = 3, 
    RuleGlobal_statement = 4, RuleStatement = 5, RuleAssignment = 6, RuleInitialization = 7, 
    RuleExp = 8, RuleNative_call = 9, RuleArguments_list = 10, RuleParameter = 11, 
    RuleParameters_list = 12, RuleNative_func_prototype = 13, RuleFunc_prototype = 14, 
    RuleFunc_declaration = 15, RuleScope = 16, RuleBordered_scope = 17, 
    RuleFunc_scope = 18, RuleFunc_body = 19
  };

  explicit relcgrammarParser(antlr4::TokenStream *input);

  relcgrammarParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~relcgrammarParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class Plain_typeContext;
  class Pointer_typeContext;
  class TypeContext;
  class ProgramContext;
  class Global_statementContext;
  class StatementContext;
  class AssignmentContext;
  class InitializationContext;
  class ExpContext;
  class Native_callContext;
  class Arguments_listContext;
  class ParameterContext;
  class Parameters_listContext;
  class Native_func_prototypeContext;
  class Func_prototypeContext;
  class Func_declarationContext;
  class ScopeContext;
  class Bordered_scopeContext;
  class Func_scopeContext;
  class Func_bodyContext; 

  class  Plain_typeContext : public antlr4::ParserRuleContext {
  public:
    Plain_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    antlr4::tree::TerminalNode *INTERNAL_TYPE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Plain_typeContext* plain_type();

  class  Pointer_typeContext : public antlr4::ParserRuleContext {
  public:
    Pointer_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Plain_typeContext *plain_type();
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *CONST();
    Pointer_typeContext *pointer_type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pointer_typeContext* pointer_type();
  Pointer_typeContext* pointer_type(int precedence);
  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Pointer_typeContext *pointer_type();
    Plain_typeContext *plain_type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Global_statementContext *> global_statement();
    Global_statementContext* global_statement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  Global_statementContext : public antlr4::ParserRuleContext {
  public:
    Global_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Native_func_prototypeContext *native_func_prototype();
    Func_prototypeContext *func_prototype();
    Func_bodyContext *func_body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Global_statementContext* global_statement();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentContext *assignment();
    antlr4::tree::TerminalNode *SEMI();
    InitializationContext *initialization();
    ExpContext *exp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *EQUAL();
    ExpContext *exp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  InitializationContext : public antlr4::ParserRuleContext {
  public:
    InitializationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *EQUAL();
    ExpContext *exp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitializationContext* initialization();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *ptrderef = nullptr;
    antlr4::Token *ptrgetref = nullptr;
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *ID();
    Native_callContext *native_call();
    Arguments_listContext *arguments_list();
    antlr4::tree::TerminalNode *LONG_LITERAL();
    antlr4::tree::TerminalNode *INT_LITERAL();
    antlr4::tree::TerminalNode *FLOAT_LITERAL();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpContext* exp();
  ExpContext* exp(int precedence);
  class  Native_callContext : public antlr4::ParserRuleContext {
  public:
    Native_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NATIVE_SCOPE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Arguments_listContext *arguments_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Native_callContext* native_call();

  class  Arguments_listContext : public antlr4::ParserRuleContext {
  public:
    Arguments_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arguments_listContext* arguments_list();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter();

  class  Parameters_listContext : public antlr4::ParserRuleContext {
  public:
    Parameters_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameters_listContext* parameters_list();

  class  Native_func_prototypeContext : public antlr4::ParserRuleContext {
  public:
    Native_func_prototypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NativeProtoDecl();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *RPAREN();
    Func_prototypeContext *func_prototype();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Native_func_prototypeContext* native_func_prototype();

  class  Func_prototypeContext : public antlr4::ParserRuleContext {
  public:
    Func_prototypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Func_declarationContext *func_declaration();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_prototypeContext* func_prototype();

  class  Func_declarationContext : public antlr4::ParserRuleContext {
  public:
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Parameters_listContext *parameters_list();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_declarationContext* func_declaration();

  class  ScopeContext : public antlr4::ParserRuleContext {
  public:
    ScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScopeContext* scope();

  class  Bordered_scopeContext : public antlr4::ParserRuleContext {
  public:
    Bordered_scopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCURL();
    ScopeContext *scope();
    antlr4::tree::TerminalNode *RCURL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bordered_scopeContext* bordered_scope();

  class  Func_scopeContext : public antlr4::ParserRuleContext {
  public:
    Func_scopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Bordered_scopeContext *bordered_scope();
    antlr4::tree::TerminalNode *LCURL();
    antlr4::tree::TerminalNode *RCURL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_scopeContext* func_scope();

  class  Func_bodyContext : public antlr4::ParserRuleContext {
  public:
    Func_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Func_declarationContext *func_declaration();
    Func_scopeContext *func_scope();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_bodyContext* func_body();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool pointer_typeSempred(Pointer_typeContext *_localctx, size_t predicateIndex);
  bool expSempred(ExpContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

