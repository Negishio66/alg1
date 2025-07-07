#include <stdio.h>

#define NAME_LEN 11
#define MAX_N 100001

typedef struct {
    char name[NAME_LEN];
    int time;
} Process;

Process queue[MAX_N];
int head, tail;

void enqueue(Process p) {
    queue[tail] = p;
    tail = (tail + 1) % MAX_N;
}

Process dequeue() {
    Process p = queue[head];
    head = (head + 1) % MAX_N;
    return p;
}

int main() {
    int n, q;
    int i;
    int elapsed_time = 0;

    scanf("%d %d", &n, &q);

    for (i = 0; i < n; i++) {
        scanf("%s %d", queue[i].name, &queue[i].time);
    }
    head = 0;
    tail = n;

    while (head != tail) {
        Process current_process = dequeue();

        if (current_process.time > q) {
            elapsed_time += q;
            current_process.time -= q;
            enqueue(current_process);
        } else {
            elapsed_time += current_process.time;
            printf("%s %d\n", current_process.name, elapsed_time);
        }
    }

    return 0;
}