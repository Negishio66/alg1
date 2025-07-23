#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 3
#define N2 9
#define MAX_STATES 362880 // 9!

typedef struct {
    int board[N2];
    int zero_pos;
    int cost;
} State;

State queue[MAX_STATES];
int head = 0, tail = 0;

bool visited[MAX_STATES];
int fact[N2];

const int goal[N2] = {1, 2, 3, 4, 5, 6, 7, 8, 0};

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < N2; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

int state_to_id(int board[]) {
    int id = 0;
    for (int i = 0; i < N2; i++) {
        int count = 0;
        for (int j = i + 1; j < N2; j++) {
            if (board[j] < board[i]) {
                count++;
            }
        }
        id += count * fact[N2 - 1 - i];
    }
    return id;
}

void enqueue(State s) {
    queue[tail++] = s;
}

State dequeue() {
    return queue[head++];
}

int bfs(State initial_state) {
    enqueue(initial_state);
    int initial_id = state_to_id(initial_state.board);
    visited[initial_id] = true;

    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};

    while (head < tail) {
        State current = dequeue();

        if (memcmp(current.board, goal, sizeof(goal)) == 0) {
            return current.cost;
        }

        int zx = current.zero_pos % N;
        int zy = current.zero_pos / N;

        for (int i = 0; i < 4; i++) {
            int nzx = zx + dx[i];
            int nzy = zy + dy[i];

            if (nzx >= 0 && nzx < N && nzy >= 0 && nzy < N) {
                State next = current;
                int next_zero_pos = nzy * N + nzx;
                
                next.board[current.zero_pos] = next.board[next_zero_pos];
                next.board[next_zero_pos] = 0;

                int next_id = state_to_id(next.board);

                if (!visited[next_id]) {
                    visited[next_id] = true;
                    next.zero_pos = next_zero_pos;
                    next.cost = current.cost + 1;
                    enqueue(next);
                }
            }
        }
    }

    return -1;
}

int main() {
    precompute_factorials();
    memset(visited, false, sizeof(visited));

    State initial_state;
    initial_state.cost = 0;

    for (int i = 0; i < N2; i++) {
        scanf("%d", &initial_state.board[i]);
        if (initial_state.board[i] == 0) {
            initial_state.zero_pos = i;
        }
    }

    int result = bfs(initial_state);
    printf("%d\n", result);

    return 0;
}