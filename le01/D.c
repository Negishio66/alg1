#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int r;
    if (n > 0) {
        scanf("%d", &r);
    }

    int min_val = r;
    int max_profit = -2000000001;

    for (int i = 1; i < n; i++) {
        scanf("%d", &r);
        max_profit = max(max_profit, r - min_val);
        min_val = min(min_val, r);
    }

    printf("%d\n", max_profit);

    return 0;
}