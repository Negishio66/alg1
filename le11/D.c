#include <stdio.h>

#define MAX_N 100000

int parent[MAX_N];
int set_size[MAX_N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        set_size[i] = 1;
    }
}

int find(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

void unite(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x != root_y) {
        if (set_size[root_x] < set_size[root_y]) {
            parent[root_x] = root_y;
            set_size[root_y] += set_size[root_x];
        } else {
            parent[root_y] = root_x;
            set_size[root_x] += set_size[root_y];
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    init(n);

    for (int i = 0; i < m; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        unite(s, t);
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        if (find(s) == find(t)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}