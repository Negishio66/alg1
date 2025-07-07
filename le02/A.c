void printArray(int A[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

int bubbleSort(int A[], int N) {
    int i, j;
    int swap_count = 0;
    
    for (i = 0; i < N; i++) {
        for (j = N - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                swap_count++;
            }
        }
    }
    return swap_count;
}

int main() {
    int N, i, swap_count;

    scanf("%d", &N);

    int A[N]; 

    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    swap_count = bubbleSort(A, N);

    printArray(A, N);
    
    printf("%d\n", swap_count);

    return 0;
}