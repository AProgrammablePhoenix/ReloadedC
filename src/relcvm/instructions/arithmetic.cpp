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

    template<integer T, template<typename> typename Op> void vmath_core(execution_context& ectx) {
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
    template<integer T> void vneg_core(execution_context& ectx) {
        auto& stack = ectx.get_operands_stack();
        if constexpr (std::is_same_v<T, uint8_t> || std::is_same_v<T, int8_t>) {
            stack.push((uint8_t)-stack.pop());
        }
        else {
            constexpr size_t op_size = sizeof(T);
            std::vector<uint8_t> raw = stack.pop(op_size);
            std::reverse(raw.begin(), raw.end());

            T result = -(*(T*)raw.data());
            
            std::vector<uint8_t> raw_result((uint8_t*)&result, (uint8_t*)&result + op_size);
            stack.push(raw_result);
        }
    }

    static void(*vadd_impl[4])(execution_context&) = {
        &vmath_core<uint8_t, std::plus>,
        &vmath_core<uint16_t, std::plus>,
        &vmath_core<uint32_t, std::plus>,
        &vmath_core<uint64_t, std::plus>
    };
    static void(*vsub_impl[4])(execution_context&) = {
        &vmath_core<uint8_t, std::minus>,
        &vmath_core<uint16_t, std::minus>,
        &vmath_core<uint32_t, std::minus>,
        &vmath_core<uint64_t, std::minus>
    };
    static void(*vmul_impl[4])(execution_context&) = {
        &vmath_core<uint8_t, std::multiplies>,
        &vmath_core<uint16_t, std::multiplies>,
        &vmath_core<uint32_t, std::multiplies>,
        &vmath_core<uint64_t, std::multiplies>
    };
    static void(*vdiv_impl[4])(execution_context&) = {
        &vmath_core<uint8_t, std::divides>,
        &vmath_core<uint16_t, std::divides>,
        &vmath_core<uint32_t, std::divides>,
        &vmath_core<uint64_t, std::divides>
    };
    static void(*vimul_impl[4])(execution_context&) = {
        &vmath_core<int8_t, std::multiplies>,
        &vmath_core<int16_t, std::multiplies>,
        &vmath_core<int32_t, std::multiplies>,
        &vmath_core<int64_t, std::multiplies>
    };
    static void(*vidiv_impl[4])(execution_context&) = {
        &vmath_core<int8_t, std::divides>,
        &vmath_core<int16_t, std::divides>,
        &vmath_core<int32_t, std::divides>,
        &vmath_core<int64_t, std::divides>
    };
    static void(*vneg_impl[4])(execution_context&) = {
        &vneg_core<uint8_t>,
        &vneg_core<uint16_t>,
        &vneg_core<uint32_t>,
        &vneg_core<uint64_t>
    };

    template<void(*vmath_impl[4])(execution_context&)> void vmath(call_context& ctx) {
        size_t vmath_size = reduce_prefix(ctx.prefix);
        vmath_impl[vmath_size](ctx.ectx);
    }
}

auto vadd = vmath<vadd_impl>;
auto vsub = vmath<vsub_impl>;
auto vmul = vmath<vmul_impl>;
auto vdiv = vmath<vdiv_impl>;
auto vimul = vmath<vimul_impl>;
auto vidiv = vmath<vidiv_impl>;
auto vneg = vmath<vneg_impl>;