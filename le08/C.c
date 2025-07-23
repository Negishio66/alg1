#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node *parent, *left, *right;
} Node;

Node *root = NULL;

void inorder(Node *u) {
    if (u == NULL) return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u) {
    if (u == NULL) return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

void insert(int k) {
    Node *y = NULL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NULL;
    z->right = NULL;

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

Node* find(int k) {
    Node *x = root;
    while (x != NULL && k != x->key) {
        if (k < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

Node* treeMinimum(Node* x) {
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

void transplant(Node *u, Node *v) {
    if (u->parent == NULL) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}

void treeDelete(Node *z) {
    if (z->left == NULL) {
        transplant(z, z->right);
    } else if (z->right == NULL) {
        transplant(z, z->left);
    } else {
        Node *y = treeMinimum(z->right);
        if (y->parent != z) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    free(z);
}

int main() {
    int m, k;
    char command[10];

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            scanf("%d", &k);
            insert(k);
        } else if (strcmp(command, "find") == 0) {
            scanf("%d", &k);
            if (find(k) != NULL) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else if (strcmp(command, "delete") == 0) {
            scanf("%d", &k);
            Node *target = find(k);
            if (target != NULL) {
                treeDelete(target);
            }
        } else if (strcmp(command, "print") == 0) {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }

    return 0;
}