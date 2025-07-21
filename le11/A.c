#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int adjMatrix[100][100] = {0};

    for (int i = 0; i < n; i++) {
        int u, k;
        scanf("%d %d", &u, &k);

        for (int j = 0; j < k; j++) {
             int v;
             scanf("%d", &v);
             adjMatrix[u - 1][v - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}