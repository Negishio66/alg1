#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 1000
#define MAX_W 10000
#define INF_W 10001

int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

long long min_ll(long long a, long long b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int W[MAX_N];
    int S[MAX_N];
    int V[MAX_W + 1];
    bool visited[MAX_N] = {false};
    int global_min = INF_W;

    for (int i = 0; i < n; i++) {
        scanf("%d", &W[i]);
        S[i] = W[i];
        if (W[i] < global_min) {
            global_min = W[i];
        }
    }

    qsort(S, n, sizeof(int), compare_int);

    for (int i = 0; i < n; i++) {
        V[S[i]] = i;
    }

    long long total_cost = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }

        int current_pos = i;
        long long sum_cycle = 0;
        int len_cycle = 0;
        int min_cycle = INF_W;

        while (!visited[current_pos]) {
            visited[current_pos] = true;
            len_cycle++;
            int weight = W[current_pos];
            sum_cycle += weight;
            if (weight < min_cycle) {
                min_cycle = weight;
            }
            current_pos = V[weight];
        }

        if (len_cycle > 1) {
            long long cost1 = sum_cycle + (long long)(len_cycle - 2) * min_cycle;

            long long cost2 = sum_cycle + min_cycle + (long long)(len_cycle + 1) * global_min;
            
            total_cost += min_ll(cost1, cost2);
        }
    }

    printf("%lld\n", total_cost);

    return 0;
}