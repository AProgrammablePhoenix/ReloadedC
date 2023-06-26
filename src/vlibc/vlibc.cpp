#include <iostream>
#include <unordered_map>

#include "vlibc.hpp"

#define vlibc_f(f) { #f, v##f }

// stdlib.h
void vabort(execution_context& ectx);
void vexit(execution_context& ectx);
void vquick_exit(execution_context& ectx);
void v_Exit(execution_context& ectx);
void vsystem(execution_context& ectx);
void vgetenv(execution_context& ectx);
void vmalloc(execution_context& ectx);
void valigned_malloc(execution_context& ectx);
void vcalloc(execution_context& ectx);
void vrealloc(execution_context& ectx);
void vfree(execution_context& ectx);
void vatoi(execution_context& ectx);
void vatol(execution_context& ectx);
void vatoll(execution_context& ectx);
void vstrtol(execution_context& ectx);
void vstrtoll(execution_context& ectx);
void vstrtoul(execution_context& ectx);
void vstrtoull(execution_context& ectx);
void vrand(execution_context& ectx);
void vsrand(execution_context& ectx);
void vabs(execution_context& ectx);
void vlabs(execution_context& ectx);
void vllabs(execution_context& ectx);

// stdio.h
void vfopen(execution_context& ectx);
void vfreopen(execution_context& ectx);
void vfclose(execution_context& ectx);
void vfflush(execution_context& ectx);
void vsetbuf(execution_context& ectx);
void vsetvbuf(execution_context& ectx);
void vfread(execution_context& ectx);
void vfwrite(execution_context& ectx);
void vfgetc(execution_context& ectx);
void vgetc(execution_context& ectx);
void vfgets(execution_context& ectx);
void vfputc(execution_context& ectx);
void vputc(execution_context& ectx);
void vfputs(execution_context& ectx);
void vgetchar(execution_context& ectx);
void vputchar(execution_context& ectx);
void vputs(execution_context& ectx);
void vungetc(execution_context& ectx);
void vftell(execution_context& ectx);
void vfgetpos(execution_context& ectx);
void vfseek(execution_context& ectx);
void vfsetpos(execution_context& ectx);
void vrewind(execution_context& ectx);
void vclearerr(execution_context& ectx);
void vfeof(execution_context& ectx);
void vferror(execution_context& ectx);
void vperror(execution_context& ectx);
void vremove(execution_context& ectx);
void vrename(execution_context& ectx);
void vtmpfile(execution_context& ectx);
void vtmpnam(execution_context& ectx);

namespace {
    static const std::unordered_map<std::string, void(*)(execution_context&)> vlibc_map = {
        // stdlib.h
        vlibc_f(abort),
        vlibc_f(exit),
        vlibc_f(quick_exit),
        vlibc_f(_Exit),
        vlibc_f(system),
        vlibc_f(getenv),
        vlibc_f(malloc),
        vlibc_f(aligned_malloc),
        vlibc_f(calloc),
        vlibc_f(realloc),
        vlibc_f(free),
        vlibc_f(atoi),
        vlibc_f(atol),
        vlibc_f(atoll),
        vlibc_f(strtol),
        vlibc_f(strtoll),
        vlibc_f(strtoul),
        vlibc_f(strtoull),
        vlibc_f(rand),
        vlibc_f(srand),
        vlibc_f(abs),
        vlibc_f(labs),
        vlibc_f(llabs),

        // stdio.h
        vlibc_f(fopen),
        vlibc_f(freopen),
        vlibc_f(fclose),
        vlibc_f(fflush),
        vlibc_f(setbuf),
        vlibc_f(setvbuf),
        vlibc_f(fread),
        vlibc_f(fwrite),
        vlibc_f(fgetc),
        vlibc_f(getc),
        vlibc_f(fgets),
        vlibc_f(fputc),
        vlibc_f(putc),
        vlibc_f(fputs),
        vlibc_f(getchar),
        vlibc_f(putchar),
        vlibc_f(puts),
        vlibc_f(ungetc),
        vlibc_f(ftell),
        vlibc_f(fgetpos),
        vlibc_f(fseek),
        vlibc_f(fsetpos),
        vlibc_f(rewind),
        vlibc_f(clearerr),
        vlibc_f(feof),
        vlibc_f(ferror),
        vlibc_f(perror),
        vlibc_f(remove),
        vlibc_f(rename),
        vlibc_f(tmpfile),
        vlibc_f(tmpnam)
    };
}

bool vlibc_handler(const std::string& symbol, execution_context& ectx) {
    if (!vlibc_map.count(symbol)) {
        return false;
    }

    vlibc_map.at(symbol)(ectx);

    return true;
}