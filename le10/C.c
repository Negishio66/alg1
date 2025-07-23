#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        char X[1001];
        char Y[1001];
        scanf("%s", X);
        scanf("%s", Y);

        int m = strlen(X);
        int n = strlen(Y);

        static int dp[1002][1002];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (X[i - 1] == Y[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        printf("%d\n", dp[m][n]);
    }

    return 0;
}