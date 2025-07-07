typedef struct {
    char suit;
    int value;
} Card;

void printCards(Card C[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%c%d", C[i].suit, C[i].value);
    }
    printf("\n");
}

void bubbleSort(Card C[], int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = N - 1; j > i; j--) {
            if (C[j].value < C[j - 1].value) {
                Card temp = C[j];
                C[j] = C[j - 1];
                C[j - 1] = temp;
            }
        }
    }
}

void selectionSort(Card C[], int N) {
    int i, j, mini;
    for (i = 0; i < N; i++) {
        mini = i;
        for (j = i; j < N; j++) {
            if (C[j].value < C[mini].value) {
                mini = j;
            }
        }
        if (i != mini) {
            Card temp = C[i];
            C[i] = C[mini];
            C[mini] = temp;
        }
    }
}

int isStable(Card original[], Card sorted[], int N) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            if (original[i].value == original[j].value) {
                int pos1 = -1, pos2 = -1;
                for (k = 0; k < N; k++) {
                    if (sorted[k].suit == original[i].suit && sorted[k].value == original[i].value) {
                        pos1 = k;
                    }
                    if (sorted[k].suit == original[j].suit && sorted[k].value == original[j].value) {
                        pos2 = k;
                    }
                }
                if (pos1 > pos2) {
                    return 0; // Not stable
                }
            }
        }
    }
    return 1; // Stable
}

int main() {
    int N;
    Card C1[36], C2[36], C_original[36];
    char str[3];
    int i;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%s", str);
        C1[i].suit = str[0];
        C1[i].value = str[1] - '0';

        C2[i] = C1[i];
        C_original[i] = C1[i];
    }

    bubbleSort(C1, N);
    printCards(C1, N);
    if (isStable(C_original, C1, N)) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    selectionSort(C2, N);
    printCards(C2, N);
    if (isStable(C_original, C2, N)) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    return 0;
}