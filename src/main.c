#include <stdio.h>

int answers[11] = {
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1
};

int hoc(int (*fptr)(int), int n) {
    if (answers[n] > -1) {
        printf("%d is saved = %d\n", n, answers[n]);
        return answers[n];
    } else {
        answers[n] = fptr(n);
        printf("%d is calculated = %d and saved\n", n, answers[n]);
        return answers[n];
    }
}

int factorial(int n) {
    // Base Case:
    if (n == 1) {
        return 1;
    }

    // Multiplying the current N with the previous product
    // of Ns
    return n * hoc(&factorial, n - 1);
}


int main() {
    printf("factorial 5 = %d\n\n", hoc(&factorial, 5));
    printf("factorial 6 = %d\n\n", hoc(&factorial, 6));
    printf("factorial 4 = %d\n\n", hoc(&factorial, 4));
    printf("factorial 10 = %d\n\n", hoc(&factorial, 10));
    return 0;
}
