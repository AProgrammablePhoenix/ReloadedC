#include <iostream>
#include <array>

#include "context.hpp"

execution_stack<16384>& execution_context::get_operands_stack() {
    return this->operands_stack;
}
std::array<uint8_t, 0xFFFF>& execution_context::get_local_variables() {
    return this->local_variables;
}

execution_context::execution_context(const std::unordered_map<size_t, size_t>& idx_mapping) : index_mapping(idx_mapping) { };