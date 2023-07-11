#pragma once

#include <iostream>
#include <string>

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
    bool _isptrtoconst = false;
    bool _isvoidptr = false;
    int _ptrlvl = 0;
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