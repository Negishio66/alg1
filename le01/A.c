#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void insertionSort(int A[], int N) {
    printArray(A, N);
    for (int i = 1; i < N; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
        printArray(A, N);
    }
}

int main() {
    int N;

    if (scanf("%d", &N) != 1 || N <= 0) {
        return 1;
    }

    int *A = (int *)malloc(N * sizeof(int));
    if (A == NULL) {
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &A[i]) != 1) {
            free(A);
            return 1;
        }
    }

    insertionSort(A, N);

    free(A);

    return 0;
}
