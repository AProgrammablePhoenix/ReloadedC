__nativedecl(vlibc) int remove(const char* filename);
__nativedecl(vlibc) int rename(const char* old_name, const char* new_name);
//__nativedecl(vlibc) FILE* tmpfile();
__nativedecl(vlibc) char* tmpnam(char* str);
//__nativedecl(vlibc) int fclose(FILE* stream);
//__nativedecl(vlibc) int fflush(FILE* stream);
//__nativedecl(vlibc) FILE* fopen(const char* filename, const char* mode);
//__nativedecl(vlibc) FILE* freopen(const char* filename, const char* mode, FILE* stream);
//__nativedecl(vlibc) void setbuf(FILE* stream, char* buffer);
//__nativedecl(vlibc) int setvbuf(FILE* stream, char* buffer, int mode, size_t size);
//__nativedecl(vlibc) size_t fread(void* buffer, size_t size, size_t count, FILE* stream);
//__nativedecl(vlibc) size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
//__nativedecl(vlibc) int fgetc(FILE* stream);
//__nativedecl(vlibc) int getc(FILE* stream);
//__nativedecl(vlibc) char* fgets(char* str, int count, FILE* stream);
//__nativedecl(vlibc) int fputc(int ch, FILE* stream);
//__nativedecl(vlibc) int putc(int ch, FILE* stream);
//__nativedecl(vlibc) int fputs(const char* str, FILE* stream);
__nativedecl(vlibc) int getchar();
__nativedecl(vlibc) int putchar(int ch);
__nativedecl(vlibc) int puts(const char* str);
//__nativedecl(vlibc) int ungetc(int ch, FILE* stream):
//__nativedecl(vlibc) long ftell(FILE* stream);
//__nativedecl(vlibc) int fgetpos(FILE* stream, fpos_t* pos);
//__nativedecl(vlibc) int fseek(FILE* stream, long offset, int origin);
//__nativedecl(vlibc) int setpos(FILE* stream, fpos_t* pos);
//__nativedecl(vlibc) void rewind(FILE* stream);
//__nativedecl(vlibc) void clearerr(FILE* stream);
//__nativedecl(vlibc) int feof(FILE* stream);
//__nativedecl(vlibc) int ferror(FILE* stream);
//__nativedecl(vlibc) void perror(const char* s);
