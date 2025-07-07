long long cnt; 
int A[1000000];
int n;
int m;
int G[100];

void insertionSort(int g) {
    int i;
    for (i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j + g] = v;
    }
}

void shellSort() {
    int h;
    for (h = 1; ; ) {
        if (h > n) break;
        G[m] = h;
        m++;
        h = 3 * h + 1;
    }

    for (int i = m - 1; i >= 0; i--) {
        insertionSort(G[i]);
    }
}

int main() {
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    cnt = 0;
    m = 0;

    shellSort();

    printf("%d\n", m);
    for (i = m - 1; i >= 0; i--) {
        printf("%d", G[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");
    
    printf("%lld\n", cnt);
    
    for (i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }
    
    return 0;
}