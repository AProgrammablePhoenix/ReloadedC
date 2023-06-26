#pragma once

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

#include <fmt/core.h>
#include <fmt/color.h>

[[noreturn]] inline void report_err(const std::string& message) {
    std::string err = fmt::format("{} : {}\n",
        fmt::styled("runtime error: ", fg(fmt::color::red)),
        message
    );
    throw std::runtime_error(err);
}

template<size_t max_size> class execution_stack {
public:
    execution_stack() = default;

    void push(uint8_t v) {
        if constexpr (max_size) {
            if (this->stack.size() >= max_size) {
                report_err(
                    fmt::format("Stack overflow (at {}): {{ allocated: {} B, used: {} B }}", fmt::ptr(this), max_size, max_size + 1)
                );
            }
        }

        this->stack.push(v);
    }
    void push(const std::vector<uint8_t>& bytes) {
        if constexpr (max_size) {
            if (this->stack.size() >= max_size) {
                report_err(
                    fmt::format("Stack overflow (at {}): {{ allocated: {} B, used: {} B }}", fmt::ptr(this), max_size, max_size + bytes.size())
                );
            }
        }


        for (const auto& b : bytes) {
            this->stack.push(b);
        }
    }

    uint8_t pop() {
        if (this->stack.size() == 0) {
            report_err(
                fmt::format("Stack underflow (at {})", fmt::ptr(this))
            );
        }

        uint8_t v = this->stack.top();
        this->stack.pop();
        return v;
    }
    std::vector<uint8_t> pop(size_t n) {
        if (this->stack.size() - n >= this->stack.size()) {
            report_err(
                fmt::format("Stack underflow (at {})", fmt::ptr(this))
            );
        }
        
        std::vector<uint8_t> values(n);

        for (auto& v : values) {
            v = this->stack.top();
            this->stack.pop();
        }

        return values;
    }

    bool empty() const {
        return this->stack.empty();
    }
private:
    std::stack<uint8_t> stack;
};

class execution_context {
public:
    execution_context(const std::unordered_map<size_t, size_t>& idx_mapping);    

    execution_stack<16384>& get_operands_stack();
    std::array<uint8_t, 0xFFFF>& get_local_variables();

    const std::unordered_map<size_t, size_t>& index_mapping;
private:
    execution_stack<16384> operands_stack;
    std::array<uint8_t, 0xFFFF> local_variables;
};

struct call_context {
    uint64_t& ip; // index of end of current instruction bytecode
    bool& running_state; // execution continues if this variable is true, otherwise it stops
    int& cmp_flag;

    uint8_t prefix;
    execution_context& ectx;
    const std::vector<uint8_t>& args;

    std::vector<std::pair<uint64_t, std::array<uint8_t, 0xFFFF>>>& saved_locals;
    std::unordered_map<std::string, void*>& external_libs;
};
