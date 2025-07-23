#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 2000001

int H[MAX_HEAP_SIZE];
int heap_size;

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest;

    if (l < heap_size && H[l] > H[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r < heap_size && H[r] > H[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&H[i], &H[largest]);
        maxHeapify(largest);
    }
}

int extractMax() {
    if (heap_size < 1) {
        return -1;
    }
    int max = H[0];
    H[0] = H[heap_size - 1];
    heap_size--;
    maxHeapify(0);
    return max;
}

void insert( int key) {
    heap_size++;
    H[heap_size - 1] = key;
    int i = heap_size - 1;
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(&H[i], &H[parent(i)]);
        i = parent(i);
    }
}

int main() {
    int key;
    char command[10];

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "end") == 0) {
            break;
        }
        if (strcmp(command, "insert") == 0) {
            scanf("%d", &key);
            insert(key);
        } else {
            printf("%d\n", extractMax());
        }
    }

    return 0;
}