#include <string>
#include <unordered_map>
#include <unordered_set>

namespace VM_Bytecode {
    const uint8_t prefix8  = 0x8;
    const uint8_t prefix16 = 0x10;
    const uint8_t preifx32 = 0x20;

    namespace Assembling {
        const std::unordered_set<std::string> one_operand_ops = {
            "load_c", "load_v", "store", "call"
        };
        const std::unordered_set<std::string> two_operand_ops = {
            "natcall"
        };
    }
    
    const std::unordered_map<std::string, uint8_t> opcodes = {
        { "add", 0x00 },
        { "sub", 0x01 },
        { "mul", 0x02 },
        { "div", 0x03 },
        { "imul", 0x04 },
        { "idiv", 0x05 },
        { "neg", 0x06 },

        { "and", 0x07 }, // skip 0x8 prefix
        { "not", 0x09 },
        { "or", 0x0A },
        { "xor", 0x0B },
        { "shl", 0x0C },
        { "shr", 0x0D },
        { "sar", 0x0E },
        { "rol", 0x0F }, // skip 0x10 prefix
        { "ror", 0x11 },

        { "load_c", 0x12 },
        { "load_v", 0x13 },
        { "store", 0x14 },
        { "dstore", 0x15 },

        { "call", 0x16 },
        { "natcall", 0x17 },
        { "ret", 0x18 },
        { "hlt", 0x19 },

        { "cmp", 0x1A },
        { "jmp", 0x1B },
        { "je", 0x1C },
        { "jne", 0x1D },
        { "jg", 0x1E },
        { "jl", 0x1F },
        { "jge", 0x21 }, // skip 0x20 prefix
        { "jle", 0x22 },

        { "cb", 0x23 },
        { "cw", 0x24 },
        { "cd", 0x25 },
        { "cq", 0x26 },

        { "secw", 0x27 },
        { "secd", 0x28 },
        { "secq", 0x29 },
    };

    const std::unordered_set<std::string> size_prefixed_ops = {
        "add",
        "sub",
        "mul",
        "div",
        "imul",
        "idiv",

        "and",
        "not",
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
        "dstore",

        "cmp",

        "cb",
        "cw",
        "cd",
        "cq",

        "secw",
        "secd",
        "secq"
    };
};