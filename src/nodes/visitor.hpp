#pragma once

#include "node.hpp"
#include "program_node.hpp"
#include "statement_node.hpp"
#include "identifier_node.hpp"
#include "integer_node.hpp"
#include "float_node.hpp"
#include "char_node.hpp"
#include "math_node.hpp"
#include "func_call_node.hpp"

class Visitor {
public:
    virtual void visit(ProgramNode* node);
    virtual void visit(StatementNode* Node);
    virtual void visit(IdentifierNode* node);
    virtual void visit(IntegerNode* node);
    virtual void visit(FloatNode* node);
    virtual void visit(CharNode* node);
    virtual void visit(MathNode* node);
    virtual void visit(FunctionCall* node);
    virtual void visit(NativeFunctionCall* node);
};