#include <stdio.h>

int main() {
    int n, q;
    int count = 0;
    int i, j;

    scanf("%d", &n);
    int S[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    int T_val;

    for (i = 0; i < q; i++) {
        scanf("%d", &T_val);
        for (j = 0; j < n; j++) {
            if (S[j] == T_val) {
                count++;
                break;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}