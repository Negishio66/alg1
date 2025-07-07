#include <stdio.h>

#define MAX_NODES 100
#define NIL -1

struct Node {
    int parent;
    int left;
    int right;
};

struct Node T[MAX_NODES];
int D[MAX_NODES], H[MAX_NODES];
int n;

void setDepth(int u, int d) {
    if (u == NIL) {
        return;
    }
    D[u] = d;
    setDepth(T[u].left, d + 1);
    setDepth(T[u].right, d + 1);
}

int setHeight(int u) {
    int h1 = 0, h2 = 0;
    if (T[u].left != NIL) {
        h1 = setHeight(T[u].left) + 1;
    }
    if (T[u].right != NIL) {
        h2 = setHeight(T[u].right) + 1;
    }
    H[u] = (h1 > h2) ? h1 : h2;
    return H[u];
}

int getSibling(int u) {
    if (T[u].parent == NIL) {
        return NIL;
    }
    int p = T[u].parent;
    if (T[p].left == u) {
        return T[p].right;
    } 
    else {
        return T[p].left;
    }
}

void printNode(int u) {
    printf("node %d: ", u);
    printf("parent = %d, ", T[u].parent);
    printf("sibling = %d, ", getSibling(u));

    int deg = 0;
    if (T[u].left != NIL) deg++;
    if (T[u].right != NIL) deg++;
    printf("degree = %d, ", deg);

    printf("depth = %d, ", D[u]);
    printf("height = %d, ", H[u]);

    if (T[u].parent == NIL) {
        printf("root\n");
    } else if (T[u].left == NIL && T[u].right == NIL) {
        printf("leaf\n");
    } else {
        printf("internal node\n");
    }
}

int main() {
    int i, v, l, r, root = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        T[i].parent = NIL;
    }

    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &v, &l, &r);
        T[v].left = l;
        T[v].right = r;
        if (l != NIL) {
            T[l].parent = v;
        }
        if (r != NIL) {
            T[r].parent = v;
        }
    }

    for (i = 0; i < n; i++) {
        if (T[i].parent == NIL) {
            root = i;
            break;
        }
    }

    setDepth(root, 0);
    setHeight(root);

    for (i = 0; i < n; i++) {
        printNode(i);
    }

    return 0;
}