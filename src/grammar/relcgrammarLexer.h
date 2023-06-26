
// Generated from src/antlr_grammar/relcgrammar.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  relcgrammarLexer : public antlr4::Lexer {
public:
  enum {
    LONG_LITERAL = 1, INT_LITERAL = 2, FLOAT_LITERAL = 3, TYPE = 4, CONST = 5, 
    NativeProtoDecl = 6, ID = 7, CHAR = 8, PLUS = 9, MINUS = 10, MULT = 11, 
    DIV = 12, EQUAL = 13, SEMI = 14, COMMA = 15, LPAREN = 16, RPAREN = 17, 
    LCURL = 18, RCURL = 19, NATIVE_SCOPE = 20, WS = 21
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

