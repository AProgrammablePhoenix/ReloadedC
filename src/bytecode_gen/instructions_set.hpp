#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace VM_Bytecode {
    const uint8_t prefix8  = 0x8;
    const uint8_t prefix16 = 0x10;
    const uint8_t prefix32 = 0x20;

    namespace Assembling {
        const std::unordered_set<std::string> one_operand_ops = {
            "load_c", "load_v", "store", "call"
        };
        const std::unordered_set<std::string> two_operand_ops = {
            "natcall"
        };
        const std::unordered_set<std::string> control_flow = {
            "call", "jmp", "je", "jne", "jg", "jl", "jge", "jle"
        };
    }
    
    const std::unordered_map<std::string, uint8_t> opcodes = {
        { "add", 0x00 }, // addition
        { "sub", 0x01 }, // subtraction
        { "mul", 0x02 }, // multiplication
        { "div", 0x03 }, // division
        { "imul", 0x04 }, // signed multiplication
        { "idiv", 0x05 }, // signed division
        { "neg", 0x06 }, // negate		
		
        { "not", 0x07 }, // bitwise NOT
		// skip 0x8 prefix
        { "and", 0x09 }, // bitwise AND
        { "or", 0x0A }, // bitwise OR
        { "xor", 0x0B }, // bitwise XOR
        { "shl", 0x0C }, // left binary shift
        { "shr", 0x0D }, // right binary shift
        { "sar", 0x0E }, // right arithmetic shift
        { "rol", 0x0F }, // rotate left
		// skip 0x10 prefix
        { "ror", 0x11 }, // rotate right

        { "load_c", 0x12 }, // load constant
        { "load_v", 0x13 }, // load variable
        { "store", 0x14 }, // store value

        { "call", 0x16 }, // call user defined procedure
        { "natcall", 0x17 }, // call native function
        { "ret", 0x18 }, // return
        { "hlt", 0x19 }, // halt

        { "cmp", 0x1A }, // compare
        { "jmp", 0x1B }, // jump
        { "je", 0x1C },	// jump if equal
        { "jne", 0x1D }, // jump if not equal
        { "jg", 0x1E }, // jump if greater
        { "jl", 0x1F }, // jump if less
        // skip 0x20 prefix
		{ "jge", 0x21 }, // jump if greater or equal
        { "jle", 0x22 }, // jump if less or equal

        { "cb", 0x23 }, // convert to byte
        { "cw", 0x24 }, // convert to word
        { "cd", 0x25 }, // convert to dword
        { "cq", 0x26 }, // convert to qword
        { "secb", 0x27 }, // sign extended convert to byte
        { "secw", 0x28 }, // sign extended convert to word
        { "secd", 0x29 }, // sign extended convert to dword
        { "secq", 0x2A }, // sign extended convert to qword
    };

    const std::unordered_set<std::string> size_prefixed_ops = {
        "add",
        "sub",
        "mul",
        "div",
        "imul",
        "idiv",

        "not",
        "and",
        "or",
        "xor",
        "shl",
        "shr",
        "sar",
        "rol",
        "ror",

        "load_c",
        "load_v",
        "store",

        "cmp",

        "cb",
        "cw",
        "cd",
        "cq",

        "secb"
        "secw",
        "secd",
        "secq"
    };
};