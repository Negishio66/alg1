#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4
#define N2 16
#define LIMIT 45

int puzzle[N2];
int space;

const int goal_x[N2] = {3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2};
const int goal_y[N2] = {3, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3};

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int get_manhattan_distance() {
    int dist = 0;
    for (int i = 0; i < N2; i++) {
        if (puzzle[i] == 0) continue;
        int v = puzzle[i];
        int sx = i % N;
        int sy = i / N;
        dist += abs(sx - goal_x[v]) + abs(sy - goal_y[v]);
    }
    return dist;
}

int solve(int depth, int prev_move, int limit) {
    int h = get_manhattan_distance();
    
    if (depth + h > limit) {
        return depth + h;
    }
    
    if (h == 0) {
        return depth;
    }

    int sx = space % N;
    int sy = space / N;
    int min_limit = 1000;

    for (int i = 0; i < 4; i++) {
        if (prev_move != -1 && (prev_move + i == 1 || prev_move + i == 5)) {
            continue;
        }

        int n_sx = sx + dx[i];
        int n_sy = sy + dy[i];

        if (n_sx >= 0 && n_sx < N && n_sy >= 0 && n_sy < N) {
            int new_space = n_sy * N + n_sx;
            
            puzzle[space] = puzzle[new_space];
            puzzle[new_space] = 0;
            space = new_space;

            int res = solve(depth + 1, i, limit);
            
            new_space = sy * N + sx;
            puzzle[space] = puzzle[new_space];
            puzzle[new_space] = 0;
            space = new_space;

            if (res <= limit) {
                return res;
            }
            if(res < min_limit) {
                min_limit = res;
            }
        }
    }
    
    return min_limit;
}


int main() {
    for (int i = 0; i < N2; i++) {
        scanf("%d", &puzzle[i]);
        if (puzzle[i] == 0) {
            space = i;
        }
    }

    int limit = get_manhattan_distance();
    
    while (limit <= LIMIT) {
        int result = solve(0, -1, limit);
        if (result <= limit) {
            printf("%d\n", result);
            break;
        }
        limit = result;
    }

    return 0;
}