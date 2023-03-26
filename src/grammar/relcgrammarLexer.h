
// Generated from src/antlr_grammar/relcgrammar.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  relcgrammarLexer : public antlr4::Lexer {
public:
  enum {
    INT_LITERAL = 1, FLOAT_LITERAL = 2, TYPE = 3, NativeProtoDecl = 4, ID = 5, 
    CHAR = 6, PLUS = 7, MINUS = 8, MULT = 9, DIV = 10, EQUAL = 11, SEMI = 12, 
    COMMA = 13, LPAREN = 14, RPAREN = 15, LCURL = 16, RCURL = 17, NATIVE_SCOPE = 18, 
    WS = 19
  };

  explicit relcgrammarLexer(antlr4::CharStream *input);

  ~relcgrammarLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

