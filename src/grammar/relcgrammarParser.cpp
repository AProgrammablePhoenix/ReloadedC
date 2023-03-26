
// Generated from src/antlr_grammar/relcgrammar.g4 by ANTLR 4.10.1


#include "relcgrammarVisitor.h"

#include "relcgrammarParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct RelcgrammarParserStaticData final {
  RelcgrammarParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  RelcgrammarParserStaticData(const RelcgrammarParserStaticData&) = delete;
  RelcgrammarParserStaticData(RelcgrammarParserStaticData&&) = delete;
  RelcgrammarParserStaticData& operator=(const RelcgrammarParserStaticData&) = delete;
  RelcgrammarParserStaticData& operator=(RelcgrammarParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag relcgrammarParserOnceFlag;
RelcgrammarParserStaticData *relcgrammarParserStaticData = nullptr;

void relcgrammarParserInitialize() {
  assert(relcgrammarParserStaticData == nullptr);
  auto staticData = std::make_unique<RelcgrammarParserStaticData>(
    std::vector<std::string>{
      "program", "global_statement", "statement", "assignment", "initialization", 
      "exp", "native_call", "arguments_list", "parameter", "parameters_list", 
      "native_func_prototype", "func_prototype", "func_declaration", "scope", 
      "bordered_scope", "func_scope", "func_body"
    },
    std::vector<std::string>{
      "", "", "", "", "'__nativedecl'", "", "", "'+'", "'-'", "'*'", "'/'", 
      "'='", "';'", "','", "'('", "')'", "'{'", "'}'", "'::'"
    },
    std::vector<std::string>{
      "", "INT_LITERAL", "FLOAT_LITERAL", "TYPE", "NativeProtoDecl", "ID", 
      "CHAR", "PLUS", "MINUS", "MULT", "DIV", "EQUAL", "SEMI", "COMMA", 
      "LPAREN", "RPAREN", "LCURL", "RCURL", "NATIVE_SCOPE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,19,170,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,1,0,4,0,36,8,0,11,0,12,0,37,1,1,1,1,1,1,3,1,43,
  	8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,57,8,2,1,3,1,
  	3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,86,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,5,5,100,8,5,10,5,12,5,103,9,5,1,6,1,6,1,6,1,6,3,
  	6,109,8,6,1,6,1,6,1,7,1,7,1,7,5,7,116,8,7,10,7,12,7,119,9,7,1,8,1,8,1,
  	8,1,9,1,9,1,9,5,9,127,8,9,10,9,12,9,130,9,9,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	3,12,151,8,12,1,13,4,13,154,8,13,11,13,12,13,155,1,14,1,14,1,14,1,14,
  	1,15,1,15,1,15,3,15,165,8,15,1,16,1,16,1,16,1,16,0,1,10,17,0,2,4,6,8,
  	10,12,14,16,18,20,22,24,26,28,30,32,0,0,177,0,35,1,0,0,0,2,42,1,0,0,0,
  	4,56,1,0,0,0,6,58,1,0,0,0,8,62,1,0,0,0,10,85,1,0,0,0,12,104,1,0,0,0,14,
  	112,1,0,0,0,16,120,1,0,0,0,18,123,1,0,0,0,20,131,1,0,0,0,22,137,1,0,0,
  	0,24,150,1,0,0,0,26,153,1,0,0,0,28,157,1,0,0,0,30,164,1,0,0,0,32,166,
  	1,0,0,0,34,36,3,2,1,0,35,34,1,0,0,0,36,37,1,0,0,0,37,35,1,0,0,0,37,38,
  	1,0,0,0,38,1,1,0,0,0,39,43,3,20,10,0,40,43,3,22,11,0,41,43,3,32,16,0,
  	42,39,1,0,0,0,42,40,1,0,0,0,42,41,1,0,0,0,43,3,1,0,0,0,44,45,3,6,3,0,
  	45,46,5,12,0,0,46,57,1,0,0,0,47,48,3,8,4,0,48,49,5,12,0,0,49,57,1,0,0,
  	0,50,51,3,10,5,0,51,52,5,12,0,0,52,57,1,0,0,0,53,57,3,6,3,0,54,57,3,8,
  	4,0,55,57,3,10,5,0,56,44,1,0,0,0,56,47,1,0,0,0,56,50,1,0,0,0,56,53,1,
  	0,0,0,56,54,1,0,0,0,56,55,1,0,0,0,57,5,1,0,0,0,58,59,5,5,0,0,59,60,5,
  	11,0,0,60,61,3,10,5,0,61,7,1,0,0,0,62,63,5,3,0,0,63,64,5,5,0,0,64,65,
  	5,11,0,0,65,66,3,10,5,0,66,9,1,0,0,0,67,68,6,5,-1,0,68,86,3,12,6,0,69,
  	70,5,5,0,0,70,71,5,14,0,0,71,72,3,14,7,0,72,73,5,15,0,0,73,86,1,0,0,0,
  	74,75,5,5,0,0,75,76,5,14,0,0,76,86,5,15,0,0,77,86,5,5,0,0,78,86,5,1,0,
  	0,79,86,5,2,0,0,80,86,5,6,0,0,81,82,5,14,0,0,82,83,3,10,5,0,83,84,5,15,
  	0,0,84,86,1,0,0,0,85,67,1,0,0,0,85,69,1,0,0,0,85,74,1,0,0,0,85,77,1,0,
  	0,0,85,78,1,0,0,0,85,79,1,0,0,0,85,80,1,0,0,0,85,81,1,0,0,0,86,101,1,
  	0,0,0,87,88,10,5,0,0,88,89,5,7,0,0,89,100,3,10,5,6,90,91,10,4,0,0,91,
  	92,5,8,0,0,92,100,3,10,5,5,93,94,10,3,0,0,94,95,5,9,0,0,95,100,3,10,5,
  	4,96,97,10,2,0,0,97,98,5,10,0,0,98,100,3,10,5,3,99,87,1,0,0,0,99,90,1,
  	0,0,0,99,93,1,0,0,0,99,96,1,0,0,0,100,103,1,0,0,0,101,99,1,0,0,0,101,
  	102,1,0,0,0,102,11,1,0,0,0,103,101,1,0,0,0,104,105,5,18,0,0,105,106,5,
  	5,0,0,106,108,5,14,0,0,107,109,3,14,7,0,108,107,1,0,0,0,108,109,1,0,0,
  	0,109,110,1,0,0,0,110,111,5,15,0,0,111,13,1,0,0,0,112,117,3,10,5,0,113,
  	114,5,13,0,0,114,116,3,10,5,0,115,113,1,0,0,0,116,119,1,0,0,0,117,115,
  	1,0,0,0,117,118,1,0,0,0,118,15,1,0,0,0,119,117,1,0,0,0,120,121,5,3,0,
  	0,121,122,5,5,0,0,122,17,1,0,0,0,123,128,3,16,8,0,124,125,5,13,0,0,125,
  	127,3,16,8,0,126,124,1,0,0,0,127,130,1,0,0,0,128,126,1,0,0,0,128,129,
  	1,0,0,0,129,19,1,0,0,0,130,128,1,0,0,0,131,132,5,4,0,0,132,133,5,14,0,
  	0,133,134,5,5,0,0,134,135,5,15,0,0,135,136,3,22,11,0,136,21,1,0,0,0,137,
  	138,3,24,12,0,138,139,5,12,0,0,139,23,1,0,0,0,140,141,5,3,0,0,141,142,
  	5,5,0,0,142,143,5,14,0,0,143,144,3,18,9,0,144,145,5,15,0,0,145,151,1,
  	0,0,0,146,147,5,3,0,0,147,148,5,5,0,0,148,149,5,14,0,0,149,151,5,15,0,
  	0,150,140,1,0,0,0,150,146,1,0,0,0,151,25,1,0,0,0,152,154,3,4,2,0,153,
  	152,1,0,0,0,154,155,1,0,0,0,155,153,1,0,0,0,155,156,1,0,0,0,156,27,1,
  	0,0,0,157,158,5,16,0,0,158,159,3,26,13,0,159,160,5,17,0,0,160,29,1,0,
  	0,0,161,165,3,28,14,0,162,163,5,16,0,0,163,165,5,17,0,0,164,161,1,0,0,
  	0,164,162,1,0,0,0,165,31,1,0,0,0,166,167,3,24,12,0,167,168,3,30,15,0,
  	168,33,1,0,0,0,12,37,42,56,85,99,101,108,117,128,150,155,164
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  relcgrammarParserStaticData = staticData.release();
}

}

relcgrammarParser::relcgrammarParser(TokenStream *input) : relcgrammarParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

relcgrammarParser::relcgrammarParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  relcgrammarParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *relcgrammarParserStaticData->atn, relcgrammarParserStaticData->decisionToDFA, relcgrammarParserStaticData->sharedContextCache, options);
}

relcgrammarParser::~relcgrammarParser() {
  delete _interpreter;
}

const atn::ATN& relcgrammarParser::getATN() const {
  return *relcgrammarParserStaticData->atn;
}

std::string relcgrammarParser::getGrammarFileName() const {
  return "relcgrammar.g4";
}

const std::vector<std::string>& relcgrammarParser::getRuleNames() const {
  return relcgrammarParserStaticData->ruleNames;
}

const dfa::Vocabulary& relcgrammarParser::getVocabulary() const {
  return relcgrammarParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView relcgrammarParser::getSerializedATN() const {
  return relcgrammarParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

relcgrammarParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<relcgrammarParser::Global_statementContext *> relcgrammarParser::ProgramContext::global_statement() {
  return getRuleContexts<relcgrammarParser::Global_statementContext>();
}

relcgrammarParser::Global_statementContext* relcgrammarParser::ProgramContext::global_statement(size_t i) {
  return getRuleContext<relcgrammarParser::Global_statementContext>(i);
}


size_t relcgrammarParser::ProgramContext::getRuleIndex() const {
  return relcgrammarParser::RuleProgram;
}


std::any relcgrammarParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::ProgramContext* relcgrammarParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, relcgrammarParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(34);
      global_statement();
      setState(37); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == relcgrammarParser::TYPE

    || _la == relcgrammarParser::NativeProtoDecl);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Global_statementContext ------------------------------------------------------------------

relcgrammarParser::Global_statementContext::Global_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

relcgrammarParser::Native_func_prototypeContext* relcgrammarParser::Global_statementContext::native_func_prototype() {
  return getRuleContext<relcgrammarParser::Native_func_prototypeContext>(0);
}

relcgrammarParser::Func_prototypeContext* relcgrammarParser::Global_statementContext::func_prototype() {
  return getRuleContext<relcgrammarParser::Func_prototypeContext>(0);
}

relcgrammarParser::Func_bodyContext* relcgrammarParser::Global_statementContext::func_body() {
  return getRuleContext<relcgrammarParser::Func_bodyContext>(0);
}


size_t relcgrammarParser::Global_statementContext::getRuleIndex() const {
  return relcgrammarParser::RuleGlobal_statement;
}


std::any relcgrammarParser::Global_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitGlobal_statement(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::Global_statementContext* relcgrammarParser::global_statement() {
  Global_statementContext *_localctx = _tracker.createInstance<Global_statementContext>(_ctx, getState());
  enterRule(_localctx, 2, relcgrammarParser::RuleGlobal_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(42);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(39);
      native_func_prototype();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(40);
      func_prototype();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(41);
      func_body();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

relcgrammarParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

relcgrammarParser::AssignmentContext* relcgrammarParser::StatementContext::assignment() {
  return getRuleContext<relcgrammarParser::AssignmentContext>(0);
}

tree::TerminalNode* relcgrammarParser::StatementContext::SEMI() {
  return getToken(relcgrammarParser::SEMI, 0);
}

relcgrammarParser::InitializationContext* relcgrammarParser::StatementContext::initialization() {
  return getRuleContext<relcgrammarParser::InitializationContext>(0);
}

relcgrammarParser::ExpContext* relcgrammarParser::StatementContext::exp() {
  return getRuleContext<relcgrammarParser::ExpContext>(0);
}


size_t relcgrammarParser::StatementContext::getRuleIndex() const {
  return relcgrammarParser::RuleStatement;
}


std::any relcgrammarParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::StatementContext* relcgrammarParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, relcgrammarParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(56);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(44);
      assignment();
      setState(45);
      match(relcgrammarParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(47);
      initialization();
      setState(48);
      match(relcgrammarParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(50);
      exp(0);
      setState(51);
      match(relcgrammarParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(53);
      assignment();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(54);
      initialization();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(55);
      exp(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

relcgrammarParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* relcgrammarParser::AssignmentContext::ID() {
  return getToken(relcgrammarParser::ID, 0);
}

tree::TerminalNode* relcgrammarParser::AssignmentContext::EQUAL() {
  return getToken(relcgrammarParser::EQUAL, 0);
}

relcgrammarParser::ExpContext* relcgrammarParser::AssignmentContext::exp() {
  return getRuleContext<relcgrammarParser::ExpContext>(0);
}


size_t relcgrammarParser::AssignmentContext::getRuleIndex() const {
  return relcgrammarParser::RuleAssignment;
}


std::any relcgrammarParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::AssignmentContext* relcgrammarParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 6, relcgrammarParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(relcgrammarParser::ID);
    setState(59);
    match(relcgrammarParser::EQUAL);
    setState(60);
    exp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitializationContext ------------------------------------------------------------------

relcgrammarParser::InitializationContext::InitializationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* relcgrammarParser::InitializationContext::TYPE() {
  return getToken(relcgrammarParser::TYPE, 0);
}

tree::TerminalNode* relcgrammarParser::InitializationContext::ID() {
  return getToken(relcgrammarParser::ID, 0);
}

tree::TerminalNode* relcgrammarParser::InitializationContext::EQUAL() {
  return getToken(relcgrammarParser::EQUAL, 0);
}

relcgrammarParser::ExpContext* relcgrammarParser::InitializationContext::exp() {
  return getRuleContext<relcgrammarParser::ExpContext>(0);
}


size_t relcgrammarParser::InitializationContext::getRuleIndex() const {
  return relcgrammarParser::RuleInitialization;
}


std::any relcgrammarParser::InitializationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitInitialization(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::InitializationContext* relcgrammarParser::initialization() {
  InitializationContext *_localctx = _tracker.createInstance<InitializationContext>(_ctx, getState());
  enterRule(_localctx, 8, relcgrammarParser::RuleInitialization);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    match(relcgrammarParser::TYPE);
    setState(63);
    match(relcgrammarParser::ID);
    setState(64);
    match(relcgrammarParser::EQUAL);
    setState(65);
    exp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

relcgrammarParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

relcgrammarParser::Native_callContext* relcgrammarParser::ExpContext::native_call() {
  return getRuleContext<relcgrammarParser::Native_callContext>(0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::ID() {
  return getToken(relcgrammarParser::ID, 0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::LPAREN() {
  return getToken(relcgrammarParser::LPAREN, 0);
}

relcgrammarParser::Arguments_listContext* relcgrammarParser::ExpContext::arguments_list() {
  return getRuleContext<relcgrammarParser::Arguments_listContext>(0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::RPAREN() {
  return getToken(relcgrammarParser::RPAREN, 0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::INT_LITERAL() {
  return getToken(relcgrammarParser::INT_LITERAL, 0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::FLOAT_LITERAL() {
  return getToken(relcgrammarParser::FLOAT_LITERAL, 0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::CHAR() {
  return getToken(relcgrammarParser::CHAR, 0);
}

std::vector<relcgrammarParser::ExpContext *> relcgrammarParser::ExpContext::exp() {
  return getRuleContexts<relcgrammarParser::ExpContext>();
}

relcgrammarParser::ExpContext* relcgrammarParser::ExpContext::exp(size_t i) {
  return getRuleContext<relcgrammarParser::ExpContext>(i);
}

tree::TerminalNode* relcgrammarParser::ExpContext::PLUS() {
  return getToken(relcgrammarParser::PLUS, 0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::MINUS() {
  return getToken(relcgrammarParser::MINUS, 0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::MULT() {
  return getToken(relcgrammarParser::MULT, 0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::DIV() {
  return getToken(relcgrammarParser::DIV, 0);
}


size_t relcgrammarParser::ExpContext::getRuleIndex() const {
  return relcgrammarParser::RuleExp;
}


std::any relcgrammarParser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}


relcgrammarParser::ExpContext* relcgrammarParser::exp() {
   return exp(0);
}

relcgrammarParser::ExpContext* relcgrammarParser::exp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  relcgrammarParser::ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, parentState);
  relcgrammarParser::ExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, relcgrammarParser::RuleExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(85);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(68);
      native_call();
      break;
    }

    case 2: {
      setState(69);
      match(relcgrammarParser::ID);
      setState(70);
      match(relcgrammarParser::LPAREN);
      setState(71);
      arguments_list();
      setState(72);
      match(relcgrammarParser::RPAREN);
      break;
    }

    case 3: {
      setState(74);
      match(relcgrammarParser::ID);
      setState(75);
      match(relcgrammarParser::LPAREN);
      setState(76);
      match(relcgrammarParser::RPAREN);
      break;
    }

    case 4: {
      setState(77);
      match(relcgrammarParser::ID);
      break;
    }

    case 5: {
      setState(78);
      match(relcgrammarParser::INT_LITERAL);
      break;
    }

    case 6: {
      setState(79);
      match(relcgrammarParser::FLOAT_LITERAL);
      break;
    }

    case 7: {
      setState(80);
      match(relcgrammarParser::CHAR);
      break;
    }

    case 8: {
      setState(81);
      match(relcgrammarParser::LPAREN);
      setState(82);
      exp(0);
      setState(83);
      match(relcgrammarParser::RPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(101);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(99);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(87);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(88);
          match(relcgrammarParser::PLUS);
          setState(89);
          exp(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(90);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(91);
          match(relcgrammarParser::MINUS);
          setState(92);
          exp(5);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(93);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(94);
          match(relcgrammarParser::MULT);
          setState(95);
          exp(4);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(96);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(97);
          match(relcgrammarParser::DIV);
          setState(98);
          exp(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(103);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Native_callContext ------------------------------------------------------------------

relcgrammarParser::Native_callContext::Native_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* relcgrammarParser::Native_callContext::NATIVE_SCOPE() {
  return getToken(relcgrammarParser::NATIVE_SCOPE, 0);
}

tree::TerminalNode* relcgrammarParser::Native_callContext::ID() {
  return getToken(relcgrammarParser::ID, 0);
}

tree::TerminalNode* relcgrammarParser::Native_callContext::LPAREN() {
  return getToken(relcgrammarParser::LPAREN, 0);
}

tree::TerminalNode* relcgrammarParser::Native_callContext::RPAREN() {
  return getToken(relcgrammarParser::RPAREN, 0);
}

relcgrammarParser::Arguments_listContext* relcgrammarParser::Native_callContext::arguments_list() {
  return getRuleContext<relcgrammarParser::Arguments_listContext>(0);
}


size_t relcgrammarParser::Native_callContext::getRuleIndex() const {
  return relcgrammarParser::RuleNative_call;
}


std::any relcgrammarParser::Native_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitNative_call(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::Native_callContext* relcgrammarParser::native_call() {
  Native_callContext *_localctx = _tracker.createInstance<Native_callContext>(_ctx, getState());
  enterRule(_localctx, 12, relcgrammarParser::RuleNative_call);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    match(relcgrammarParser::NATIVE_SCOPE);
    setState(105);
    match(relcgrammarParser::ID);
    setState(106);
    match(relcgrammarParser::LPAREN);
    setState(108);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << relcgrammarParser::INT_LITERAL)
      | (1ULL << relcgrammarParser::FLOAT_LITERAL)
      | (1ULL << relcgrammarParser::ID)
      | (1ULL << relcgrammarParser::CHAR)
      | (1ULL << relcgrammarParser::LPAREN)
      | (1ULL << relcgrammarParser::NATIVE_SCOPE))) != 0)) {
      setState(107);
      arguments_list();
    }
    setState(110);
    match(relcgrammarParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arguments_listContext ------------------------------------------------------------------

relcgrammarParser::Arguments_listContext::Arguments_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<relcgrammarParser::ExpContext *> relcgrammarParser::Arguments_listContext::exp() {
  return getRuleContexts<relcgrammarParser::ExpContext>();
}

relcgrammarParser::ExpContext* relcgrammarParser::Arguments_listContext::exp(size_t i) {
  return getRuleContext<relcgrammarParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> relcgrammarParser::Arguments_listContext::COMMA() {
  return getTokens(relcgrammarParser::COMMA);
}

tree::TerminalNode* relcgrammarParser::Arguments_listContext::COMMA(size_t i) {
  return getToken(relcgrammarParser::COMMA, i);
}


size_t relcgrammarParser::Arguments_listContext::getRuleIndex() const {
  return relcgrammarParser::RuleArguments_list;
}


std::any relcgrammarParser::Arguments_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitArguments_list(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::Arguments_listContext* relcgrammarParser::arguments_list() {
  Arguments_listContext *_localctx = _tracker.createInstance<Arguments_listContext>(_ctx, getState());
  enterRule(_localctx, 14, relcgrammarParser::RuleArguments_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    exp(0);
    setState(117);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == relcgrammarParser::COMMA) {
      setState(113);
      match(relcgrammarParser::COMMA);
      setState(114);
      exp(0);
      setState(119);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

relcgrammarParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* relcgrammarParser::ParameterContext::TYPE() {
  return getToken(relcgrammarParser::TYPE, 0);
}

tree::TerminalNode* relcgrammarParser::ParameterContext::ID() {
  return getToken(relcgrammarParser::ID, 0);
}


size_t relcgrammarParser::ParameterContext::getRuleIndex() const {
  return relcgrammarParser::RuleParameter;
}


std::any relcgrammarParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::ParameterContext* relcgrammarParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 16, relcgrammarParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(relcgrammarParser::TYPE);
    setState(121);
    match(relcgrammarParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameters_listContext ------------------------------------------------------------------

relcgrammarParser::Parameters_listContext::Parameters_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<relcgrammarParser::ParameterContext *> relcgrammarParser::Parameters_listContext::parameter() {
  return getRuleContexts<relcgrammarParser::ParameterContext>();
}

relcgrammarParser::ParameterContext* relcgrammarParser::Parameters_listContext::parameter(size_t i) {
  return getRuleContext<relcgrammarParser::ParameterContext>(i);
}

std::vector<tree::TerminalNode *> relcgrammarParser::Parameters_listContext::COMMA() {
  return getTokens(relcgrammarParser::COMMA);
}

tree::TerminalNode* relcgrammarParser::Parameters_listContext::COMMA(size_t i) {
  return getToken(relcgrammarParser::COMMA, i);
}


size_t relcgrammarParser::Parameters_listContext::getRuleIndex() const {
  return relcgrammarParser::RuleParameters_list;
}


std::any relcgrammarParser::Parameters_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitParameters_list(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::Parameters_listContext* relcgrammarParser::parameters_list() {
  Parameters_listContext *_localctx = _tracker.createInstance<Parameters_listContext>(_ctx, getState());
  enterRule(_localctx, 18, relcgrammarParser::RuleParameters_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    parameter();
    setState(128);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == relcgrammarParser::COMMA) {
      setState(124);
      match(relcgrammarParser::COMMA);
      setState(125);
      parameter();
      setState(130);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Native_func_prototypeContext ------------------------------------------------------------------

relcgrammarParser::Native_func_prototypeContext::Native_func_prototypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* relcgrammarParser::Native_func_prototypeContext::NativeProtoDecl() {
  return getToken(relcgrammarParser::NativeProtoDecl, 0);
}

tree::TerminalNode* relcgrammarParser::Native_func_prototypeContext::LPAREN() {
  return getToken(relcgrammarParser::LPAREN, 0);
}

tree::TerminalNode* relcgrammarParser::Native_func_prototypeContext::ID() {
  return getToken(relcgrammarParser::ID, 0);
}

tree::TerminalNode* relcgrammarParser::Native_func_prototypeContext::RPAREN() {
  return getToken(relcgrammarParser::RPAREN, 0);
}

relcgrammarParser::Func_prototypeContext* relcgrammarParser::Native_func_prototypeContext::func_prototype() {
  return getRuleContext<relcgrammarParser::Func_prototypeContext>(0);
}


size_t relcgrammarParser::Native_func_prototypeContext::getRuleIndex() const {
  return relcgrammarParser::RuleNative_func_prototype;
}


std::any relcgrammarParser::Native_func_prototypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitNative_func_prototype(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::Native_func_prototypeContext* relcgrammarParser::native_func_prototype() {
  Native_func_prototypeContext *_localctx = _tracker.createInstance<Native_func_prototypeContext>(_ctx, getState());
  enterRule(_localctx, 20, relcgrammarParser::RuleNative_func_prototype);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    match(relcgrammarParser::NativeProtoDecl);
    setState(132);
    match(relcgrammarParser::LPAREN);
    setState(133);
    match(relcgrammarParser::ID);
    setState(134);
    match(relcgrammarParser::RPAREN);
    setState(135);
    func_prototype();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_prototypeContext ------------------------------------------------------------------

relcgrammarParser::Func_prototypeContext::Func_prototypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

relcgrammarParser::Func_declarationContext* relcgrammarParser::Func_prototypeContext::func_declaration() {
  return getRuleContext<relcgrammarParser::Func_declarationContext>(0);
}

tree::TerminalNode* relcgrammarParser::Func_prototypeContext::SEMI() {
  return getToken(relcgrammarParser::SEMI, 0);
}


size_t relcgrammarParser::Func_prototypeContext::getRuleIndex() const {
  return relcgrammarParser::RuleFunc_prototype;
}


std::any relcgrammarParser::Func_prototypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitFunc_prototype(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::Func_prototypeContext* relcgrammarParser::func_prototype() {
  Func_prototypeContext *_localctx = _tracker.createInstance<Func_prototypeContext>(_ctx, getState());
  enterRule(_localctx, 22, relcgrammarParser::RuleFunc_prototype);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    func_declaration();
    setState(138);
    match(relcgrammarParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

relcgrammarParser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* relcgrammarParser::Func_declarationContext::TYPE() {
  return getToken(relcgrammarParser::TYPE, 0);
}

tree::TerminalNode* relcgrammarParser::Func_declarationContext::ID() {
  return getToken(relcgrammarParser::ID, 0);
}

tree::TerminalNode* relcgrammarParser::Func_declarationContext::LPAREN() {
  return getToken(relcgrammarParser::LPAREN, 0);
}

relcgrammarParser::Parameters_listContext* relcgrammarParser::Func_declarationContext::parameters_list() {
  return getRuleContext<relcgrammarParser::Parameters_listContext>(0);
}

tree::TerminalNode* relcgrammarParser::Func_declarationContext::RPAREN() {
  return getToken(relcgrammarParser::RPAREN, 0);
}


size_t relcgrammarParser::Func_declarationContext::getRuleIndex() const {
  return relcgrammarParser::RuleFunc_declaration;
}


std::any relcgrammarParser::Func_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitFunc_declaration(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::Func_declarationContext* relcgrammarParser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 24, relcgrammarParser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(140);
      match(relcgrammarParser::TYPE);
      setState(141);
      match(relcgrammarParser::ID);
      setState(142);
      match(relcgrammarParser::LPAREN);
      setState(143);
      parameters_list();
      setState(144);
      match(relcgrammarParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(146);
      match(relcgrammarParser::TYPE);
      setState(147);
      match(relcgrammarParser::ID);
      setState(148);
      match(relcgrammarParser::LPAREN);
      setState(149);
      match(relcgrammarParser::RPAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

relcgrammarParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<relcgrammarParser::StatementContext *> relcgrammarParser::ScopeContext::statement() {
  return getRuleContexts<relcgrammarParser::StatementContext>();
}

relcgrammarParser::StatementContext* relcgrammarParser::ScopeContext::statement(size_t i) {
  return getRuleContext<relcgrammarParser::StatementContext>(i);
}


size_t relcgrammarParser::ScopeContext::getRuleIndex() const {
  return relcgrammarParser::RuleScope;
}


std::any relcgrammarParser::ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitScope(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::ScopeContext* relcgrammarParser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 26, relcgrammarParser::RuleScope);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(152);
      statement();
      setState(155); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << relcgrammarParser::INT_LITERAL)
      | (1ULL << relcgrammarParser::FLOAT_LITERAL)
      | (1ULL << relcgrammarParser::TYPE)
      | (1ULL << relcgrammarParser::ID)
      | (1ULL << relcgrammarParser::CHAR)
      | (1ULL << relcgrammarParser::LPAREN)
      | (1ULL << relcgrammarParser::NATIVE_SCOPE))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bordered_scopeContext ------------------------------------------------------------------

relcgrammarParser::Bordered_scopeContext::Bordered_scopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* relcgrammarParser::Bordered_scopeContext::LCURL() {
  return getToken(relcgrammarParser::LCURL, 0);
}

relcgrammarParser::ScopeContext* relcgrammarParser::Bordered_scopeContext::scope() {
  return getRuleContext<relcgrammarParser::ScopeContext>(0);
}

tree::TerminalNode* relcgrammarParser::Bordered_scopeContext::RCURL() {
  return getToken(relcgrammarParser::RCURL, 0);
}


size_t relcgrammarParser::Bordered_scopeContext::getRuleIndex() const {
  return relcgrammarParser::RuleBordered_scope;
}


std::any relcgrammarParser::Bordered_scopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitBordered_scope(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::Bordered_scopeContext* relcgrammarParser::bordered_scope() {
  Bordered_scopeContext *_localctx = _tracker.createInstance<Bordered_scopeContext>(_ctx, getState());
  enterRule(_localctx, 28, relcgrammarParser::RuleBordered_scope);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(relcgrammarParser::LCURL);
    setState(158);
    scope();
    setState(159);
    match(relcgrammarParser::RCURL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_scopeContext ------------------------------------------------------------------

relcgrammarParser::Func_scopeContext::Func_scopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

relcgrammarParser::Bordered_scopeContext* relcgrammarParser::Func_scopeContext::bordered_scope() {
  return getRuleContext<relcgrammarParser::Bordered_scopeContext>(0);
}

tree::TerminalNode* relcgrammarParser::Func_scopeContext::LCURL() {
  return getToken(relcgrammarParser::LCURL, 0);
}

tree::TerminalNode* relcgrammarParser::Func_scopeContext::RCURL() {
  return getToken(relcgrammarParser::RCURL, 0);
}


size_t relcgrammarParser::Func_scopeContext::getRuleIndex() const {
  return relcgrammarParser::RuleFunc_scope;
}


std::any relcgrammarParser::Func_scopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitFunc_scope(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::Func_scopeContext* relcgrammarParser::func_scope() {
  Func_scopeContext *_localctx = _tracker.createInstance<Func_scopeContext>(_ctx, getState());
  enterRule(_localctx, 30, relcgrammarParser::RuleFunc_scope);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(164);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(161);
      bordered_scope();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(162);
      match(relcgrammarParser::LCURL);
      setState(163);
      match(relcgrammarParser::RCURL);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_bodyContext ------------------------------------------------------------------

relcgrammarParser::Func_bodyContext::Func_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

relcgrammarParser::Func_declarationContext* relcgrammarParser::Func_bodyContext::func_declaration() {
  return getRuleContext<relcgrammarParser::Func_declarationContext>(0);
}

relcgrammarParser::Func_scopeContext* relcgrammarParser::Func_bodyContext::func_scope() {
  return getRuleContext<relcgrammarParser::Func_scopeContext>(0);
}


size_t relcgrammarParser::Func_bodyContext::getRuleIndex() const {
  return relcgrammarParser::RuleFunc_body;
}


std::any relcgrammarParser::Func_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitFunc_body(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::Func_bodyContext* relcgrammarParser::func_body() {
  Func_bodyContext *_localctx = _tracker.createInstance<Func_bodyContext>(_ctx, getState());
  enterRule(_localctx, 32, relcgrammarParser::RuleFunc_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    func_declaration();
    setState(167);
    func_scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool relcgrammarParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return expSempred(antlrcpp::downCast<ExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool relcgrammarParser::expSempred(ExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);
    case 3: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void relcgrammarParser::initialize() {
  std::call_once(relcgrammarParserOnceFlag, relcgrammarParserInitialize);
}
