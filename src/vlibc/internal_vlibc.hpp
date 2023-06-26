#pragma once

#include <iostream>
#include <vector>

#include "engine/context.hpp"

namespace {
    constexpr size_t int_size = 4; // fixed by the Reloaded C compiler
    constexpr size_t long_size = 8; // fixed by the Reloaded C compiler
    constexpr size_t ptr_size = sizeof(uintptr_t);

    static_assert(sizeof(int) == int_size);
    static_assert(sizeof(size_t) == long_size);

    template<size_t size> inline std::vector<uint8_t> get_raw_args(execution_context& ectx) {
        std::vector<uint8_t> raw_args = ectx.get_operands_stack().pop(size);
        std::reverse(raw_args.begin(), raw_args.end());
        return raw_args;
    }

    template<typename T, size_t offset = 0> inline T get_arg(const std::vector<uint8_t>& args) {
        if constexpr (offset == 0) {
            return *(T*)(args.data());
        } else {
            return *(T*)(args.data() + offset);
        }
    }

    template<typename T> concept _internal_pointer_t = std::is_pointer_v<T>;
    template<typename T> concept _internal_int32_t = std::is_same_v<T,int32_t> || std::is_same_v<T,uint32_t>;
    template<typename T> concept _internal_int64_t = std::is_same_v<T,int64_t> || std::is_same_v<T,uint64_t> || std::is_same_v<T,size_t>;

    template<typename T, size_t size> inline void return_value(const T& value, execution_context& ectx) {
        std::vector<uint8_t> raw((uint8_t*)&value, (uint8_t*)&value + size);
        ectx.get_operands_stack().push(raw);
    }
    template<_internal_pointer_t T, size_t size = ptr_size> inline void return_value(const T& value, execution_context& ectx) {
        std::vector<uint8_t> raw((uint8_t*)&value, (uint8_t*)&value + ptr_size);
        ectx.get_operands_stack().push(raw);
    }
    template<_internal_int32_t T, size_t size = int_size> inline void return_value(const T& value, execution_context& ectx) {
        std::vector<uint8_t> raw((uint8_t*)&value, (uint8_t*)&value + int_size);
        ectx.get_operands_stack().push(raw);
    }
    template<_internal_int64_t T, size_t size = long_size> inline void return_value(const T& value, execution_context& ectx) {
        std::vector<uint8_t> raw((uint8_t*)&value, (uint8_t*)&value + long_size);
        ectx.get_operands_stack().push(raw);
    }
}