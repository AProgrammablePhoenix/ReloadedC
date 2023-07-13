#include <iostream>
#include <array>
#include <span>
#include <vector>
#include <unordered_map>

#include "engine/context.hpp"
#include "engine/voperations.hpp"
#include "engine/engine.hpp"

#include "bytecode_gen/bytecode_gen.hpp"

namespace {    
    struct operation_context {
        void(*vop)(call_context&);
        uint8_t prefix;
        std::vector<uint8_t> args;
    };

    struct executable {
        std::unordered_map<size_t, size_t> index_mapping;
        std::vector<operation_context> vops;
        std::vector<uint8_t> static_data;
    };

    executable decode_bytecode(const std::vector<uint8_t>& bytecode) {
        const bytecode_header header = *(const bytecode_header*)bytecode.data();

        std::span<const uint8_t> natcall_symbol_table(
            bytecode.data() + sizeof(bytecode_header) + header.bytecode_size,
            header.data_section_offset - header.bytecode_size- sizeof(bytecode_header)
        );

        std::vector<std::vector<uint8_t>> natcall_symbols;
        for (size_t i = 0; i < natcall_symbol_table.size();) {
            const uint64_t lib_length = *(uint64_t*)natcall_symbol_table.data();
            const uint64_t sym_length = *(uint64_t*)(natcall_symbol_table.data() + sizeof(lib_length) + lib_length);

            const uint64_t entry_length = sizeof(lib_length) + lib_length + sizeof(sym_length) + sym_length;            
            natcall_symbols.emplace_back(natcall_symbol_table.data() + i, natcall_symbol_table.data() + i + entry_length);
            
            i += entry_length;
        }

        std::vector<uint8_t> data_section(
            bytecode.data() + header.data_section_offset,
            bytecode.data() + bytecode.size()
        );

        std::span<const uint8_t> exe_bytecode(bytecode.data() + sizeof(bytecode_header), header.bytecode_size);

        std::unordered_map<size_t, size_t> index_mapping;
        std::vector<operation_context> vops;
        operation_context current_vop;

        // allocate at least some space to reduce the number of reallocations
        // each pair of opcode + prefix occupies 2 bytes (without optional arguments)
        // bytecode_size / 2 is not the real amount of instructions, but something closer to it than just bytecode_size itself
        vops.reserve(header.bytecode_size / 2);

        for (size_t i = 0; i < header.bytecode_size; ++i) {
            current_vop = operation_context();
            index_mapping.emplace(i + sizeof(uint64_t), vops.size());

            uint8_t byte = exe_bytecode[i];

            if (byte == 0x8 || byte == 0x10 || byte == 0x20) {
                current_vop.prefix = byte;
                byte = exe_bytecode[++i];
            } else {
                current_vop.prefix = 0x40;
            }

            if (byte == VM_Bytecode::opcodes.at("load_c")) {
                const size_t arg_size = current_vop.prefix / 8;
                current_vop.args.reserve(arg_size);

                ++i;
                for (size_t j = i; j < i + arg_size; ++j) {
                    current_vop.args.push_back(exe_bytecode[j]);
                }

                i += arg_size;
                --i;
            }
            else if (byte == VM_Bytecode::opcodes.at("load_v") || byte == VM_Bytecode::opcodes.at("store")) {
                constexpr size_t arg_size = sizeof(uint16_t);
                current_vop.args.reserve(arg_size);

                ++i;
                for (size_t j = i; j < i + arg_size; ++j) {
                    current_vop.args.push_back(exe_bytecode[j]);
                }

                i += arg_size;
                --i;
            }
            else if (reverse_control_flow.contains(byte) || byte == VM_Bytecode::opcodes.at("ldptr")) {
                constexpr size_t arg_size = sizeof(uint64_t);
                current_vop.args.reserve(arg_size);

                ++i;
                for (size_t j = i; j < i + arg_size; ++j) {
                    current_vop.args.push_back(exe_bytecode[j]);
                }

                i += arg_size;
                --i;
            }
            else if (byte == VM_Bytecode::opcodes.at("natcall")) {
                constexpr size_t arg_size = sizeof(uint64_t);

                uint64_t entry_n = *(uint64_t*)(exe_bytecode.data() + i + 1);
                current_vop.args = natcall_symbols[entry_n];            

                i += arg_size;
            }

            current_vop.vop = opcodes_map.at(byte);
            vops.push_back(current_vop);
        }

        return executable{
            .index_mapping = index_mapping,
            .vops = vops,
            .static_data = data_section
        };
    }

    void engine_core(executable& _exec) {
        const auto& vops = _exec.vops;

        size_t ip = 0;
        bool running_state = true;
        int cmp_flag = 0;

        std::vector<std::pair<uint64_t, std::array<uint8_t, 0xFFFF>>> saved_locals;
        std::unordered_map<std::string, void*> external_libs;

        execution_context ectx(_exec.index_mapping, _exec.static_data);

        for (; ip < vops.size() && running_state; ++ip) {
            const auto& vop_ctx = vops[ip];

            call_context cctx{
                .ip = ip,
                .running_state = running_state,
                .cmp_flag = cmp_flag,
                .prefix = vop_ctx.prefix,
                .ectx = ectx,
                .args = vop_ctx.args,
                .saved_locals = saved_locals,
                .external_libs = external_libs
            };

            vop_ctx.vop(cctx);
        }
    }
}

void engine_execute(const std::vector<uint8_t>& bytecode) {
    auto vops = decode_bytecode(bytecode);
    engine_core(vops);
}