#include <stdio.h>

#define MAX 500000

int A[MAX];
int L[MAX/2 + 2], R[MAX/2 + 2];
long long count = 0;

void merge(int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int i, j, k;

    for (i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }

    i = 0;
    j = 0;

    for (k = left; k < right; k++) {
        count++; 
        if (i >= n1) {
            A[k] = R[j];
            j++;
        } else if (j >= n2) {
            A[k] = L[i];
            i++;
        } else if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

int main() {
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    mergeSort(0, n);

    for (i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%lld\n", count);

    return 0;
}