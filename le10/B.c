#include <stdio.h>
#include <limits.h>

long long calculate_min_multiplications(int n, int p[]) {
    long long m[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long q = m[i][k] + m[k + 1][j] + (long long)p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n];
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    if (n <= 0) {
        printf("0\n");
        return 0;
    }

    int p[n + 1];
    int r, c;

    for (int i = 0; i < n; i++) {
        if (scanf("%d %d", &r, &c) != 2) {
            return 1;
        }
        if (i == 0) {
            p[0] = r;
        }
        p[i + 1] = c;
    }

    long long result = calculate_min_multiplications(n, p);

    printf("%lld\n", result);
    
    return 0;
}