#include <stdio.h>

#define MAX_NODES 25
#define NIL -1

typedef struct {
    int parent;
    int left;
    int right;
} Node;

Node T[MAX_NODES];

void preOrder(int u) {
    if (u == NIL) return;
    printf(" %d", u);
    preOrder(T[u].left);
    preOrder(T[u].right);
}

void inOrder(int u) {
    if (u == NIL) return;
    inOrder(T[u].left);
    printf(" %d", u);
    inOrder(T[u].right);
}

void postOrder(int u) {
    if (u == NIL) return;
    postOrder(T[u].left);
    postOrder(T[u].right);
    printf(" %d", u);
}

int main() {
    int n, i, id, l, r, root;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        T[i].parent = NIL;
    }

    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &id, &l, &r);
        T[id].left = l;
        T[id].right = r;
        if (l != NIL) {
            T[l].parent = id;
        }
        if (r != NIL) {
            T[r].parent = id;
        }
    }

    for (i = 0; i < n; i++) {
        if (T[i].parent == NIL) {
            root = i;
            break;
        }
    }

    printf("Preorder\n");
    preOrder(root);
    printf("\n");

    printf("Inorder\n");
    inOrder(root);
    printf("\n");

    printf("Postorder\n");
    postOrder(root);
    printf("\n");

    return 0;
}