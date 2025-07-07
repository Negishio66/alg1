#include <stdio.h>

typedef struct Node {
    int parent;
    int left_child;
    int right_sibling;
} Node;

typedef struct Tree {
    Node* nodes;
    int* depths;
    int n;
} Tree;

void set_depth(Tree* tree, int u, int p) {
    tree->depths[u] = p;
    if (tree->nodes[u].right_sibling != -1) {
        set_depth(tree, tree->nodes[u].right_sibling, p);
    }
    if (tree->nodes[u].left_child != -1) {
        set_depth(tree, tree->nodes[u].left_child, p + 1);
    }
}

void print_node(Tree* tree, int u) {
    printf("node %d: ", u);
    printf("parent = %d, ", tree->nodes[u].parent);
    printf("depth = %d, ", tree->depths[u]);

    if (tree->nodes[u].parent == -1) {
        printf("root, ");
    } else if (tree->nodes[u].left_child == -1) {
        printf("leaf, ");
    } else {
        printf("internal node, ");
    }

    printf("[");
    int c = tree->nodes[u].left_child;
    if (c != -1) {
        printf("%d", c);
        c = tree->nodes[c].right_sibling;
        while (c != -1) {
            printf(", %d", c);
            c = tree->nodes[c].right_sibling;
        }
    }
    printf("]\n");
}

int main() {
    int n;
    scanf("%d", &n);

    Tree tree;
    tree.n = n;
    tree.nodes = (Node*)malloc(n * sizeof(Node));
    tree.depths = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        tree.nodes[i].parent = -1;
        tree.nodes[i].left_child = -1;
        tree.nodes[i].right_sibling = -1;
    }

    for (int i = 0; i < n; i++) {
        int id, k, c, prev_c;
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &c);
            if (j == 0) {
                tree.nodes[id].left_child = c;
            } else {
                tree.nodes[prev_c].right_sibling = c;
            }
            tree.nodes[c].parent = id;
            prev_c = c;
        }
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (tree.nodes[i].parent == -1) {
            root = i;
            break;
        }
    }

    set_depth(&tree, root, 0);

    for (int i = 0; i < n; i++) {
        print_node(&tree, i);
    }

    free(tree.nodes);
    free(tree.depths);

    return 0;
}