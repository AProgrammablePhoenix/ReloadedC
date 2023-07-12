
// Generated from src/antlr_grammar/relcgrammar.g4 by ANTLR 4.13.0


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

::antlr4::internal::OnceFlag relcgrammarParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
RelcgrammarParserStaticData *relcgrammarParserStaticData = nullptr;

void relcgrammarParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (relcgrammarParserStaticData != nullptr) {
    return;
  }
#else
  assert(relcgrammarParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<RelcgrammarParserStaticData>(
    std::vector<std::string>{
      "plain_type", "pointer_type", "type", "program", "global_statement", 
      "statement", "assignment", "initialization", "exp", "native_call", 
      "arguments_list", "parameter", "parameters_list", "native_func_prototype", 
      "func_prototype", "func_declaration", "scope", "bordered_scope", "func_scope", 
      "func_body"
    },
    std::vector<std::string>{
      "", "'&'", "", "", "", "", "'const'", "'__nativedecl'", "", "", "", 
      "'+'", "'-'", "'*'", "'/'", "'='", "';'", "','", "'('", "')'", "'{'", 
      "'}'", "'::'"
    },
    std::vector<std::string>{
      "", "", "LONG_LITERAL", "INT_LITERAL", "FLOAT_LITERAL", "INTERNAL_TYPE", 
      "CONST", "NativeProtoDecl", "ID", "CHAR", "STRING", "PLUS", "MINUS", 
      "MULT", "DIV", "EQUAL", "SEMI", "COMMA", "LPAREN", "RPAREN", "LCURL", 
      "RCURL", "NATIVE_SCOPE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,23,214,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,1,0,1,0,1,0,
  	1,0,3,0,46,8,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,56,8,1,1,1,1,1,1,1,
  	1,1,1,1,5,1,63,8,1,10,1,12,1,66,9,1,1,2,1,2,3,2,70,8,2,1,3,4,3,73,8,3,
  	11,3,12,3,74,1,4,1,4,1,4,3,4,80,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,3,5,94,8,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,8,3,8,129,8,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,5,8,143,8,8,10,8,12,8,146,9,8,1,9,1,9,1,9,1,9,3,9,152,8,9,1,9,
  	1,9,1,10,1,10,1,10,5,10,159,8,10,10,10,12,10,162,9,10,1,11,1,11,1,11,
  	1,12,1,12,1,12,5,12,170,8,12,10,12,12,12,173,9,12,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,3,15,195,8,15,1,16,4,16,198,8,16,11,16,12,16,199,1,17,1,17,
  	1,17,1,17,1,18,1,18,1,18,3,18,209,8,18,1,19,1,19,1,19,1,19,0,2,2,16,20,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,0,0,228,0,45,1,
  	0,0,0,2,55,1,0,0,0,4,69,1,0,0,0,6,72,1,0,0,0,8,79,1,0,0,0,10,93,1,0,0,
  	0,12,95,1,0,0,0,14,99,1,0,0,0,16,128,1,0,0,0,18,147,1,0,0,0,20,155,1,
  	0,0,0,22,163,1,0,0,0,24,166,1,0,0,0,26,174,1,0,0,0,28,180,1,0,0,0,30,
  	194,1,0,0,0,32,197,1,0,0,0,34,201,1,0,0,0,36,208,1,0,0,0,38,210,1,0,0,
  	0,40,41,5,6,0,0,41,46,5,5,0,0,42,43,5,5,0,0,43,46,5,6,0,0,44,46,5,5,0,
  	0,45,40,1,0,0,0,45,42,1,0,0,0,45,44,1,0,0,0,46,1,1,0,0,0,47,48,6,1,-1,
  	0,48,49,3,0,0,0,49,50,5,13,0,0,50,51,5,6,0,0,51,56,1,0,0,0,52,53,3,0,
  	0,0,53,54,5,13,0,0,54,56,1,0,0,0,55,47,1,0,0,0,55,52,1,0,0,0,56,64,1,
  	0,0,0,57,58,10,4,0,0,58,59,5,13,0,0,59,63,5,6,0,0,60,61,10,3,0,0,61,63,
  	5,13,0,0,62,57,1,0,0,0,62,60,1,0,0,0,63,66,1,0,0,0,64,62,1,0,0,0,64,65,
  	1,0,0,0,65,3,1,0,0,0,66,64,1,0,0,0,67,70,3,2,1,0,68,70,3,0,0,0,69,67,
  	1,0,0,0,69,68,1,0,0,0,70,5,1,0,0,0,71,73,3,8,4,0,72,71,1,0,0,0,73,74,
  	1,0,0,0,74,72,1,0,0,0,74,75,1,0,0,0,75,7,1,0,0,0,76,80,3,26,13,0,77,80,
  	3,28,14,0,78,80,3,38,19,0,79,76,1,0,0,0,79,77,1,0,0,0,79,78,1,0,0,0,80,
  	9,1,0,0,0,81,82,3,12,6,0,82,83,5,16,0,0,83,94,1,0,0,0,84,85,3,14,7,0,
  	85,86,5,16,0,0,86,94,1,0,0,0,87,88,3,16,8,0,88,89,5,16,0,0,89,94,1,0,
  	0,0,90,94,3,12,6,0,91,94,3,14,7,0,92,94,3,16,8,0,93,81,1,0,0,0,93,84,
  	1,0,0,0,93,87,1,0,0,0,93,90,1,0,0,0,93,91,1,0,0,0,93,92,1,0,0,0,94,11,
  	1,0,0,0,95,96,5,8,0,0,96,97,5,15,0,0,97,98,3,16,8,0,98,13,1,0,0,0,99,
  	100,3,4,2,0,100,101,5,8,0,0,101,102,5,15,0,0,102,103,3,16,8,0,103,15,
  	1,0,0,0,104,105,6,8,-1,0,105,106,5,18,0,0,106,107,3,16,8,0,107,108,5,
  	19,0,0,108,129,1,0,0,0,109,110,5,13,0,0,110,129,3,16,8,11,111,112,5,1,
  	0,0,112,129,5,8,0,0,113,129,3,18,9,0,114,115,5,8,0,0,115,116,5,18,0,0,
  	116,117,3,20,10,0,117,118,5,19,0,0,118,129,1,0,0,0,119,120,5,8,0,0,120,
  	121,5,18,0,0,121,129,5,19,0,0,122,129,5,8,0,0,123,129,5,2,0,0,124,129,
  	5,3,0,0,125,129,5,4,0,0,126,129,5,9,0,0,127,129,5,10,0,0,128,104,1,0,
  	0,0,128,109,1,0,0,0,128,111,1,0,0,0,128,113,1,0,0,0,128,114,1,0,0,0,128,
  	119,1,0,0,0,128,122,1,0,0,0,128,123,1,0,0,0,128,124,1,0,0,0,128,125,1,
  	0,0,0,128,126,1,0,0,0,128,127,1,0,0,0,129,144,1,0,0,0,130,131,10,15,0,
  	0,131,132,5,13,0,0,132,143,3,16,8,16,133,134,10,14,0,0,134,135,5,14,0,
  	0,135,143,3,16,8,15,136,137,10,13,0,0,137,138,5,11,0,0,138,143,3,16,8,
  	14,139,140,10,12,0,0,140,141,5,12,0,0,141,143,3,16,8,13,142,130,1,0,0,
  	0,142,133,1,0,0,0,142,136,1,0,0,0,142,139,1,0,0,0,143,146,1,0,0,0,144,
  	142,1,0,0,0,144,145,1,0,0,0,145,17,1,0,0,0,146,144,1,0,0,0,147,148,5,
  	22,0,0,148,149,5,8,0,0,149,151,5,18,0,0,150,152,3,20,10,0,151,150,1,0,
  	0,0,151,152,1,0,0,0,152,153,1,0,0,0,153,154,5,19,0,0,154,19,1,0,0,0,155,
  	160,3,16,8,0,156,157,5,17,0,0,157,159,3,16,8,0,158,156,1,0,0,0,159,162,
  	1,0,0,0,160,158,1,0,0,0,160,161,1,0,0,0,161,21,1,0,0,0,162,160,1,0,0,
  	0,163,164,3,4,2,0,164,165,5,8,0,0,165,23,1,0,0,0,166,171,3,22,11,0,167,
  	168,5,17,0,0,168,170,3,22,11,0,169,167,1,0,0,0,170,173,1,0,0,0,171,169,
  	1,0,0,0,171,172,1,0,0,0,172,25,1,0,0,0,173,171,1,0,0,0,174,175,5,7,0,
  	0,175,176,5,18,0,0,176,177,5,8,0,0,177,178,5,19,0,0,178,179,3,28,14,0,
  	179,27,1,0,0,0,180,181,3,30,15,0,181,182,5,16,0,0,182,29,1,0,0,0,183,
  	184,3,4,2,0,184,185,5,8,0,0,185,186,5,18,0,0,186,187,3,24,12,0,187,188,
  	5,19,0,0,188,195,1,0,0,0,189,190,3,4,2,0,190,191,5,8,0,0,191,192,5,18,
  	0,0,192,193,5,19,0,0,193,195,1,0,0,0,194,183,1,0,0,0,194,189,1,0,0,0,
  	195,31,1,0,0,0,196,198,3,10,5,0,197,196,1,0,0,0,198,199,1,0,0,0,199,197,
  	1,0,0,0,199,200,1,0,0,0,200,33,1,0,0,0,201,202,5,20,0,0,202,203,3,32,
  	16,0,203,204,5,21,0,0,204,35,1,0,0,0,205,209,3,34,17,0,206,207,5,20,0,
  	0,207,209,5,21,0,0,208,205,1,0,0,0,208,206,1,0,0,0,209,37,1,0,0,0,210,
  	211,3,30,15,0,211,212,3,36,18,0,212,39,1,0,0,0,17,45,55,62,64,69,74,79,
  	93,128,142,144,151,160,171,194,199,208
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


//----------------- Plain_typeContext ------------------------------------------------------------------

relcgrammarParser::Plain_typeContext::Plain_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* relcgrammarParser::Plain_typeContext::CONST() {
  return getToken(relcgrammarParser::CONST, 0);
}

tree::TerminalNode* relcgrammarParser::Plain_typeContext::INTERNAL_TYPE() {
  return getToken(relcgrammarParser::INTERNAL_TYPE, 0);
}


size_t relcgrammarParser::Plain_typeContext::getRuleIndex() const {
  return relcgrammarParser::RulePlain_type;
}


std::any relcgrammarParser::Plain_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitPlain_type(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::Plain_typeContext* relcgrammarParser::plain_type() {
  Plain_typeContext *_localctx = _tracker.createInstance<Plain_typeContext>(_ctx, getState());
  enterRule(_localctx, 0, relcgrammarParser::RulePlain_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(45);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(40);
      match(relcgrammarParser::CONST);
      setState(41);
      match(relcgrammarParser::INTERNAL_TYPE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(42);
      match(relcgrammarParser::INTERNAL_TYPE);
      setState(43);
      match(relcgrammarParser::CONST);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(44);
      match(relcgrammarParser::INTERNAL_TYPE);
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

//----------------- Pointer_typeContext ------------------------------------------------------------------

relcgrammarParser::Pointer_typeContext::Pointer_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

relcgrammarParser::Plain_typeContext* relcgrammarParser::Pointer_typeContext::plain_type() {
  return getRuleContext<relcgrammarParser::Plain_typeContext>(0);
}

tree::TerminalNode* relcgrammarParser::Pointer_typeContext::MULT() {
  return getToken(relcgrammarParser::MULT, 0);
}

tree::TerminalNode* relcgrammarParser::Pointer_typeContext::CONST() {
  return getToken(relcgrammarParser::CONST, 0);
}

relcgrammarParser::Pointer_typeContext* relcgrammarParser::Pointer_typeContext::pointer_type() {
  return getRuleContext<relcgrammarParser::Pointer_typeContext>(0);
}


size_t relcgrammarParser::Pointer_typeContext::getRuleIndex() const {
  return relcgrammarParser::RulePointer_type;
}


std::any relcgrammarParser::Pointer_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitPointer_type(this);
  else
    return visitor->visitChildren(this);
}


relcgrammarParser::Pointer_typeContext* relcgrammarParser::pointer_type() {
   return pointer_type(0);
}

relcgrammarParser::Pointer_typeContext* relcgrammarParser::pointer_type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  relcgrammarParser::Pointer_typeContext *_localctx = _tracker.createInstance<Pointer_typeContext>(_ctx, parentState);
  relcgrammarParser::Pointer_typeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, relcgrammarParser::RulePointer_type, precedence);

    

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
    setState(55);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(48);
      plain_type();
      setState(49);
      match(relcgrammarParser::MULT);
      setState(50);
      match(relcgrammarParser::CONST);
      break;
    }

    case 2: {
      setState(52);
      plain_type();
      setState(53);
      match(relcgrammarParser::MULT);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(64);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(62);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Pointer_typeContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePointer_type);
          setState(57);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(58);
          match(relcgrammarParser::MULT);
          setState(59);
          match(relcgrammarParser::CONST);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Pointer_typeContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePointer_type);
          setState(60);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(61);
          match(relcgrammarParser::MULT);
          break;
        }

        default:
          break;
        } 
      }
      setState(66);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

relcgrammarParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

relcgrammarParser::Pointer_typeContext* relcgrammarParser::TypeContext::pointer_type() {
  return getRuleContext<relcgrammarParser::Pointer_typeContext>(0);
}

relcgrammarParser::Plain_typeContext* relcgrammarParser::TypeContext::plain_type() {
  return getRuleContext<relcgrammarParser::Plain_typeContext>(0);
}


size_t relcgrammarParser::TypeContext::getRuleIndex() const {
  return relcgrammarParser::RuleType;
}


std::any relcgrammarParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<relcgrammarVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

relcgrammarParser::TypeContext* relcgrammarParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 4, relcgrammarParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(69);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(67);
      pointer_type(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(68);
      plain_type();
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
  enterRule(_localctx, 6, relcgrammarParser::RuleProgram);
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
    setState(72); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(71);
      global_statement();
      setState(74); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 224) != 0));
   
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
  enterRule(_localctx, 8, relcgrammarParser::RuleGlobal_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(79);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(76);
      native_func_prototype();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(77);
      func_prototype();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(78);
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
  enterRule(_localctx, 10, relcgrammarParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(81);
      assignment();
      setState(82);
      match(relcgrammarParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(84);
      initialization();
      setState(85);
      match(relcgrammarParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(87);
      exp(0);
      setState(88);
      match(relcgrammarParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(90);
      assignment();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(91);
      initialization();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(92);
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
  enterRule(_localctx, 12, relcgrammarParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(relcgrammarParser::ID);
    setState(96);
    match(relcgrammarParser::EQUAL);
    setState(97);
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

relcgrammarParser::TypeContext* relcgrammarParser::InitializationContext::type() {
  return getRuleContext<relcgrammarParser::TypeContext>(0);
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
  enterRule(_localctx, 14, relcgrammarParser::RuleInitialization);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    type();
    setState(100);
    match(relcgrammarParser::ID);
    setState(101);
    match(relcgrammarParser::EQUAL);
    setState(102);
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

tree::TerminalNode* relcgrammarParser::ExpContext::LPAREN() {
  return getToken(relcgrammarParser::LPAREN, 0);
}

std::vector<relcgrammarParser::ExpContext *> relcgrammarParser::ExpContext::exp() {
  return getRuleContexts<relcgrammarParser::ExpContext>();
}

relcgrammarParser::ExpContext* relcgrammarParser::ExpContext::exp(size_t i) {
  return getRuleContext<relcgrammarParser::ExpContext>(i);
}

tree::TerminalNode* relcgrammarParser::ExpContext::RPAREN() {
  return getToken(relcgrammarParser::RPAREN, 0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::MULT() {
  return getToken(relcgrammarParser::MULT, 0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::ID() {
  return getToken(relcgrammarParser::ID, 0);
}

relcgrammarParser::Native_callContext* relcgrammarParser::ExpContext::native_call() {
  return getRuleContext<relcgrammarParser::Native_callContext>(0);
}

relcgrammarParser::Arguments_listContext* relcgrammarParser::ExpContext::arguments_list() {
  return getRuleContext<relcgrammarParser::Arguments_listContext>(0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::LONG_LITERAL() {
  return getToken(relcgrammarParser::LONG_LITERAL, 0);
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

tree::TerminalNode* relcgrammarParser::ExpContext::STRING() {
  return getToken(relcgrammarParser::STRING, 0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::DIV() {
  return getToken(relcgrammarParser::DIV, 0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::PLUS() {
  return getToken(relcgrammarParser::PLUS, 0);
}

tree::TerminalNode* relcgrammarParser::ExpContext::MINUS() {
  return getToken(relcgrammarParser::MINUS, 0);
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
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, relcgrammarParser::RuleExp, precedence);

    

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
    setState(128);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(105);
      match(relcgrammarParser::LPAREN);
      setState(106);
      exp(0);
      setState(107);
      match(relcgrammarParser::RPAREN);
      break;
    }

    case 2: {
      setState(109);
      antlrcpp::downCast<ExpContext *>(_localctx)->ptrderef = match(relcgrammarParser::MULT);
      setState(110);
      exp(11);
      break;
    }

    case 3: {
      setState(111);
      antlrcpp::downCast<ExpContext *>(_localctx)->ptrgetref = match(relcgrammarParser::T__0);
      setState(112);
      match(relcgrammarParser::ID);
      break;
    }

    case 4: {
      setState(113);
      native_call();
      break;
    }

    case 5: {
      setState(114);
      match(relcgrammarParser::ID);
      setState(115);
      match(relcgrammarParser::LPAREN);
      setState(116);
      arguments_list();
      setState(117);
      match(relcgrammarParser::RPAREN);
      break;
    }

    case 6: {
      setState(119);
      match(relcgrammarParser::ID);
      setState(120);
      match(relcgrammarParser::LPAREN);
      setState(121);
      match(relcgrammarParser::RPAREN);
      break;
    }

    case 7: {
      setState(122);
      match(relcgrammarParser::ID);
      break;
    }

    case 8: {
      setState(123);
      match(relcgrammarParser::LONG_LITERAL);
      break;
    }

    case 9: {
      setState(124);
      match(relcgrammarParser::INT_LITERAL);
      break;
    }

    case 10: {
      setState(125);
      match(relcgrammarParser::FLOAT_LITERAL);
      break;
    }

    case 11: {
      setState(126);
      match(relcgrammarParser::CHAR);
      break;
    }

    case 12: {
      setState(127);
      match(relcgrammarParser::STRING);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(144);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(142);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(130);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(131);
          match(relcgrammarParser::MULT);
          setState(132);
          exp(16);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(133);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(134);
          match(relcgrammarParser::DIV);
          setState(135);
          exp(15);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(136);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(137);
          match(relcgrammarParser::PLUS);
          setState(138);
          exp(14);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(139);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(140);
          match(relcgrammarParser::MINUS);
          setState(141);
          exp(13);
          break;
        }

        default:
          break;
        } 
      }
      setState(146);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
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
  enterRule(_localctx, 18, relcgrammarParser::RuleNative_call);
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
    setState(147);
    match(relcgrammarParser::NATIVE_SCOPE);
    setState(148);
    match(relcgrammarParser::ID);
    setState(149);
    match(relcgrammarParser::LPAREN);
    setState(151);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4466462) != 0)) {
      setState(150);
      arguments_list();
    }
    setState(153);
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
  enterRule(_localctx, 20, relcgrammarParser::RuleArguments_list);
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
    setState(155);
    exp(0);
    setState(160);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == relcgrammarParser::COMMA) {
      setState(156);
      match(relcgrammarParser::COMMA);
      setState(157);
      exp(0);
      setState(162);
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

relcgrammarParser::TypeContext* relcgrammarParser::ParameterContext::type() {
  return getRuleContext<relcgrammarParser::TypeContext>(0);
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
  enterRule(_localctx, 22, relcgrammarParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    type();
    setState(164);
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
  enterRule(_localctx, 24, relcgrammarParser::RuleParameters_list);
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
    setState(166);
    parameter();
    setState(171);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == relcgrammarParser::COMMA) {
      setState(167);
      match(relcgrammarParser::COMMA);
      setState(168);
      parameter();
      setState(173);
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
  enterRule(_localctx, 26, relcgrammarParser::RuleNative_func_prototype);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(relcgrammarParser::NativeProtoDecl);
    setState(175);
    match(relcgrammarParser::LPAREN);
    setState(176);
    match(relcgrammarParser::ID);
    setState(177);
    match(relcgrammarParser::RPAREN);
    setState(178);
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
  enterRule(_localctx, 28, relcgrammarParser::RuleFunc_prototype);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    func_declaration();
    setState(181);
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

relcgrammarParser::TypeContext* relcgrammarParser::Func_declarationContext::type() {
  return getRuleContext<relcgrammarParser::TypeContext>(0);
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
  enterRule(_localctx, 30, relcgrammarParser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(194);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(183);
      type();
      setState(184);
      match(relcgrammarParser::ID);
      setState(185);
      match(relcgrammarParser::LPAREN);
      setState(186);
      parameters_list();
      setState(187);
      match(relcgrammarParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(189);
      type();
      setState(190);
      match(relcgrammarParser::ID);
      setState(191);
      match(relcgrammarParser::LPAREN);
      setState(192);
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
  enterRule(_localctx, 32, relcgrammarParser::RuleScope);
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
    setState(197); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(196);
      statement();
      setState(199); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4466558) != 0));
   
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
  enterRule(_localctx, 34, relcgrammarParser::RuleBordered_scope);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(relcgrammarParser::LCURL);
    setState(202);
    scope();
    setState(203);
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
  enterRule(_localctx, 36, relcgrammarParser::RuleFunc_scope);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(208);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(205);
      bordered_scope();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(206);
      match(relcgrammarParser::LCURL);
      setState(207);
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
  enterRule(_localctx, 38, relcgrammarParser::RuleFunc_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    func_declaration();
    setState(211);
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
    case 1: return pointer_typeSempred(antlrcpp::downCast<Pointer_typeContext *>(context), predicateIndex);
    case 8: return expSempred(antlrcpp::downCast<ExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool relcgrammarParser::pointer_typeSempred(Pointer_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool relcgrammarParser::expSempred(ExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 15);
    case 3: return precpred(_ctx, 14);
    case 4: return precpred(_ctx, 13);
    case 5: return precpred(_ctx, 12);

  default:
    break;
  }
  return true;
}

void relcgrammarParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  relcgrammarParserInitialize();
#else
  ::antlr4::internal::call_once(relcgrammarParserOnceFlag, relcgrammarParserInitialize);
#endif
}
