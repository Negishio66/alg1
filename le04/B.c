#include <stdio.h>

int binarySearch(int S[], int n, int key) {
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (S[mid] == key) {
            return 1;
        } else if (S[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}

int main() {
    int n, q;
    int count = 0;
    int i;

    scanf("%d", &n);
    int S[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        int t_key;
        scanf("%d", &t_key);
        if (binarySearch(S, n, t_key)) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}