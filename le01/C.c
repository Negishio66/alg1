#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    int count = 0;
    int number;

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &number) != 1) {
            return 1;
        }
        if (isPrime(number)) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}