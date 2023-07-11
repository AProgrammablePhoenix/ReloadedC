#pragma once

#include "expressions.hpp"
#include "../internal_types.hpp"

template<typename T, const char* _imm_type, const _typeinfo_t& _type> class _internal_primitive: public ExpNode {
public:
    _internal_primitive(int line, T value) : ExpNode(line, _imm_type, _type), value(value) {};
    const T& getValue() const { return this->value; };
    constexpr bool isConst() const { return true; };
    virtual void accept(class Visitor& v) = 0;
private:
    T value;
};

inline constexpr char _internal_imm_num[] = "imm_num";
inline constexpr char _internal_imm_flt[] = "imm_flt";
inline constexpr char _internal_imm_chr[] = "imm_chr";

inline constexpr _typeinfo_t _internal_int = {
    ._type = "int"
};
inline constexpr _typeinfo_t _internal_long = {
    ._type = "long"
};
inline constexpr _typeinfo_t _internal_float = {
    ._type = "float"
};
inline constexpr _typeinfo_t _internal_char = {
    ._type = "char"
};

class IntegerNode : public _internal_primitive<int32_t, _internal_imm_num, _internal_int> {
public:
    using _internal_primitive<int32_t, _internal_imm_num, _internal_int>::_internal_primitive;
    void accept(class Visitor& v);
};

class LongNode : public _internal_primitive<int64_t, _internal_imm_num, _internal_long> {
    using _internal_primitive<int64_t, _internal_imm_num, _internal_long>::_internal_primitive;
    void accept(class Visitor& v);
};

class FloatNode : public _internal_primitive<float, _internal_imm_flt, _internal_float> {
    using _internal_primitive<float, _internal_imm_flt, _internal_float>::_internal_primitive;
    void accept(class Visitor& v);
};

class CharNode : public _internal_primitive<char, _internal_imm_chr, _internal_char> {
    using _internal_primitive<char, _internal_imm_chr, _internal_char>::_internal_primitive;
    void accept(class Visitor& v);
};