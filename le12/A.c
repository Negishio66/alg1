#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int n) {
    int parent[n];
    int key[n];
    int mstSet[n];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        int u = minKey(key, mstSet, n);
        
        if (u == -1) {
            break;
        }

        mstSet[u] = 1;

        totalWeight += key[u];

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != -1 && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0 || n > MAX_VERTICES) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(n);

    return 0;
}