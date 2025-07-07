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

int selectionSort(int A[], int N) {
    int i, j, mini;
    int swap_count = 0;

    for (i = 0; i < N; i++) {
        mini = i;
        for (j = i; j < N; j++) {
            if (A[j] < A[mini]) {
                mini = j;
            }
        }
        if (i != mini) {
            int temp = A[i];
            A[i] = A[mini];
            A[mini] = temp;
            swap_count++;
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

    swap_count = selectionSort(A, N);

    printArray(A, N);
    printf("%d\n", swap_count);

    return 0;
}