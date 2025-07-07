#include <stdio.h>

int n;
int k;
int w[100001];

int check(long long P) {
    int trucks_used = 1;
    long long current_truck_load = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (current_truck_load + w[i] <= P) {
            current_truck_load += w[i];
        } else {
            trucks_used++;
            current_truck_load = w[i];
        }
    }
    
    return trucks_used <= k;
}

int main() {
    scanf("%d %d", &n, &k);

    long long total_weight = 0;
    int max_weight = 0;
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        if (w[i] > max_weight) {
            max_weight = w[i];
        }
        total_weight += w[i];
    }

    long long left = max_weight;
    long long right = total_weight;
    long long answer = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    printf("%lld\n", answer);

    return 0;
}