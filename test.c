#include <stdio.h>
#include <stdlib.h>

__nativedecl(vlibc) int printf(int n);

int sum(int a, int b) {
    a + b;
    // return a + b;
}

int main() {
    //::printf("Hello World!\n");
    //printf("H\n");

    ::printf(3);

    int a = 3;
    //long b = ((a + 2) * 3) + ((a - 5) * (a + 2));

    int c = sum(3 + 2, 4);

    // return 0;
}