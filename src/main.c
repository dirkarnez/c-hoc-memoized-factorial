#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int hoc(int (*fptr)(int, int), int c, int d) {
    return fptr(c, d) + 1;
}

// hoc return a function of same signature as add
int main() {
    printf("%d", hoc(&add, 10, 5));

    return 0;
}
