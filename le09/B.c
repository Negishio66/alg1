#include <stdio.h>
#include <stdlib.h>

int N;
int *A;
int *count;

int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

void precompute_subtree_sizes() {
    for (int i = N; i >= 1; i--) {
        count[i] = 1;
        if (2 * i <= N) count[i] += count[2 * i];
        if (2 * i + 1 <= N) count[i] += count[2 * i + 1];
    }
}

void build_heap_final(int u, int* current_values, int num_vals) {
    if (num_vals <= 0) {
        return;
    }

    A[u] = current_values[0];
    if (num_vals == 1) {
        return;
    }

    int left_child = 2 * u;
    int right_child = 2 * u + 1;
    int left_size = (left_child <= N) ? count[left_child] : 0;
    int right_size = (right_child <= N) ? count[right_child] : 0;

    int* left_vals = (int*)malloc(left_size * sizeof(int));
    int* right_vals = (int*)malloc(right_size * sizeof(int));
    int l_idx = 0, r_idx = 0;

    for (int i = 1; i < num_vals; i++) {
        if (left_size > right_size) {
            left_vals[l_idx++] = current_values[i];
            left_size--;
        } else {
            right_vals[r_idx++] = current_values[i];
            right_size--;
        }
    }

    build_heap_final(left_child, left_vals, l_idx);
    build_heap_final(right_child, right_vals, r_idx);

    free(left_vals);
    free(right_vals);
}

int main() {
    scanf("%d", &N);

    int* initial_values = (int*)malloc(N * sizeof(int));
    A = (int*)malloc((N + 1) * sizeof(int));
    count = (int*)calloc(N + 1, sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &initial_values[i]);
    }

    qsort(initial_values, N, sizeof(int), compare_desc);
    
    precompute_subtree_sizes();
    build_heap_final(1, initial_values, N);

    if (N > 0) {
        printf("%d", A[1]);
        for (int i = 2; i <= N; i++) {
            printf(" %d", A[i]);
        }
    }
    printf("\n");

    free(initial_values);
    free(A);
    free(count);

    return 0;
}