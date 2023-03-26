
// Generated from src/antlr_grammar/relcgrammar.g4 by ANTLR 4.10.1


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

std::once_flag relcgrammarlexerLexerOnceFlag;
RelcgrammarLexerStaticData *relcgrammarlexerLexerStaticData = nullptr;

void relcgrammarlexerLexerInitialize() {
  assert(relcgrammarlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<RelcgrammarLexerStaticData>(
    std::vector<std::string>{
      "INT_LITERAL", "FLOAT_LITERAL", "TYPE", "NativeProtoDecl", "ID", "CHAR", 
      "PLUS", "MINUS", "MULT", "DIV", "EQUAL", "SEMI", "COMMA", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "NATIVE_SCOPE", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,19,128,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,4,0,41,8,0,11,0,12,0,
  	42,1,1,4,1,46,8,1,11,1,12,1,47,1,1,1,1,4,1,52,8,1,11,1,12,1,53,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,71,8,2,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,5,4,88,8,4,10,
  	4,12,4,91,9,4,1,5,1,5,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,
  	10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,
  	17,1,17,1,18,4,18,123,8,18,11,18,12,18,124,1,18,1,18,0,0,19,1,1,3,2,5,
  	3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,
  	16,33,17,35,18,37,19,1,0,4,1,0,48,57,3,0,65,90,95,95,97,122,4,0,48,57,
  	65,90,95,95,97,122,3,0,9,10,13,13,32,32,135,0,1,1,0,0,0,0,3,1,0,0,0,0,
  	5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,
  	0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,
  	0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,
  	1,0,0,0,1,40,1,0,0,0,3,45,1,0,0,0,5,70,1,0,0,0,7,72,1,0,0,0,9,85,1,0,
  	0,0,11,92,1,0,0,0,13,96,1,0,0,0,15,98,1,0,0,0,17,100,1,0,0,0,19,102,1,
  	0,0,0,21,104,1,0,0,0,23,106,1,0,0,0,25,108,1,0,0,0,27,110,1,0,0,0,29,
  	112,1,0,0,0,31,114,1,0,0,0,33,116,1,0,0,0,35,118,1,0,0,0,37,122,1,0,0,
  	0,39,41,7,0,0,0,40,39,1,0,0,0,41,42,1,0,0,0,42,40,1,0,0,0,42,43,1,0,0,
  	0,43,2,1,0,0,0,44,46,7,0,0,0,45,44,1,0,0,0,46,47,1,0,0,0,47,45,1,0,0,
  	0,47,48,1,0,0,0,48,49,1,0,0,0,49,51,9,0,0,0,50,52,7,0,0,0,51,50,1,0,0,
  	0,52,53,1,0,0,0,53,51,1,0,0,0,53,54,1,0,0,0,54,4,1,0,0,0,55,56,5,118,
  	0,0,56,57,5,111,0,0,57,58,5,105,0,0,58,71,5,100,0,0,59,60,5,99,0,0,60,
  	61,5,104,0,0,61,62,5,97,0,0,62,71,5,114,0,0,63,64,5,105,0,0,64,65,5,110,
  	0,0,65,71,5,116,0,0,66,67,5,108,0,0,67,68,5,111,0,0,68,69,5,110,0,0,69,
  	71,5,103,0,0,70,55,1,0,0,0,70,59,1,0,0,0,70,63,1,0,0,0,70,66,1,0,0,0,
  	71,6,1,0,0,0,72,73,5,95,0,0,73,74,5,95,0,0,74,75,5,110,0,0,75,76,5,97,
  	0,0,76,77,5,116,0,0,77,78,5,105,0,0,78,79,5,118,0,0,79,80,5,101,0,0,80,
  	81,5,100,0,0,81,82,5,101,0,0,82,83,5,99,0,0,83,84,5,108,0,0,84,8,1,0,
  	0,0,85,89,7,1,0,0,86,88,7,2,0,0,87,86,1,0,0,0,88,91,1,0,0,0,89,87,1,0,
  	0,0,89,90,1,0,0,0,90,10,1,0,0,0,91,89,1,0,0,0,92,93,5,39,0,0,93,94,9,
  	0,0,0,94,95,5,39,0,0,95,12,1,0,0,0,96,97,5,43,0,0,97,14,1,0,0,0,98,99,
  	5,45,0,0,99,16,1,0,0,0,100,101,5,42,0,0,101,18,1,0,0,0,102,103,5,47,0,
  	0,103,20,1,0,0,0,104,105,5,61,0,0,105,22,1,0,0,0,106,107,5,59,0,0,107,
  	24,1,0,0,0,108,109,5,44,0,0,109,26,1,0,0,0,110,111,5,40,0,0,111,28,1,
  	0,0,0,112,113,5,41,0,0,113,30,1,0,0,0,114,115,5,123,0,0,115,32,1,0,0,
  	0,116,117,5,125,0,0,117,34,1,0,0,0,118,119,5,58,0,0,119,120,5,58,0,0,
  	120,36,1,0,0,0,121,123,7,3,0,0,122,121,1,0,0,0,123,124,1,0,0,0,124,122,
  	1,0,0,0,124,125,1,0,0,0,125,126,1,0,0,0,126,127,6,18,0,0,127,38,1,0,0,
  	0,7,0,42,47,53,70,89,124,1,6,0,0
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
  std::call_once(relcgrammarlexerLexerOnceFlag, relcgrammarlexerLexerInitialize);
}
