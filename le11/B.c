#include <stdio.h>

#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, tt;
int M[MAX][MAX];
int color[MAX], d[MAX], f[MAX];

void dfs_visit(int u) {
    color[u] = GRAY;
    d[u] = ++tt;

    for (int v = 1; v <= n; v++) {
        if (M[u][v] == 1 && color[v] == WHITE) {
            dfs_visit(v);
        }
    }
    color[u] = BLACK;
    f[u] = ++tt;
}

void dfs() {
    for (int i = 1; i <= n; i++) {
        color[i] = WHITE;
    }
    tt = 0;

    for (int u = 1; u <= n; u++) {
        if (color[u] == WHITE) {
            dfs_visit(u);
        }
    }
}

int main() {
    int u, k, v;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            M[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &u, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &v);
            M[u][v] = 1;
        }
    }

    dfs();

    for (int i = 1; i <= n; i++) {
        printf("%d %d %d\n", i, d[i], f[i]);
    }

    return 0;
}