#include <iostream>
#include <array>
#include <unordered_map>
#include <vector>

#include "context.hpp"

execution_stack<16384>& execution_context::get_operands_stack() {
    return this->operands_stack;
}
heap_array<0xFFFF>& execution_context::get_local_variables() {
    return this->local_variables;
}

execution_context::execution_context(const std::unordered_map<size_t, size_t>& idx_mapping, std::vector<uint8_t>& _static_data) : 
    index_mapping(idx_mapping), static_data(_static_data) { };