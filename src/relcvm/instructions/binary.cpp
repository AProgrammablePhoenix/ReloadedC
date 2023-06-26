#include <iostream>
#include <string>
#include <algorithm>
#include <bit>

#include "engine/context.hpp"

inline constexpr size_t reduce_prefix(uint8_t prefix) {
    return (size_t)std::bit_width(prefix) - 4;
}

namespace {
    template<typename T> concept integer =
        std::is_same_v<T, uint8_t> || std::is_same_v<T, int8_t>
        || std::is_same_v<T, uint16_t> || std::is_same_v<T, int16_t>
        || std::is_same_v<T, uint32_t> || std::is_same_v<T, int32_t>
        || std::is_same_v<T, uint64_t> || std::is_same_v<T, int64_t>
    ;
    

    template<integer T> struct bit_and {
        T operator()(const T& left, const T& right) const {
            return left & right;
        }
    };    
    template<integer T> struct bit_or {
        T operator()(const T& left, const T& right) const {
            return left | right;
        }
    };
    template<integer T> struct bit_xor {
        T operator()(const T& left, const T& right) const {
            return left ^ right;
        }
    };
    template<integer T> struct bit_shl {
        T operator()(const T& left, const T& right) const {
            return left << right;
        }
    };
    template<integer T> struct bit_shr {
        T operator()(const T& left, const T& right) const {
            return left >> right;
        }
    };
    template<integer T> struct bit_rol {
        T operator()(const T& left, const T& right) const {
            return std::rotl(left, right);
        }
    };
    template<integer T> struct bit_ror {
        T operator()(const T& left, const T& right) const {
            return std::rotr(left, right);
        }
    };

    template<integer T, template<typename> typename Op> void vbin_core(execution_context& ectx) {
        auto& stack = ectx.get_operands_stack();

        constexpr Op<T> _operator;

        if constexpr (std::is_same_v<T, uint8_t> || std::is_same_v<T, int8_t>) {  
            uint8_t b = stack.pop();
            uint8_t a = stack.pop();
            stack.push(_operator(a, b));
        }
        else {
            constexpr size_t op_size = sizeof(T);
            std::vector<uint8_t> raw = stack.pop(2 * op_size);
            std::reverse(raw.begin(), raw.end());

            T* a = (T*)raw.data();
            T* b = (T*)(raw.data() + op_size);

            T result = _operator(*a, *b);

            std::vector<uint8_t> raw_result((uint8_t*)&result, (uint8_t*)&result + op_size);
            stack.push(raw_result);
        }
    }
    template<integer T> void vnot_core(execution_context& ectx) {
        auto& stack = ectx.get_operands_stack();
        if constexpr (std::is_same_v<T, uint8_t>) {
            stack.push((uint8_t)~stack.pop());
        }
        else {
            constexpr size_t op_size = sizeof(T);
            std::vector<uint8_t> raw = stack.pop(op_size);
            std::reverse(raw.begin(), raw.end());

            T result = ~(*(T*)raw.data());
            
            std::vector<uint8_t> raw_result((uint8_t*)&result, (uint8_t*)&result + op_size);
            stack.push(raw_result);
        }
    }

    static void(*vnot_impl[4])(execution_context&) = {
        &vnot_core<uint8_t>,
        &vnot_core<uint16_t>,
        &vnot_core<uint32_t>,
        &vnot_core<uint64_t>
    };
    static void(*vand_impl[4])(execution_context&) = {
        &vbin_core<uint8_t,  bit_and>,
        &vbin_core<uint16_t, bit_and>,
        &vbin_core<uint32_t, bit_and>,
        &vbin_core<uint64_t, bit_and>
    };
    static void(*vor_impl[4])(execution_context&) = {
        &vbin_core<uint8_t,  bit_or>,
        &vbin_core<uint16_t, bit_or>,
        &vbin_core<uint32_t, bit_or>,
        &vbin_core<uint64_t, bit_or>
    };
    static void(*vxor_impl[4])(execution_context&) = {
        &vbin_core<uint8_t,  bit_xor>,
        &vbin_core<uint16_t, bit_xor>,
        &vbin_core<uint32_t, bit_xor>,
        &vbin_core<uint64_t, bit_xor>
    };
    static void(*vshl_impl[4])(execution_context&) = {
        &vbin_core<uint8_t,  bit_shl>,
        &vbin_core<uint16_t, bit_shl>,
        &vbin_core<uint32_t, bit_shl>,
        &vbin_core<uint64_t, bit_shl>
    };
    static void(*vshr_impl[4])(execution_context&) = {
        &vbin_core<uint8_t,  bit_shr>,
        &vbin_core<uint16_t, bit_shr>,
        &vbin_core<uint32_t, bit_shr>,
        &vbin_core<uint64_t, bit_shr>
    };
    static void(*vsar_impl[4])(execution_context&) = {
        &vbin_core<int8_t,  bit_shr>,
        &vbin_core<int16_t, bit_shr>,
        &vbin_core<int32_t, bit_shr>,
        &vbin_core<int64_t, bit_shr>
    };
    static void(*vrol_impl[4])(execution_context&) = {
        &vbin_core<uint8_t,  bit_rol>,
        &vbin_core<uint16_t, bit_rol>,
        &vbin_core<uint32_t, bit_rol>,
        &vbin_core<uint64_t, bit_rol>
    };
    static void(*vror_impl[4])(execution_context&) = {
        &vbin_core<uint8_t,  bit_ror>,
        &vbin_core<uint16_t, bit_ror>,
        &vbin_core<uint32_t, bit_ror>,
        &vbin_core<uint64_t, bit_ror>
    };

    template<void(*vbin_impl[4])(execution_context&)> void vbin(call_context& ctx) {
        size_t vbin_size = reduce_prefix(ctx.prefix);
        vbin_impl[vbin_size](ctx.ectx);
    }
}

auto vnot = vbin<vnot_impl>;
auto vand = vbin<vand_impl>;
auto vor = vbin<vor_impl>;
auto vxor = vbin<vxor_impl>;
auto vshl = vbin<vshl_impl>;
auto vshr = vbin<vshr_impl>;
auto vsar = vbin<vsar_impl>;
auto vrol = vbin<vrol_impl>;
auto vror = vbin<vror_impl>;