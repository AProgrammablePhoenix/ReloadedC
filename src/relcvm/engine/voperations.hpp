#pragma once

#include <unordered_map>
#include <unordered_set>

#include "../bytecode_gen/instructions_set.hpp"
#include "context.hpp"

// basic arithmetic
extern void(*vadd)(call_context&);
extern void(*vsub)(call_context&);
extern void(*vmul)(call_context&);
extern void(*vdiv)(call_context&);
extern void(*vimul)(call_context&);
extern void(*vidiv)(call_context&);
extern void(*vneg)(call_context&);

// binary arithmetic
extern void(*vnot)(call_context&);
extern void(*vand)(call_context&);
extern void(*vor)(call_context&);
extern void(*vxor)(call_context&);
extern void(*vshl)(call_context&);
extern void(*vshr)(call_context&);
extern void(*vsar)(call_context&);
extern void(*vrol)(call_context&);
extern void(*vror)(call_context&);

// memory operations
extern void(*vload_c)(call_context&);
extern void(*vload_v)(call_context&);
extern void(*vstore)(call_context&);

// control flow
extern void(*vcall)(call_context&);
extern void(*vnatcall)(call_context&);
extern void(*vret)(call_context&);
extern void(*vhlt)(call_context&);

// conditionnal
extern void(*vcmp)(call_context&);
extern void(*vjmp)(call_context&);
extern void(*vje)(call_context&);
extern void(*vjne)(call_context&);
extern void(*vjg)(call_context&);
extern void(*vjl)(call_context&);
extern void(*vjge)(call_context&);
extern void(*vjle)(call_context&);

// conversions
extern void(*vcb)(call_context&);
extern void(*vcw)(call_context&);
extern void(*vcd)(call_context&);
extern void(*vcq)(call_context&);
extern void(*vsecb)(call_context&);
extern void(*vsecw)(call_context&);
extern void(*vsecd)(call_context&);
extern void(*vsecq)(call_context&);

using namespace VM_Bytecode;

const std::unordered_map<uint8_t, void(*)(call_context&)> opcodes_map = {
    { opcodes.at("add"), vadd },
    { opcodes.at("sub"), vsub },
    { opcodes.at("mul"), vmul },
    { opcodes.at("div"), vdiv },
    { opcodes.at("imul"), vimul },
    { opcodes.at("idiv"), vidiv },
    { opcodes.at("neg"), vneg },

    { opcodes.at("not"), vnot },
    { opcodes.at("and"), vand },
    { opcodes.at("or"), vor },
    { opcodes.at("xor"), vxor },
    { opcodes.at("shl"), vshl },
    { opcodes.at("shr"), vshr },
    { opcodes.at("sar"), vsar },
    { opcodes.at("rol"), vrol },
    { opcodes.at("ror"), vror },

    { opcodes.at("load_c"), vload_c },
    { opcodes.at("load_v"), vload_v },
    { opcodes.at("store"), vstore },

    { opcodes.at("call"), vcall },
    { opcodes.at("natcall"), vnatcall },
    { opcodes.at("ret"), vret },
    { opcodes.at("hlt"), vhlt },

    { opcodes.at("cmp"), vcmp },
    { opcodes.at("jmp"), vjmp },
    { opcodes.at("je"), vje },
    { opcodes.at("jne"), vjne },
    { opcodes.at("jg"), vjg },
    { opcodes.at("jl"), vjl },
    { opcodes.at("jge"), vjge },
    { opcodes.at("jle"), vjle },

    { opcodes.at("cb"), vcb },
    { opcodes.at("cw"), vcw },
    { opcodes.at("cd"), vcd },
    { opcodes.at("cq"), vcq },
    { opcodes.at("secb"), vsecb },
    { opcodes.at("secw"), vsecw },
    { opcodes.at("secd"), vsecd },
    { opcodes.at("secq"), vsecq }
};

const std::unordered_set<uint8_t> reverse_control_flow = {
    opcodes.at("call"),
    opcodes.at("jmp"),
    opcodes.at("je"),
    opcodes.at("jne"),
    opcodes.at("jg"),
    opcodes.at("jl"),
    opcodes.at("jge"),
    opcodes.at("jle")
};