
// Generated from src/antlr_grammar/relcgrammar.g4 by ANTLR 4.13.0


#include "relcgrammarLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct RelcgrammarLexerStaticData final {
  RelcgrammarLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  RelcgrammarLexerStaticData(const RelcgrammarLexerStaticData&) = delete;
  RelcgrammarLexerStaticData(RelcgrammarLexerStaticData&&) = delete;
  RelcgrammarLexerStaticData& operator=(const RelcgrammarLexerStaticData&) = delete;
  RelcgrammarLexerStaticData& operator=(RelcgrammarLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag relcgrammarlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
RelcgrammarLexerStaticData *relcgrammarlexerLexerStaticData = nullptr;

void relcgrammarlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (relcgrammarlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(relcgrammarlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<RelcgrammarLexerStaticData>(
    std::vector<std::string>{
      "T__0", "LONG_LITERAL", "INT_LITERAL", "FLOAT_LITERAL", "INTERNAL_TYPE", 
      "CONST", "NativeProtoDecl", "ID", "ESC", "CHAR", "STRING", "PLUS", 
      "MINUS", "MULT", "DIV", "EQUAL", "SEMI", "COMMA", "LPAREN", "RPAREN", 
      "LCURL", "RCURL", "NATIVE_SCOPE", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,23,192,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,1,0,1,0,1,1,3,1,53,8,1,1,1,4,1,56,8,1,11,1,12,
  	1,57,1,1,3,1,61,8,1,1,1,1,1,3,1,65,8,1,1,2,3,2,68,8,2,1,2,4,2,71,8,2,
  	11,2,12,2,72,1,2,3,2,76,8,2,1,3,4,3,79,8,3,11,3,12,3,80,1,3,1,3,4,3,85,
  	8,3,11,3,12,3,86,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,113,8,4,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,
  	5,7,136,8,7,10,7,12,7,139,9,7,1,8,1,8,1,8,1,9,1,9,1,9,3,9,147,8,9,1,9,
  	1,9,1,10,1,10,1,10,5,10,154,8,10,10,10,12,10,157,9,10,1,10,1,10,1,11,
  	1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,
  	1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,22,1,23,4,23,187,8,23,
  	11,23,12,23,188,1,23,1,23,1,155,0,24,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,
  	8,17,0,19,9,21,10,23,11,25,12,27,13,29,14,31,15,33,16,35,17,37,18,39,
  	19,41,20,43,21,45,22,47,23,1,0,5,2,0,43,43,45,45,1,0,48,57,3,0,65,90,
  	95,95,97,122,4,0,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,208,0,
  	1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,
  	0,0,13,1,0,0,0,0,15,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,
  	25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,
  	0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,
  	0,0,47,1,0,0,0,1,49,1,0,0,0,3,52,1,0,0,0,5,67,1,0,0,0,7,78,1,0,0,0,9,
  	112,1,0,0,0,11,114,1,0,0,0,13,120,1,0,0,0,15,133,1,0,0,0,17,140,1,0,0,
  	0,19,143,1,0,0,0,21,150,1,0,0,0,23,160,1,0,0,0,25,162,1,0,0,0,27,164,
  	1,0,0,0,29,166,1,0,0,0,31,168,1,0,0,0,33,170,1,0,0,0,35,172,1,0,0,0,37,
  	174,1,0,0,0,39,176,1,0,0,0,41,178,1,0,0,0,43,180,1,0,0,0,45,182,1,0,0,
  	0,47,186,1,0,0,0,49,50,5,38,0,0,50,2,1,0,0,0,51,53,7,0,0,0,52,51,1,0,
  	0,0,52,53,1,0,0,0,53,55,1,0,0,0,54,56,7,1,0,0,55,54,1,0,0,0,56,57,1,0,
  	0,0,57,55,1,0,0,0,57,58,1,0,0,0,58,60,1,0,0,0,59,61,5,85,0,0,60,59,1,
  	0,0,0,60,61,1,0,0,0,61,62,1,0,0,0,62,64,5,76,0,0,63,65,5,76,0,0,64,63,
  	1,0,0,0,64,65,1,0,0,0,65,4,1,0,0,0,66,68,7,0,0,0,67,66,1,0,0,0,67,68,
  	1,0,0,0,68,70,1,0,0,0,69,71,7,1,0,0,70,69,1,0,0,0,71,72,1,0,0,0,72,70,
  	1,0,0,0,72,73,1,0,0,0,73,75,1,0,0,0,74,76,5,85,0,0,75,74,1,0,0,0,75,76,
  	1,0,0,0,76,6,1,0,0,0,77,79,7,1,0,0,78,77,1,0,0,0,79,80,1,0,0,0,80,78,
  	1,0,0,0,80,81,1,0,0,0,81,82,1,0,0,0,82,84,9,0,0,0,83,85,7,1,0,0,84,83,
  	1,0,0,0,85,86,1,0,0,0,86,84,1,0,0,0,86,87,1,0,0,0,87,8,1,0,0,0,88,89,
  	5,118,0,0,89,90,5,111,0,0,90,91,5,105,0,0,91,113,5,100,0,0,92,93,5,99,
  	0,0,93,94,5,104,0,0,94,95,5,97,0,0,95,113,5,114,0,0,96,97,5,105,0,0,97,
  	98,5,110,0,0,98,113,5,116,0,0,99,100,5,108,0,0,100,101,5,111,0,0,101,
  	102,5,110,0,0,102,103,5,103,0,0,103,104,5,32,0,0,104,105,5,108,0,0,105,
  	106,5,111,0,0,106,107,5,110,0,0,107,113,5,103,0,0,108,109,5,108,0,0,109,
  	110,5,111,0,0,110,111,5,110,0,0,111,113,5,103,0,0,112,88,1,0,0,0,112,
  	92,1,0,0,0,112,96,1,0,0,0,112,99,1,0,0,0,112,108,1,0,0,0,113,10,1,0,0,
  	0,114,115,5,99,0,0,115,116,5,111,0,0,116,117,5,110,0,0,117,118,5,115,
  	0,0,118,119,5,116,0,0,119,12,1,0,0,0,120,121,5,95,0,0,121,122,5,95,0,
  	0,122,123,5,110,0,0,123,124,5,97,0,0,124,125,5,116,0,0,125,126,5,105,
  	0,0,126,127,5,118,0,0,127,128,5,101,0,0,128,129,5,100,0,0,129,130,5,101,
  	0,0,130,131,5,99,0,0,131,132,5,108,0,0,132,14,1,0,0,0,133,137,7,2,0,0,
  	134,136,7,3,0,0,135,134,1,0,0,0,136,139,1,0,0,0,137,135,1,0,0,0,137,138,
  	1,0,0,0,138,16,1,0,0,0,139,137,1,0,0,0,140,141,5,92,0,0,141,142,9,0,0,
  	0,142,18,1,0,0,0,143,146,5,39,0,0,144,147,3,17,8,0,145,147,9,0,0,0,146,
  	144,1,0,0,0,146,145,1,0,0,0,147,148,1,0,0,0,148,149,5,39,0,0,149,20,1,
  	0,0,0,150,155,5,34,0,0,151,154,3,17,8,0,152,154,9,0,0,0,153,151,1,0,0,
  	0,153,152,1,0,0,0,154,157,1,0,0,0,155,156,1,0,0,0,155,153,1,0,0,0,156,
  	158,1,0,0,0,157,155,1,0,0,0,158,159,5,34,0,0,159,22,1,0,0,0,160,161,5,
  	43,0,0,161,24,1,0,0,0,162,163,5,45,0,0,163,26,1,0,0,0,164,165,5,42,0,
  	0,165,28,1,0,0,0,166,167,5,47,0,0,167,30,1,0,0,0,168,169,5,61,0,0,169,
  	32,1,0,0,0,170,171,5,59,0,0,171,34,1,0,0,0,172,173,5,44,0,0,173,36,1,
  	0,0,0,174,175,5,40,0,0,175,38,1,0,0,0,176,177,5,41,0,0,177,40,1,0,0,0,
  	178,179,5,123,0,0,179,42,1,0,0,0,180,181,5,125,0,0,181,44,1,0,0,0,182,
  	183,5,58,0,0,183,184,5,58,0,0,184,46,1,0,0,0,185,187,7,4,0,0,186,185,
  	1,0,0,0,187,188,1,0,0,0,188,186,1,0,0,0,188,189,1,0,0,0,189,190,1,0,0,
  	0,190,191,6,23,0,0,191,48,1,0,0,0,16,0,52,57,60,64,67,72,75,80,86,112,
  	137,146,153,155,188,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  relcgrammarlexerLexerStaticData = staticData.release();
}

}

relcgrammarLexer::relcgrammarLexer(CharStream *input) : Lexer(input) {
  relcgrammarLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *relcgrammarlexerLexerStaticData->atn, relcgrammarlexerLexerStaticData->decisionToDFA, relcgrammarlexerLexerStaticData->sharedContextCache);
}

relcgrammarLexer::~relcgrammarLexer() {
  delete _interpreter;
}

std::string relcgrammarLexer::getGrammarFileName() const {
  return "relcgrammar.g4";
}

const std::vector<std::string>& relcgrammarLexer::getRuleNames() const {
  return relcgrammarlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& relcgrammarLexer::getChannelNames() const {
  return relcgrammarlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& relcgrammarLexer::getModeNames() const {
  return relcgrammarlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& relcgrammarLexer::getVocabulary() const {
  return relcgrammarlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView relcgrammarLexer::getSerializedATN() const {
  return relcgrammarlexerLexerStaticData->serializedATN;
}

const atn::ATN& relcgrammarLexer::getATN() const {
  return *relcgrammarlexerLexerStaticData->atn;
}




void relcgrammarLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  relcgrammarlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(relcgrammarlexerLexerOnceFlag, relcgrammarlexerLexerInitialize);
#endif
}
