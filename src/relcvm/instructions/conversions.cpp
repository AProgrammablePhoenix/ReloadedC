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

    template<typename I, typename O> void vconv_core(execution_context& ectx) {        
        if constexpr (std::is_same_v<I, O> || sizeof(I) == sizeof(O)) return;

        auto& stack = ectx.get_operands_stack();

        if constexpr (std::is_same_v<I, uint8_t> || std::is_same_v<I, int8_t>) {
            I value = (I)stack.pop();
            O conv = (O)value;

            std::vector<uint8_t> raw_conv((uint8_t*)&conv, (uint8_t*)&conv + sizeof(O));
            stack.push(raw_conv);
        }
        else if constexpr (std::is_same_v<O, uint8_t> || std::is_same_v<O, int8_t>) {
            std::vector<uint8_t> raw_value = stack.pop(sizeof(I));
            std::reverse(raw_value.begin(), raw_value.end());
            I value = *(I*)raw_value.data();

            O conv = (O)value;
            stack.push((uint8_t)conv);
        }
        else {
            std::vector<uint8_t> raw_value = stack.pop(sizeof(I));
            std::reverse(raw_value.begin(), raw_value.end());
            I value = *(I*)raw_value.data();

            O conv = (O)value;
            std::vector<uint8_t> raw_conv((uint8_t*)&conv, (uint8_t*)&conv + sizeof(O));
            stack.push(raw_conv);
        }
    }
    void(*vcb_impl[4])(execution_context&) = {
        &vconv_core<uint8_t,  uint8_t>,
        &vconv_core<uint16_t, uint8_t>,
        &vconv_core<uint32_t, uint8_t>,
        &vconv_core<uint64_t, uint8_t>
    };
    void(*vcw_impl[4])(execution_context&) = {
        &vconv_core<uint8_t,  uint16_t>,
        &vconv_core<uint16_t, uint16_t>,
        &vconv_core<uint32_t, uint16_t>,
        &vconv_core<uint64_t, uint16_t>
    };
    void(*vcd_impl[4])(execution_context&) = {
        &vconv_core<uint8_t,  uint32_t>,
        &vconv_core<uint16_t, uint32_t>,
        &vconv_core<uint32_t, uint32_t>,
        &vconv_core<uint64_t, uint32_t>
    };
    void(*vcq_impl[4])(execution_context&) = {
        &vconv_core<uint8_t,  uint64_t>,
        &vconv_core<uint16_t, uint64_t>,
        &vconv_core<uint32_t, uint64_t>,
        &vconv_core<uint64_t, uint64_t>
    };
    void(*vsecb_impl[4])(execution_context&) = {
        &vconv_core<int8_t,  int8_t>,
        &vconv_core<int16_t, int8_t>,
        &vconv_core<int32_t, int8_t>,
        &vconv_core<int64_t, int8_t>
    };
    void(*vsecw_impl[4])(execution_context&) = {
        &vconv_core<int8_t,  int16_t>,
        &vconv_core<int16_t, int16_t>,
        &vconv_core<int32_t, int16_t>,
        &vconv_core<int64_t, int16_t>
    };
    void(*vsecd_impl[4])(execution_context&) = {
        &vconv_core<int8_t,  int32_t>,
        &vconv_core<int16_t, int32_t>,
        &vconv_core<int32_t, int32_t>,
        &vconv_core<int64_t, int32_t>
    };
    void(*vsecq_impl[4])(execution_context&) = {
        &vconv_core<int8_t,  int64_t>,
        &vconv_core<int16_t, int64_t>,
        &vconv_core<int32_t, int64_t>,
        &vconv_core<int64_t, int64_t>
    };

    template<void(*vconv_impl[4])(execution_context&)> void vconv(call_context& ctx) {
        size_t vconv_size = reduce_prefix(ctx.prefix);
        vconv_impl[vconv_size](ctx.ectx);
    }
}

auto vcb = vconv<vcb_impl>;
auto vcw = vconv<vcw_impl>;
auto vcd = vconv<vcd_impl>;
auto vcq = vconv<vcq_impl>;
auto vsecb = vconv<vsecb_impl>;
auto vsecw = vconv<vsecw_impl>;
auto vsecd = vconv<vsecd_impl>;
auto vsecq = vconv<vsecq_impl>;