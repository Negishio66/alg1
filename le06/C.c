#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define SENTINEL 2000000000 

typedef struct {
    char suit;
    int value;
} Card;

Card L[MAX_N / 2 + 2], R[MAX_N / 2 + 2];

void swap(Card *a, Card *b) {
    Card temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Card A[], int p, int r) {
    Card x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j].value <= x.value) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return i + 1;
}

void quickSort(Card A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

void merge(Card A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1].value = SENTINEL;
    R[n2].value = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(Card A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int n;
    Card quick_sort_cards[MAX_N];
    Card merge_sort_cards[MAX_N];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &quick_sort_cards[i].suit, &quick_sort_cards[i].value);
        merge_sort_cards[i] = quick_sort_cards[i];
    }

    quickSort(quick_sort_cards, 0, n - 1);
    mergeSort(merge_sort_cards, 0, n);

    int stable = 1;
    for (int i = 0; i < n; i++) {
        if (quick_sort_cards[i].suit != merge_sort_cards[i].suit) {
            stable = 0;
            break;
        }
    }

    if (stable) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    for (int i = 0; i < n; i++) {
        printf("%c %d\n", quick_sort_cards[i].suit, quick_sort_cards[i].value);
    }

    return 0;
}