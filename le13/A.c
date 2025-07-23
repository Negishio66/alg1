#include <stdio.h>
#include <stdbool.h>

#define N 8

char board[N][N];
bool row[N];
bool dpos[2 * N - 1];
bool dneg[2 * N - 1];

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

bool solveNQueens(int col) {
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (board[i][col] == 'Q') {
            if (solveNQueens(col + 1)) {
                return true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (!row[i] && !dpos[i + col] && !dneg[i - col + (N - 1)]) {
            board[i][col] = 'Q';
            row[i] = dpos[i + col] = dneg[i - col + (N - 1)] = true;

            if (solveNQueens(col + 1)) {
                return true;
            }

            board[i][col] = '.';
            row[i] = dpos[i + col] = dneg[i - col + (N - 1)] = false;
        }
    }

    return false;
}

int main() {
    int k;
    scanf("%d", &k);

    for (int i = 0; i < N; i++) {
        row[i] = false;
        for (int j = 0; j < N; j++) {
            board[i][j] = '.';
        }
    }
    for (int i = 0; i < 2 * N - 1; i++) {
        dpos[i] = dneg[i] = false;
    }

    for (int i = 0; i < k; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        board[r][c] = 'Q';
        row[r] = true;
        dpos[r + c] = true;
        dneg[r - c + (N - 1)] = true;
    }

    if (solveNQueens(0)) {
        printBoard();
    }

    return 0;
}