#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *next, *prev;
} Node;

Node *nil;

void init() {
    nil = (Node *)malloc(sizeof(Node));
    if (nil == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    nil->next = nil;
    nil->prev = nil;
}

void insert(int key) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->key = key;
    
    newNode->next = nil->next;
    nil->next->prev = newNode;
    nil->next = newNode;
    newNode->prev = nil;
}

void deleteNode(Node *t) {
    if (t == nil) return;
    
    t->prev->next = t->next;
    t->next->prev = t->prev;
    
    free(t);
}

void deleteFirst() {
    deleteNode(nil->next);
}

void deleteLast() {
    deleteNode(nil->prev);
}

void deleteKey(int key) {
    Node *current = nil->next;
    while(current != nil && current->key != key) {
        current = current->next;
    }
    if (current != nil) {
        deleteNode(current);
    }
}

void printList() {
    Node *current = nil->next;
    int isFirst = 1;
    while (current != nil) {
        if (!isFirst) {
            printf(" ");
        }
        printf("%d", current->key);
        isFirst = 0;
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n, key;
    char command[20];
    
    init();
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        
        if (command[0] == 'i') {
            scanf("%d", &key);
            insert(key);
        } else if (command[0] == 'd') {
            if (command[6] == 'F') {
                deleteFirst();
            } else if (command[6] == 'L') {
                deleteLast();
            } else {
                scanf("%d", &key);
                deleteKey(key);
            }
        }
    }
    
    printList();
    
    free(nil);
    
    return 0;
}