#include <stdio.h>

#define MAX 101
#define NIL -1

int n;
int M[MAX][MAX];
int d[MAX];
int Q[MAX];
int head = 0, tail = 0;

void enqueue(int x) {
    Q[tail] = x;
    tail = (tail + 1) % MAX;
}

int dequeue() {
    int x = Q[head];
    head = (head + 1) % MAX;
    return x;
}

int isEmpty() {
    return head == tail;
}

void bfs(int s) {
    for (int i = 1; i <= n; i++) {
        d[i] = NIL;
    }
    
    d[s] = 0;
    enqueue(s);

    while (!isEmpty()) {
        int u = dequeue();
        for (int v = 1; v <= n; v++) {
            if (M[u][v] == 1 && d[v] == NIL) {
                d[v] = d[u] + 1;
                enqueue(v);
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            M[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int u, k, v;
        scanf("%d %d", &u, &k);
        if (k > 0) {
            for (int j = 0; j < k; j++) {
                scanf("%d", &v);
                M[u][v] = 1;
            }
        }
    }

    bfs(1);

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i, d[i]);
    }

    return 0;
}