#include <stdio.h>

#define MAX_ROWS 20
#define MAX_COLS 20

int maze[MAX_ROWS][MAX_COLS];
int visited[MAX_ROWS][MAX_COLS];
int rows, cols;

int is_valid(int row, int col) {
    return (row >= 0 && row < rows && col >= 0 && col < cols && maze[row][col] == 0 && visited[row][col] == 0);
}

int can_reach_exit(int row, int col, int exit_row, int exit_col) {
    if (row == exit_row && col == exit_col) {
        return 1; // Reached the exit
    }

    visited[row][col] = 1;

    // Try moving in all four directions
    if (is_valid(row - 1, col) && can_reach_exit(row - 1, col, exit_row, exit_col)) {
        return 1;
    }
    if (is_valid(row + 1, col) && can_reach_exit(row + 1, col, exit_row, exit_col)) {
        return 1;
    }
    if (is_valid(row, col - 1) && can_reach_exit(row, col - 1, exit_row, exit_col)) {
        return 1;
    }
    if (is_valid(row, col + 1) && can_reach_exit(row, col + 1, exit_row, exit_col)) {
        return 1;
    }

    return 0; // Cannot reach the exit
}

int main() {
    int start_row, start_col, exit_row, exit_col;

    // Read input
    scanf("%d %d", &rows, &cols);
    scanf("%d %d", &start_row, &start_col);
    scanf("%d %d", &exit_row, &exit_col);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
            visited[i][j] = 0;
        }
    }

    // Check if the exit is reachable from the start position
    if (can_reach_exit(start_row, start_col, exit_row, exit_col)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
