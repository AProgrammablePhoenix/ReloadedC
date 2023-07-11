
// Generated from src/antlr_grammar/relcgrammar.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  relcgrammarLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, LONG_LITERAL = 2, INT_LITERAL = 3, FLOAT_LITERAL = 4, INTERNAL_TYPE = 5, 
    CONST = 6, NativeProtoDecl = 7, ID = 8, CHAR = 9, PLUS = 10, MINUS = 11, 
    MULT = 12, DIV = 13, EQUAL = 14, SEMI = 15, COMMA = 16, LPAREN = 17, 
    RPAREN = 18, LCURL = 19, RCURL = 20, NATIVE_SCOPE = 21, WS = 22
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

