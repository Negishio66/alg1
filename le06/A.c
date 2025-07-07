#include <stdio.h>

#define MAX_N 2000001
#define MAX_K 10001

int A[MAX_N], B[MAX_N];
int C[MAX_K];
int n;

void countingSort(int A[], int B[], int k) {
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }

    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main() {
    scanf("%d", &n);

    int k = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        if (A[i] > k) {
            k = A[i];
        }
    }

    countingSort(A, B, k);

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}