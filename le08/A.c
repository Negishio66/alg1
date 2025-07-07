#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    long long key;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;

Node *root = NULL;

void insert(long long k) {
    Node *z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;

    Node *y = NULL;
    Node *x = root;

    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if (y == NULL) {
        root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

void preorder(Node *u) {
    if (u == NULL) return;
    printf(" %lld", u->key);
    preorder(u->left);
    preorder(u->right);
}

void inorder(Node *u) {
    if (u == NULL) return;
    inorder(u->left);
    printf(" %lld", u->key);
    inorder(u->right);
}

void free_tree(Node *u) {
    if (u == NULL) return;
    free_tree(u->left);
    free_tree(u->right);
    free(u);
}

int main() {
    int n;
    scanf("%d", &n);

    char command[10];
    long long key;

    for (int i = 0; i < n; i++) {
        scanf("%s", command);

        if (strcmp(command, "insert") == 0) {
            scanf("%lld", &key);
            insert(key);
        } else if (strcmp(command, "print") == 0) {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }

    free_tree(root);

    return 0;
}