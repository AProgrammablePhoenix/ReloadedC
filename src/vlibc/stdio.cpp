#include <iostream>
#include <vector>
#include <cstdio>

#include "engine/context.hpp"
#include "vlibc/internal_vlibc.hpp"

// operation on files
// int remove(const char* filename)
void vremove(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    const char* data = get_arg<const char*>(raw_ptr);

    int32_t ret_code = ::remove(data);
    return_value(ret_code, ectx);
}
// int rename(const char* old_name, const char* new_name)
void vrename(execution_context& ectx) {
    auto raw_ptrs = get_raw_args<2 * ptr_size>(ectx);

    const char* old_name = get_arg<const char*>(raw_ptrs);
    const char* new_name = get_arg<const char*, ptr_size>(raw_ptrs);

    int32_t ret_code = ::rename(old_name, new_name);
    return_value(ret_code, ectx);
}
// FILE* tmpfile(void)
void vtmpfile(execution_context& ectx) {
    FILE* tmp = ::tmpfile();
    return_value(tmp, ectx);
}
// char* tmpnam(char* str)
void vtmpnam(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    char* str = get_arg<char*>(raw_ptr);

    char* ret_str = ::tmpnam(str);
    return_value(ret_str, ectx);
}

// file access
// int fclose(FILE* stream)
void vfclose(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_ptr);

    int32_t ret_code = ::fclose(stream);
    return_value(ret_code, ectx);
}
// int fflush(FILE* stream)
void vfflush(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_ptr);

    int32_t ret_code = ::fflush(stream);
    return_value(ret_code, ectx);
}
// FILE* fopen (const char* filename, const char* mode)
void vfopen(execution_context& ectx) {
    auto raw_ptrs = get_raw_args<2 * ptr_size>(ectx);

    const char* filename = get_arg<const char*>(raw_ptrs);
    const char* mode = get_arg<const char*, ptr_size>(raw_ptrs);

    FILE* file = ::fopen(filename, mode);
    return_value(file, ectx);
}
// FILE* freopen(const char* filename, const char* mode, FILE* stream)
void vfreopen(execution_context& ectx) {
    auto raw_ptrs = get_raw_args<3 * ptr_size>(ectx);

    const char* filename = get_arg<const char*>(raw_ptrs);
    const char* mode = get_arg<const char*, ptr_size>(raw_ptrs);
    FILE* stream = get_arg<FILE*, 2 * ptr_size>(raw_ptrs);

    FILE* file = ::freopen(filename, mode, stream);
    return_value(file, ectx);
}
// void setbuf(FILE* stream, char* buffer)
void vsetbuf(execution_context& ectx) {
    auto raw_ptrs = get_raw_args<2 * ptr_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_ptrs);
    char* buffer = get_arg<char*, ptr_size>(raw_ptrs);

    ::setbuf(stream, buffer);
}
// int setvbuf(FILE* stream, char* buffer, int mode, size_t size)
void vsetvbuf(execution_context& ectx) {
    auto raw_args = get_raw_args<2 * ptr_size + int_size + long_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_args);
    char* buffer = get_arg<char*, ptr_size>(raw_args);
    int32_t mode = get_arg<int32_t, 2 * ptr_size>(raw_args);
    size_t size = get_arg<size_t, 2 * ptr_size + int_size>(raw_args);

    int32_t ret_code = ::setvbuf(stream, buffer, mode, size);
    return_value(ret_code, ectx);
}

// Direct input/output
// size_t fread(void* buffer, size_t size, size_t count, FILE* stream)
void vfread(execution_context& ectx) {
    auto raw_args = get_raw_args<2 * ptr_size + 2 * long_size>(ectx);

    void* buffer = get_arg<void*>(raw_args);
    size_t size = get_arg<size_t, ptr_size>(raw_args);
    size_t count = get_arg<size_t, ptr_size + long_size>(raw_args);
    FILE* stream = get_arg<FILE*, ptr_size + 2 * long_size>(raw_args);

    size_t ret_val = ::fread(buffer, size, count, stream);
    return_value(ret_val, ectx);
}
// size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream)
void vfwrite(execution_context& ectx) {
    auto raw_args = get_raw_args<2 * ptr_size + 2 * long_size>(ectx);

    const void* buffer = get_arg<const void*>(raw_args);
    size_t size = get_arg<size_t, ptr_size>(raw_args);
    size_t count = get_arg<size_t, ptr_size + long_size>(raw_args);
    FILE* stream = get_arg<FILE*, ptr_size + 2 * long_size>(raw_args);

    size_t ret_val = ::fwrite(buffer, size, count, stream);
    return_value(ret_val, ectx);
}

// Unformatted input/output
// int fgetc(FILE* stream)
void vfgetc(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_ptr);

    int32_t ret_code = ::fgetc(stream);
    return_value(ret_code, ectx);
}
// int getc(FILE* stream)
void vgetc(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_ptr);

    int32_t ret_code = ::getc(stream);
    return_value(ret_code,ectx);
}
// char* fgets(char* str, int count, FILE* stream)
void vfgets(execution_context& ectx) {
    auto raw_args = get_raw_args<2 * ptr_size + int_size>(ectx);

    char* str = get_arg<char*>(raw_args);
    int32_t count = get_arg<int32_t, ptr_size>(raw_args);
    FILE* stream = get_arg<FILE*, ptr_size + int_size>(raw_args);

    char* ret_str = ::fgets(str, count, stream);
    return_value(ret_str, ectx);
}
// int fputc(int ch, FILE* stream)
void vfputc(execution_context& ectx) {
    auto raw_args = get_raw_args<int_size + ptr_size>(ectx);

    int32_t ch = get_arg<int32_t>(raw_args);
    FILE* stream = get_arg<FILE*, int_size>(raw_args);

    int32_t ret_ch = ::fputc(ch, stream);
    return_value(ret_ch, ectx);
}
// int putc(int ch, FILE* stream)
void vputc(execution_context& ectx) {
    auto raw_args = get_raw_args<int_size + ptr_size>(ectx);

    int32_t ch = get_arg<int32_t>(raw_args);
    FILE* stream = get_arg<FILE*, int_size>(raw_args);

    int32_t ret_ch = ::putc(ch, stream);
    return_value(ret_ch, ectx);
}
// int fputs(const char* str, FILE* stream)
void vfputs(execution_context& ectx) {
    auto raw_ptrs = get_raw_args<2 * ptr_size>(ectx);

    const char* str = get_arg<const char*>(raw_ptrs);
    FILE* stream = get_arg<FILE*, ptr_size>(raw_ptrs);

    int32_t ret_code = ::fputs(str, stream);
    return_value(ret_code, ectx);
}
// int getchar(void)
void vgetchar(execution_context& ectx) {
    int32_t ret_ch = ::getchar();
    return_value(ret_ch,ectx);
}
// int putchar(int ch)
void vputchar(execution_context& ectx) {
    auto raw_arg = get_raw_args<int_size>(ectx);

    int32_t ch = get_arg<int32_t>(raw_arg);
    
    int32_t ret_ch = ::putchar(ch);
    return_value(ret_ch, ectx);
}
// int puts(const char* str)
void vputs(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    const char* str = get_arg<const char*>(raw_ptr);

    int32_t ret_code = ::puts(str);
    return_value(ret_code, ectx);
}
// int ungetc(int ch, FILE* stream)
void vungetc(execution_context& ectx) {
    auto raw_args = get_raw_args<int_size + ptr_size>(ectx);

    int32_t ch = get_arg<int32_t>(raw_args);
    FILE* stream = get_arg<FILE*,int_size>(raw_args);
    
    int32_t ret_code = ::ungetc(ch, stream);
    return_value(ret_code, ectx);
}

// No current implementation of Formatted input/output

// File positioning
// long ftell(FILE* stream)
void vftell(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_ptr);

    int64_t _fpos = ::ftell(stream);
    return_value(_fpos, ectx);
}
// int fgetpos(FILE* stream, fpos_t* pos)
void vfgetpos(execution_context& ectx) {
    auto raw_ptrs = get_raw_args<2 * ptr_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_ptrs);
    fpos_t* pos = get_arg<fpos_t*, ptr_size>(raw_ptrs);
    
    int32_t ret_code = ::fgetpos(stream, pos);
    return_value(ret_code, ectx);
}
// int fseek(FILE* stream, long offset, int origin)
void vfseek(execution_context& ectx) {
    auto raw_args = get_raw_args<ptr_size + long_size + int_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_args);
    int64_t offset = get_arg<int64_t,ptr_size>(raw_args);
    int32_t origin = get_arg<int32_t,ptr_size + int_size>(raw_args);

    int32_t ret_code = ::fseek(stream, offset, origin);
    return_value(ret_code, ectx);
}
// int fsetpos(FILE* stream, const fpos_t* pos)
void vfsetpos(execution_context& ectx) {
    auto raw_ptrs = get_raw_args<2 * ptr_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_ptrs);
    const fpos_t* pos = get_arg<const fpos_t*,ptr_size>(raw_ptrs);

    int32_t ret_code = ::fsetpos(stream, pos);
    return_value(ret_code, ectx);
}
// void rewind(FILE* stream)
void vrewind(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_ptr);

    ::rewind(stream);
}

// Error handling
// void clearerr(FILE* stream)
void vclearerr(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_ptr);

    ::clearerr(stream);
}
// int feof(FILE* stream)
void vfeof(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_ptr);

    int32_t ret_val = ::feof(stream);
    return_value(ret_val, ectx);
}
// int ferror(FILE* stream)
void vferror(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    FILE* stream = get_arg<FILE*>(raw_ptr);

    int32_t ret_code = ::ferror(stream);
    return_value(ret_code, ectx);
}
// void perror(const char* s)
void vperror(execution_context& ectx) {
    auto raw_ptr = get_raw_args<ptr_size>(ectx);

    const char* s = get_arg<const char*>(raw_ptr);

    ::perror(s);
}