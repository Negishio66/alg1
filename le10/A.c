#include <stdio.h>

#define MAX_N 44

int mem[MAX_N];

int fibonacci(int n) {

    if (n <= 1) {
        return 1;
    }
    if (mem[n] != 0) {
        return mem[n];
    }

    mem[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return mem[n];
}

int main() {
    int n;

    scanf("%d",&n);
    int result = fibonacci(n);

    printf("%d\n", result);

    return 0;
}