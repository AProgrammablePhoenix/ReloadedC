#include <iostream>
#include <vector>
#include <cstdlib>

#include "engine/context.hpp"
#include "vlibc/internal_vlibc.hpp"

// Process control
// void abort(void)
[[noreturn]] void vabort(execution_context& ectx) {
    ::abort();
}
// void exit(int exit_code)
[[noreturn]] void vexit(execution_context& ectx) {
    auto raw_arg = get_raw_args<int_size>(ectx);

    int32_t exit_code = get_arg<int32_t>(raw_arg);

    ::exit(exit_code);
}
// void quick_exit(int exit_code)
[[noreturn]] void vquick_exit(execution_context& ectx) {
    auto raw_arg = get_raw_args<int_size>(ectx);

    int32_t exit_code = get_arg<int32_t>(raw_arg);

    ::quick_exit(exit_code);
}
// void _Exit(int exit_code)
[[noreturn]] void v_Exit(execution_context& ectx) {
    auto raw_arg = get_raw_args<int_size>(ectx);

    int32_t exit_code = get_arg<int32_t>(raw_arg);

    ::_Exit(exit_code);
}
// no atexit
// no at_quick_exit
// int system(const char* command)
void vsystem(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    const char* command = get_arg<const char*>(raw_ptr);

    int32_t ret_val = ::system(command);
    return_value(ret_val, ectx);
}
// char* getenv(const char* env_var)
void vgetenv(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    const char* env_var = get_arg<const char*>(raw_ptr);

    char* ret_str = ::getenv(env_var);
    return_value(ret_str, ectx);
}

// Memory management
// void* malloc(size_t size)
void vmalloc(execution_context& ectx) {
    auto raw_arg = get_raw_args<long_size>(ectx);

    size_t size = get_arg<size_t>(raw_arg);

    void* memblock = ::malloc(size);
    return_value(memblock, ectx);
}
// void* aligned_alloc(size_t alignment, size_t size)
void valigned_malloc(execution_context& ectx) {
    auto raw_args = get_raw_args<2 * long_size>(ectx);

    size_t alignment = get_arg<size_t>(raw_args);
    size_t size = get_arg<size_t, long_size>(raw_args);

    void* memblock = ::aligned_alloc(alignment, size);
    return_value(memblock, ectx);
}
// void* calloc(size_t num, size_t size)
void vcalloc(execution_context& ectx) {
    auto raw_args = get_raw_args<2 * long_size>(ectx);

    size_t num = get_arg<size_t>(raw_args);
    size_t size = get_arg<size_t, long_size>(raw_args);

    void* memblock = ::calloc(num, size);
    return_value(memblock,ectx);
}
// void* realloc(void* ptr, size_t new_size)
void vrealloc(execution_context& ectx) {
    auto raw_args = get_raw_args<ptr_size + long_size>(ectx);

    void* ptr = get_arg<void*>(raw_args);
    size_t size = get_arg<size_t,ptr_size>(raw_args);

    void* memblock = ::realloc(ptr, size);
    return_value(memblock, ectx);
}
// void free(void* ptr)
void vfree(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    void* ptr = get_arg<void*>(raw_ptr);

    ::free(ptr);
}

// Numeric string conversions
// no atof
// int atoi(const char* str)
void vatoi(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    const char* str = get_arg<const char*>(raw_ptr);

    int32_t ret_val = ::atoi(str);
    return_value(ret_val, ectx);
}
// long atol(const char* str)
void vatol(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    const char* str = get_arg<const char*>(raw_ptr);

    int64_t ret_val = ::atol(str);
    return_value(ret_val, ectx);
}
// long long atoll(const char* str)
void vatoll(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    const char* str = get_arg<const char*>(raw_ptr);

    int64_t ret_val = ::atoll(str);
    return_value(ret_val, ectx);
}
// long strtol(const char* str, char** str_end, int base)
void vstrtol(execution_context& ectx) {
    auto raw_args = get_raw_args<2 * ptr_size + int_size>(ectx);

    const char* str = get_arg<const char*>(raw_args);
    char** str_end = get_arg<char**,ptr_size>(raw_args);
    int32_t base = get_arg<int32_t,2 * ptr_size>(raw_args);

    int64_t ret_val = ::strtol(str, str_end, base);
    return_value(ret_val, ectx);
}
// long long strtoll(const char* str, char** str_len, int base)
void vstrtoll(execution_context& ectx) {
    auto raw_args = get_raw_args<2 * ptr_size + int_size>(ectx);

    const char* str = get_arg<const char*>(raw_args);
    char** str_end = get_arg<char**,ptr_size>(raw_args);
    int32_t base = get_arg<int32_t,2 * ptr_size>(raw_args);

    int64_t ret_val = ::strtoll(str, str_end, base);
    return_value(ret_val, ectx);
}
// unsigned long strtoul(const char* str, char** str_end, int base)
void vstrtoul(execution_context& ectx) {
    auto raw_args = get_raw_args<2 * ptr_size + int_size>(ectx);

    const char* str = get_arg<const char*>(raw_args);
    char** str_end = get_arg<char**,ptr_size>(raw_args);
    int32_t base = get_arg<int32_t,2 * ptr_size>(raw_args);

    uint64_t ret_val = ::strtoul(str, str_end, base);
    return_value(ret_val, ectx);
}
// unsigned long long strtoull(const char* str, char** str_end, int base)
void vstrtoull(execution_context& ectx) {
    auto raw_args = get_raw_args<2 * ptr_size + int_size>(ectx);

    const char* str = get_arg<const char*>(raw_args);
    char** str_end = get_arg<char**,ptr_size>(raw_args);
    int32_t base = get_arg<int32_t,2 * ptr_size>(raw_args);

    uint64_t ret_val = ::strtoull(str, str_end, base);
    return_value(ret_val, ectx);
}
// no strtof
// no strtod
// no strtold

// Miscellaneous algorithms and math
// int rand()
void vrand(execution_context& ectx) {
    int32_t r = ::rand();
    return_value(r, ectx);
}
// void srand()
void vsrand(execution_context& ectx) {
    auto raw_arg = get_raw_args<int_size>(ectx);

    uint32_t seed = get_arg<uint32_t>(raw_arg);
    
    ::srand(seed);
}
// no qsort
// no bsearch
// int abs(int num)
void vabs(execution_context& ectx) {
    auto raw_arg = get_raw_args<int_size>(ectx);

    int32_t num = get_arg<int32_t>(raw_arg);

    int32_t absnum = ::abs(num);
    return_value(absnum, ectx);
}
// long labs(long num)
void vlabs(execution_context& ectx) {
    auto raw_arg = get_raw_args<long_size>(ectx);

    int64_t num = get_arg<int64_t>(raw_arg);

    int64_t absnum = ::labs(num);
    return_value(absnum, ectx);
}
// long long llabs(long long num)
void vllabs(execution_context& ectx) {
    auto raw_arg = get_raw_args<long_size>(ectx);

    int64_t num = get_arg<int64_t>(raw_arg);

    int64_t absnum = ::llabs(num);
    return_value(absnum, ectx);
}
// no div
// no ldiv
// no lldiv