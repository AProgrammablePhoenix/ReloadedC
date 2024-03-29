#include <iostream>
#include <string>

#include <memory>
#include <vector>

#include "antlr4-runtime.h"
#include "../grammar/relcgrammarParser.h"

#include "../nodes/NodesLib.hpp"

#include "gvisitor.hpp"
#include "../internal_types.hpp"

namespace {
    static const std::unordered_set<std::string> primitive_types = { "bool", "char", "short", "int", "long", "float", "double", "long double"};
    static const std::unordered_set<std::string> float_types = { "float", "double", "long double" };
    
    static bool is_integer(const _typeinfo_t& t) {
        return primitive_types.contains(t._type) && !t._isfloat && !t._isptr;
    }

    static bool are_pointers_compatible(const _typeinfo_t& t_in, const _typeinfo_t& t_out) {
        if (!t_in._isptr || !t_out._isptr) {
            return false;
        }
        else if (t_in.ptrderef_tinfo->_isconst && !t_out.ptrderef_tinfo->_isconst) {
            return false;
        }
        else if (t_in._ptrlvl != t_out._ptrlvl) {
            return false;
        }
        else if (t_in._type != t_out._type && !t_in._isvoidptr && !t_out._isvoidptr) {
            return false;
        }

        return t_in._ptrlvl < 2 ? true : are_pointers_compatible(*t_in.ptrderef_tinfo, *t_out.ptrderef_tinfo);
    }
    static bool are_pointers_arithmetic(const _typeinfo_t& t_in, const _typeinfo_t& t_out) {
        if (!t_in._isptr || !t_out._isptr) {
            return false;
        }
        else if (t_in._ptrlvl != t_out._ptrlvl) {
            return false;
        }
        else if (t_in._type != t_out._type || t_in._isvoidptr != t_out._isvoidptr) {
            return false;
        }

        return t_in._ptrlvl < 2 ? true : are_pointers_arithmetic(*t_in.ptrderef_tinfo, *t_out.ptrderef_tinfo);
    }
    static bool are_types_equal(const _typeinfo_t& t_in, const _typeinfo_t& t_out) {
        if (t_in._type != t_out._type) {
            return false;
        }
        else if (t_in._isptr != t_out._isptr) {
            return false;
        }
        else if (t_in._isptr && t_out._isptr) {
            auto sub_t_in  = *t_in.ptrderef_tinfo;
            auto sub_t_out = *t_out.ptrderef_tinfo;

            if (!are_types_equal(sub_t_in, sub_t_out) || !are_pointers_compatible(sub_t_in, sub_t_out)) {
                return false;
            }
        }
        else if (t_in._ptrlvl != t_out._ptrlvl) {
            return false;
        }
        else if (t_in._isfloat != t_out._isfloat) {
            return false;
        }

        return true;
    }
    static bool is_type_arithmetic(const _typeinfo_t& _tinfo) {
        return !_tinfo._isptr && primitive_types.contains(_tinfo._type);
    }

    static _typeinfo_t visitPlainType(relcgrammarParser::Plain_typeContext* ctx) {
        _typeinfo_t _tinfo;

        _tinfo._isptr = false;
        _tinfo._isvoidptr = false;
        _tinfo.ptrderef_tinfo = nullptr;
        _tinfo._ptrlvl = 0;

        if (ctx->CONST()) {
            _tinfo._isconst = true;
        }

        // when unsigned keyword is introduced -> change signedness of type depending on its presence

        std::string rawtype = ctx->INTERNAL_TYPE()->getText();
        if (rawtype == "long long") {
            rawtype = "long";
        }

        _tinfo._type = rawtype;
        _tinfo._isfloat = float_types.contains(rawtype);

        return _tinfo;
    }
    static _typeinfo_t visitPtrType(relcgrammarParser::Pointer_typeContext* ctx) {
        _typeinfo_t _tinfo;

        _tinfo._isptr = true;
        if (ctx->CONST()) {
            _tinfo._isconst = true;
        }

        _typeinfo_t dereftinfo;
        if (ctx->pointer_type()) {
            dereftinfo = visitPtrType(ctx->pointer_type());
        }
        else {
            dereftinfo = visitPlainType(ctx->plain_type());
        }

        _tinfo._ptrlvl = dereftinfo._ptrlvl + 1;
        _tinfo._type = dereftinfo._type + '*';
        _tinfo.ptrderef_tinfo = std::make_shared<_typeinfo_t>(dereftinfo);
        _tinfo._isvoidptr = dereftinfo._isvoidptr || dereftinfo._type == "void";

        return _tinfo;
    }
}

_typeinfo_t gvisitor::visitType(relcgrammarParser::TypeContext* ctx) {
    if (ctx->pointer_type()) {
        return visitPtrType(ctx->pointer_type());
    }
    
    return visitPlainType(ctx->plain_type());
}

bool is_implicit_convertible(const _typeinfo_t& t_in, const _typeinfo_t& t_out, bool in_out) {
    if (are_types_equal(t_in, t_out)) {
        return true;
    }
    else if (t_in._isptr && t_out._isptr) {
        bool _cmp_in_out = are_pointers_compatible(t_in, t_out);
        if (_cmp_in_out) {
            return true;
        }
        
        return in_out ? false : are_pointers_compatible(t_out, t_in);
    }
    else if (t_in._isptr || t_out._isptr) {
        return false;
    }
    else if ((!primitive_types.contains(t_in._type) || !primitive_types.contains(t_out._type)) && t_in._type != t_out._type) {
        return false;
    }

    return true;
}
bool is_valid_arithmetic(const _typeinfo_t& t1, const _typeinfo_t& t2, char op) {
    if (is_type_arithmetic(t1) && is_type_arithmetic(t2)) {
        return true;
    }
    else if (t1._isptr && is_integer(t2)) {
        if (op == '+' || op == '-') {
            return true;
        }
    }
    else if (t2._isptr && is_integer(t1)) {
        if (op == '+') {
            return true;
        }
    }
    else if (t1._isptr && t2._isptr) {
        if (op == '-') {
            return are_pointers_arithmetic(t1, t2);
        }
    }

    return false;
}
bool is_pointer_addition(const _typeinfo_t& t1, const _typeinfo_t& t2, char op) {
    if (op == '+') {
        if ((t1._isptr && is_integer(t2)) || (is_integer(t1) && t2._isptr)) {
            return true;
        }
    }

    return false;
}
_typeinfo_t get_ptr_serialized_type(bool constness) {
    _typeinfo_t base = _typeinfo_t{
        ._isconst = constness,
        ._issigned = false
    };

    switch (sizeof(void*)) {
        case 1 : {
            base._type = "char";
            break;
        }
        case 4 : {
            base._type = "int";
            break;
        }
        case 8 : {
            base._type = "long";
            break;
        }
        default : {
            base._type = "int";
            break;
        }
    }

    return base;
}

_internal_conversion_t get_assignment_implicit_conversion(const _typeinfo_t& _t_in, const _typeinfo_t& _t_out) {
    static const std::unordered_map<std::string, size_t> types_size = {
        { "bool", sizeof(bool) },
        { "char",  1 },
        { "short", 2 },
        { "int",   4 },
        { "long",  8 },
        { "float", sizeof(float) },
        { "double", sizeof(double) },
        { "long double", sizeof(long double) }
    };

    bool int_to_float = false;
    bool float_to_int = false;

    if (are_types_equal(_t_in, _t_out) || are_pointers_compatible(_t_in, _t_out)) {
        return _internal_conversion_t {
            .useless = true
        };
    }
    else if (_t_in._isfloat && is_integer(_t_out)) {
        float_to_int = true;
    }
    else if (_t_out._isfloat && is_integer(_t_in)) {
        int_to_float = true;
    }
    
    return _internal_conversion_t {
        ._size_in = types_size.at(_t_in._type),
        ._size_out = types_size.at(_t_out._type),
        ._is_signed = _t_out._issigned,
        ._float_to_int = float_to_int,
        ._int_to_float = int_to_float
    };
}
_implicit_conversion_t get_expression_implicit_conversion(const _typeinfo_t& _t_left, const _typeinfo_t& _t_right) {
    if ((is_integer(_t_left) || _t_left._isfloat) && (is_integer(_t_right) || _t_right._isfloat)) {
        static const std::unordered_map<std::string, size_t> types_precedence = {
            { "bool", 0},
            { "char", 1 },
            { "short", 2 },
            { "int",  3 },
            { "long", 4 },
            { "float", 5 },
            { "double", 6 },
            { "long double", 7 }
        };

        if (!(is_integer(_t_left) && is_integer(_t_right)) || (_t_left._issigned == _t_right._issigned)) {
            if (types_precedence.at(_t_left._type) == types_precedence.at(_t_right._type)) {
                return _implicit_conversion_t {
                    ._conv = {
                        .useless = true
                    }
                };
            }
            else if (types_precedence.at(_t_left._type) > types_precedence.at(_t_right._type)) {
                return _implicit_conversion_t {
                    ._conv = get_assignment_implicit_conversion(_t_right, _t_left),
                    ._left_to_right = false
                };
            }

            return _implicit_conversion_t { 
                ._conv = get_assignment_implicit_conversion(_t_left, _t_right),
                ._left_to_right = true
            };
        } else {
            const _typeinfo_t* _unsigned_t = nullptr;
            const _typeinfo_t* _signed_t = nullptr;
            bool base_direction = true;

            if (_t_left._issigned) {
                _unsigned_t = &_t_right;
                _signed_t = &_t_left;
            }
            else {
                _unsigned_t = &_t_left;
                _signed_t = &_t_right;
                base_direction = false;
            }

            if (types_precedence.at(_unsigned_t->_type) >= types_precedence.at(_signed_t->_type)) {
                return {
                    ._conv = get_assignment_implicit_conversion(*_signed_t, *_unsigned_t),
                    ._left_to_right = base_direction
                };
            }
            return {
                ._conv = get_assignment_implicit_conversion(*_unsigned_t, *_signed_t),
                ._left_to_right = !base_direction
            };
        }
    }

    return {
        ._conv = {
            .useless = true
        }
    };
}