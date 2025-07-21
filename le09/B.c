#include <stdio.h>

#define MAX 500001

int H;
int A[MAX];

void swap(int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void maxHeapify(int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest;

    if (left <= H && A[left] > A[i]) {
        largest = left;
    } else {
        largest = i;
    }
    if (right <= H && A[right] > A[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(i, largest);
        maxHeapify(largest);
    }
}

void buildMaxHeap() {
    for (int i = H / 2; i >= 1; i--) {
        maxHeapify(i);
    }
}

int main() {
    scanf("%d", &H);

    for (int i = 1; i <= H; i++) {
        scanf("%d", &A[i]);
    }

    buildMaxHeap();

    for (int i = 1; i <= H; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");

    return 0;
}