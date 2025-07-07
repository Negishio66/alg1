#include <stdio.h>

#define MAX_N 100000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int p, int r) {
    int x = A[r];

    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    
    swap(&A[i + 1], &A[r]);

    return i + 1;
}

int main() {
    int n;
    int A[MAX_N];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int pivot_index = partition(A, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        if (i == pivot_index) {
            printf("[%d]", A[i]);
        } else {
            printf("%d", A[i]);
        }
    }
    printf("\n");

    return 0;
}