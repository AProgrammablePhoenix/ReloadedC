#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
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

    template<uinteger T> void vcmp_core(call_context& ctx) {
        auto& stack = ctx.ectx.get_operands_stack();

        if constexpr (std::is_same_v<T, uint8_t>) {
            uint8_t b = stack.pop();
            uint8_t a = stack.pop();

            ctx.cmp_flag = 
                a == b ? 0
                : a < b ? -1
                : 1
            ;
        }
        else {
            constexpr size_t op_size = sizeof(T);
            std::vector<uint8_t> raw = stack.pop(2 * op_size);
            std::reverse(raw.begin(), raw.end());

            T a = *(T*)raw.data();
            T b = *(T*)(raw.data() + op_size);

            ctx.cmp_flag = 
                a == b ? 0
                : a < b ? -1
                : 1
            ;
        }
    }
    void vjmp_core(call_context& ctx) {
        uint64_t* addr = (uint64_t*)ctx.args.data();
        ctx.ip = *addr;
    }
    template<template<typename> typename Op> void vjc_core(call_context& ctx) {
        int c = ctx.cmp_flag;
        
        Op<int> o;
        if (o(c, 0)) {
            uint64_t* addr = (uint64_t*)ctx.args.data();
            ctx.ip = *addr;
        }
    }

    void(*vcmp_impl[4])(call_context&) = {
        &vcmp_core<uint8_t>,
        &vcmp_core<uint16_t>,
        &vcmp_core<uint32_t>,
        &vcmp_core<uint64_t>
    };
    void(*vje_impl)(call_context&) = &vjc_core<std::equal_to>;
    void(*vjne_impl)(call_context&) = &vjc_core<std::not_equal_to>;
    void(*vjg_impl)(call_context&) = &vjc_core<std::greater>;
    void(*vjl_impl)(call_context&) = &vjc_core<std::less>;
    void(*vjge_impl)(call_context&) = &vjc_core<std::greater_equal>;
    void(*vjle_impl)(call_context&) = &vjc_core<std::less_equal>;

    void vcmp_handler(call_context& ctx) {
        size_t vcmp_size = reduce_prefix(ctx.prefix);
        vcmp_impl[vcmp_size](ctx);
    }
}

auto vcmp = vcmp_handler;
auto vjmp = vjmp_core;
auto vje = vje_impl;
auto vjne = vjne_impl;
auto vjg = vjg_impl;
auto vjl = vjl_impl;
auto vjge = vjge_impl;
auto vjle = vjle_impl;