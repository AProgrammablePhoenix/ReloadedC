#include <iostream>
#include <string>
#include <algorithm>
#include <bit>

#include "engine/context.hpp"

inline constexpr size_t reduce_prefix(uint8_t prefix) {
    return (size_t)std::bit_width(prefix) - 4;
}

namespace {
    template<typename T> concept uinteger =
        std::is_same_v<T, uint8_t>
        || std::is_same_v<T, uint16_t>
        || std::is_same_v<T, uint32_t>
        || std::is_same_v<T, uint64_t>
    ;

    template<uinteger T> void vload_c_core(call_context& ctx) {
        auto& ectx = ctx.ectx;
        auto& stack = ectx.get_operands_stack();

        if constexpr (std::is_same_v<T, uint8_t>) {
            stack.push(ctx.args[0]);
        }
        else {
            constexpr size_t op_size = sizeof(T);
            std::vector<uint8_t> raw((uint8_t*)ctx.args.data(), (uint8_t*)ctx.args.data() + op_size);
            stack.push(raw);
        }
    }
    template<uinteger T> void vload_v_core(execution_context& ectx, uint16_t i) {
        auto& stack = ectx.get_operands_stack();
        auto& locals = ectx.get_local_variables().storage;

        if constexpr (std::is_same_v<T, uint8_t>) {
            stack.push((*locals)[i]);
        }
        else {
            constexpr size_t op_size = sizeof(T);
            std::vector<uint8_t> raw(locals->data() + i, locals->data() + i + op_size);
            stack.push(raw);
        }
    }
    template<uinteger T> void vstore_core(execution_context& ectx, uint16_t i) {
        auto& stack = ectx.get_operands_stack();
        auto& locals = ectx.get_local_variables().storage;

        if constexpr (std::is_same_v<T, uint8_t>) {
            (*locals)[i] = stack.pop();
        }
        else {
            constexpr size_t op_size = sizeof(T);
            std::vector<uint8_t> raw = stack.pop(op_size);
            std::reverse(raw.begin(), raw.end());
            for (size_t j = 0; j < op_size; ++j) {
                (*locals)[i + j] = raw[j];
            }
        }
    }

    static void(*vload_c_impl[4])(call_context&) = {
        &vload_c_core<uint8_t>,
        &vload_c_core<uint16_t>,
        &vload_c_core<uint32_t>,
        &vload_c_core<uint64_t>
    };
    static void(*vload_v_impl[4])(execution_context&, uint16_t) = {
        &vload_v_core<uint8_t>,
        &vload_v_core<uint16_t>,
        &vload_v_core<uint32_t>,
        &vload_v_core<uint64_t>
    };
    static void(*vstore_impl[4])(execution_context&, uint16_t) = {
        &vstore_core<uint8_t>,
        &vstore_core<uint16_t>,
        &vstore_core<uint32_t>,
        &vstore_core<uint64_t>
    };

    void vload_c_handler(call_context& ctx) {
        size_t vload_c_size = reduce_prefix(ctx.prefix);
        vload_c_impl[vload_c_size](ctx);
    }
    template<void(*vmem_impl[4])(execution_context&, uint16_t)> void vmem(call_context& ctx) {
        size_t vmem_size = reduce_prefix(ctx.prefix);
        uint16_t* i = (uint16_t*)ctx.args.data();
        vmem_impl[vmem_size](ctx.ectx, *i);
    }
    void vldptr_handler(call_context& ctx) {
        uint64_t offset = *(uint64_t*)ctx.args.data();
        execution_context& ectx = ctx.ectx;

        uint8_t* data_ptr = ectx.static_data.data() + offset;
        
        std::vector<uint8_t> raw_ptr((uint8_t*)&data_ptr, (uint8_t*)&data_ptr + sizeof(data_ptr));
        ectx.get_operands_stack().push(raw_ptr);
    }
    void vmkptr_handler(call_context& ctx) {
        uint16_t local_addr = *(uint16_t*)ctx.args.data();
        execution_context& ectx = ctx.ectx;

        uint8_t* ptr = ectx.get_local_variables().storage->data() + local_addr;

        std::vector<uint8_t> raw_ptr((uint8_t*)&ptr, (uint8_t*)&ptr + sizeof(ptr));
        ectx.get_operands_stack().push(raw_ptr);
    }
    void vdrptr_handler(call_context& ctx) {
        uint64_t size = *(uint64_t*)ctx.args.data();
        execution_context& ectx = ctx.ectx;
        auto& stack = ectx.get_operands_stack();

        std::vector<uint8_t> raw_ptr = stack.pop(sizeof(void*));
        std::reverse(raw_ptr.begin(), raw_ptr.end());
        uint8_t* ptr = *(uint8_t**)raw_ptr.data();

        std::vector<uint8_t> data(ptr, ptr + size);
        stack.push(data);
    }
    void vstptr_handler(call_context& ctx) {
        uint64_t size = *(uint64_t*)ctx.args.data();
        execution_context& ectx = ctx.ectx;
        auto& stack = ectx.get_operands_stack();

        std::vector<uint8_t> raw_ptr = stack.pop(sizeof(void*));
        std::vector<uint8_t> raw_v = stack.pop(size);

        std::reverse(raw_ptr.begin(), raw_ptr.end());
        std::reverse(raw_v.begin(), raw_v.end());

        uint8_t* ptr = *(uint8_t**)raw_ptr.data();
        for (size_t i = 0; i < size; ++i) {
            ptr[i] = raw_v[i];
        }
    }
}

auto vload_c = vload_c_handler;
auto vload_v = vmem<vload_v_impl>;
auto vldptr = vldptr_handler;
auto vmkptr = vmkptr_handler;
auto vdrptr = vdrptr_handler;
auto vstptr = vstptr_handler;
auto vstore = vmem<vstore_impl>;