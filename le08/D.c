#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    int priority;
    struct Node *left, *right;
} Node;

Node *root = NULL;

Node* rightRotate(Node* t) {
    Node* s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

Node* leftRotate(Node* t) {
    Node* s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

Node* insert(Node* t, int key, int priority) {
    if (t == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->priority = priority;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key == t->key) {
        return t;
    }

    if (key < t->key) {
        t->left = insert(t->left, key, priority);
        if (t->priority < t->left->priority) {
            t = rightRotate(t);
        }
    } else {
        t->right = insert(t->right, key, priority);
        if (t->priority < t->right->priority) {
            t = leftRotate(t);
        }
    }
    return t;
}

Node* deleteNode(Node* t, int key) {
    if (t == NULL) {
        return NULL;
    }

    if (key < t->key) {
        t->left = deleteNode(t->left, key);
    } else if (key > t->key) {
        t->right = deleteNode(t->right, key);
    } else {
        if (t->left == NULL && t->right == NULL) {
            free(t);
            return NULL;
        } else if (t->left == NULL) {
            t = leftRotate(t);
            t->left = deleteNode(t->left, key);
        } else if (t->right == NULL) {
            t = rightRotate(t);
            t->right = deleteNode(t->right, key);
        } else {
            if (t->left->priority > t->right->priority) {
                t = rightRotate(t);
                t->right = deleteNode(t->right, key);
            } else {
                t = leftRotate(t);
                t->left = deleteNode(t->left, key);
            }
        }
    }
    return t;
}

Node* find(Node *t, int k) {
    while (t != NULL && k != t->key) {
        if (k < t->key) {
            t = t->left;
        } else {
            t = t->right;
        }
    }
    return t;
}

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


int main() {
    int m, k, p;
    char command[10];

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            scanf("%d %d", &k, &p);
            root = insert(root, k, p);
        } else if (strcmp(command, "find") == 0) {
            scanf("%d", &k);
            if (find(root, k) != NULL) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else if (strcmp(command, "delete") == 0) {
            scanf("%d", &k);
            root = deleteNode(root, k);
        } else if (strcmp(command, "print") == 0) {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }

    return 0;
}