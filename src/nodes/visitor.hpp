#pragma once

#include "node.hpp"
#include "expressions.hpp"
#include "program.hpp"
#include "primitive_types.hpp"

class Visitor {
public:
    virtual void visit(ProgramNode* node);
    virtual void visit(StatementNode* Node);
    virtual void visit(IdentifierNode* node);
    virtual void visit(DereferenceNode* node);
    virtual void visit(AddressofNode* node);
    virtual void visit(IntegerNode* node);
    virtual void visit(LongNode* node);
    virtual void visit(FloatNode* node);
    virtual void visit(CharNode* node);
    virtual void visit(StringNode* node);
    virtual void visit(ConversionNode* node);
    virtual void visit(PointerAdditionNode* node);
    virtual void visit(PointerSubtractionNode* node);
    virtual void visit(MathNode* node);
    virtual void visit(FunctionCall* node);
    virtual void visit(NativeFunctionCall* node);
};