#include <iostream>
#include <string>

#include <memory>
#include <vector>

#include "antlr4-runtime.h"
#include "../grammar/relcgrammarParser.h"

#include "../nodes/NodesLib.hpp"

#include "gvisitor.hpp"
#include "../internal_types.hpp"

_typeinfo_t gvisitor::visitType(relcgrammarParser::TypeContext* ctx) {
    _typeinfo_t _tinfo;

    relcgrammarParser::Plain_typeContext* plain_ctx = nullptr;

    if (ctx->pointer_type()) {
        auto* ptr_info = ctx->pointer_type();
        if (ptr_info->CONST()) {
            _tinfo._isconst = true;
        }

        _tinfo._isptr = true;
        _tinfo._ptrlvl = ptr_info->ptrsym.size();
        _tinfo._type.reserve(_tinfo._ptrlvl);
        for (size_t i = 0; i < _tinfo._ptrlvl; ++i) {
            _tinfo._type += "*";
        }

        plain_ctx = ptr_info->plain_type();
    }
    else {
        plain_ctx = ctx->plain_type();
    }

    if (plain_ctx->CONST()) {
        if (_tinfo._isptr) {
            _tinfo._isptrtoconst = true;
        }
        else {
            _tinfo._isconst = true;
        }
    }

    std::string rawtype = plain_ctx->INTERNAL_TYPE()->getText();
    if (rawtype == "long long") {
        rawtype = "long";
    }
    else if (rawtype == "void") {
        _tinfo._isvoidptr = true;
    }

    _tinfo._type = rawtype + _tinfo._type;

    return _tinfo;
}

namespace {
    static const std::unordered_set<std::string> primitive_types = { "bool", "char", "short", "int", "long", "float", "double", "long double"}; // missing short
    
    static bool is_integer(const _typeinfo_t& t) {
        return primitive_types.contains(t._type) && !t._isfloat;
    }

    static bool are_types_equal(const _typeinfo_t& t_in, const _typeinfo_t& t_out) {
        if (t_in._type == t_out._type) {
            return t_in._isptr == t_out._isptr && t_in._isfloat == t_out._isfloat;
        }
        return false;
    }
    static bool are_pointers_compatible(const _typeinfo_t& t_in, const _typeinfo_t& t_out) {
        if (!t_in._isptr || !t_out._isptr) {
            return false;
        }
        else if (t_in._isptrtoconst && !t_out._isptrtoconst) {
            return false;
        }
        else if (t_in._ptrlvl != t_out._ptrlvl) {
            return false;
        }
        else if (t_in._type != t_out._type && !t_in._isvoidptr && !t_out._isvoidptr) {
            return false;
        }

        return true;
    }

}

// TODO:
// adapt all implicit conversions with pointer arithmetic

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
bool is_valid_arithmetic(const _typeinfo_t& t1, const _typeinfo_t& t2) {
    if (t1._isptr && t2._isptr) {
        return false;
    }
    else if ((t1._isptr && !is_integer(t2)) || (t2._isptr && !is_integer(t1))) {
        return false;
    }
    
    return true;
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