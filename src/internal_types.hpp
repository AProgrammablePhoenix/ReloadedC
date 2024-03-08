#pragma once

#include <iostream>
#include <string>
#include <memory>

struct _typeinfo_t {
    // general data
    std::string _type = "";
    bool _isconst = false;

    // integer data
    bool _issigned = true;

    // floating-point data
    bool _isfloat = false;

    // pointer data
    bool _isptr = false;
    std::shared_ptr<_typeinfo_t> ptrderef_tinfo = nullptr;
    bool _isvoidptr = false;
    int _ptrlvl = 0;
};

struct _serlialized_ptr_t final : public _typeinfo_t {
    _serlialized_ptr_t(bool constness) {
        switch (sizeof(void*)) {
            case 1 : {
                _type = "char";
                break;
            }
            case 4 : {
                _type = "int";
                break;
            }
            case 8 : {
                _type = "long";
                break;
            }
            default : {
                _type = "int";
                break;
            }
        }

        _isconst = constness;
        _issigned = false;
        _isfloat = false;
        _isptr = false;
        ptrderef_tinfo = nullptr;
        _isvoidptr = false;
        _ptrlvl = 0;
    }
};

struct _variable_def_t {
    std::string _name;
    _typeinfo_t _tinfo;
};

struct _internal_conversion_t {
    size_t _size_in  = 0;
    size_t _size_out = 0;

    bool useless = false;

    bool _is_signed    = false;
    bool _float_to_int = false;
    bool _int_to_float = false;
};

struct _implicit_conversion_t {
    _internal_conversion_t _conv;
    _internal_conversion_t _conv_opt;
    bool _left_to_right = false;
    bool both_converted = false;
};