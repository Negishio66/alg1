#include <stdio.h>

#define MAX 200000
#define SENTINEL 2000000000 

int L[MAX / 2 + 2], R[MAX / 2 + 2];

long long merge(int A[], int n, int left, int mid, int right) {
    long long cnt = 0;
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
            cnt += (n1 - i);
        }
    }
    return cnt;
}

long long mergeSort(int A[], int n, int left, int right) {
    long long v1, v2, v3;
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        v1 = mergeSort(A, n, left, mid);
        v2 = mergeSort(A, n, mid, right);
        v3 = merge(A, n, left, mid, right);
        return v1 + v2 + v3;
    } else {
        return 0;
    }
}

int main() {
    int A[MAX], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    long long ans = mergeSort(A, n, 0, n);
    printf("%lld\n", ans);

    return 0;
}