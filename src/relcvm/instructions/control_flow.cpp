#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <bit>

#include <dlfcn.h>

#include "engine/context.hpp"
#include "vlibc/vlibc.hpp"

namespace {
    void vcall_core(call_context& ctx) {
        ctx.saved_locals.emplace_back(ctx.ip, ctx.ectx.get_local_variables());
        ctx.ectx.get_local_variables().storage = std::make_shared<std::array<uint8_t,0xFFFF>>();
        uint64_t addr = *(uint64_t*)ctx.args.data();
        ctx.ip = ctx.ectx.index_mapping.at(addr + 1) - 1;
    }
    void vnatcall_core(call_context& ctx) {
        uint64_t s1_len = *(uint64_t*)ctx.args.data();
        uint64_t s2_len = *(uint64_t*)(ctx.args.data() + sizeof(s1_len) + s1_len);

        std::string s1;
        std::string s2;
        s1.assign((const char*)ctx.args.data() + sizeof(s1_len), s1_len);
        s2.assign((const char*)(ctx.args.data() + sizeof(s1_len) + s1_len + sizeof(s2_len)), s2_len);

        if (s1 == "vlibc") {
            bool call_status = vlibc_handler(s2, ctx.ectx);
            if (!call_status) {
                auto err = fmt::format(fg(fmt::color::dark_red) | fmt::emphasis::bold, "runtime error: symbol not found in vlibc: {}\n", s2);
                throw std::runtime_error(err);
            }
        }
        else {
            void* external_lib;
            const char* error;
            if (!ctx.external_libs.count(s1)) {
                external_lib = dlopen(s1.c_str(), RTLD_LAZY);
                if (!external_lib) {
                    auto err = fmt::format(fg(fmt::color::dark_red) | fmt::emphasis::bold, "runtime error: {}\n", dlerror());
                    throw std::runtime_error(err);
                }
                ctx.external_libs.emplace(s1, external_lib);
            }
            else {
                external_lib = ctx.external_libs.at(s1);
            }

            void(*function_symbol)(execution_context&) = (void(*)(execution_context&))dlsym(external_lib, s2.c_str());
            if ((error = dlerror()) != NULL) {
                auto formated_error = fmt::format(fg(fmt::color::dark_red) | fmt::emphasis::bold, "runtime error: {}\n", error);
                throw std::runtime_error(formated_error);
            }
            dlerror();

            function_symbol(ctx.ectx);
        }
    }
    void vret_core(call_context& ctx) {
        const auto [prev_ip, prev_locals] = ctx.saved_locals.back();
        ctx.saved_locals.pop_back();
        ctx.ectx.get_local_variables() = prev_locals;
        ctx.ip = prev_ip;
    }
    void vhlt_core(call_context& ctx) {
        ctx.running_state = false;
    }
}

auto vcall = vcall_core;
auto vnatcall = vnatcall_core;
auto vret = vret_core;
auto vhlt = vhlt_core;