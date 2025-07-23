#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define NO_EDGE -1

int graph[MAX_VERTICES][MAX_VERTICES];

int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < n; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int n) {
    int dist[n];
    int sptSet[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);

        if (u == -1) {
            break;
        }

        sptSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] != NO_EDGE && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i, dist[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0 || n > MAX_VERTICES) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = NO_EDGE;
        }
    }

    for (int i = 0; i < n; i++) {
        int u, k;
        scanf("%d %d", &u, &k);
        for (int j = 0; j < k; j++) {
            int v, c;
            scanf("%d %d", &v, &c);
            graph[u][v] = c;
        }
    }

    dijkstra(n);

    return 0;
}