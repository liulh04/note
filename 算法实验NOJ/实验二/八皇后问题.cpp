/*
描述
输出8皇后问题所有结果。

输入
没有输入。

输出
每个结果第一行是No n：的形式，n表示输出的是第几个结果；下面8行，每行8个字符，‘A’表示皇后，‘.’表示空格。不同的结果中，先输出第一个皇后位置靠前的结果；第一个皇后位置相同，先输出第二个皇后位置靠前的结果；依次类推。

输入样例
 无输入样例

输出样例
输出的前几行：
No 1:
A.......
....A...
.......A
.....A..
..A.....
......A.
.A......
...A....
No 2:
A.......
.....A..
.......A
..A.....
......A.
...A....
.A......
....A...

提示
输出样例是正确输出结果的前几行。
*/
#include <stdio.h>

#define N 8

void printBoard(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    //printf("\n");
}

int isSafe(char board[N][N], int row, int col) {
    // 检查当前位置的列
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'A') {
            return 0;
        }
    }

    // 检查当前位置的左上对角线
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'A') {
            return 0;
        }
    }

    // 检查当前位置的右上对角线
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 'A') {
            return 0;
        }
    }

    return 1;
}

void solveNQueens(char board[N][N], int row, int *solutionCount) {
    if (row == N) {
        (*solutionCount)++;
        printf("No %d:\n", *solutionCount);
        printBoard(board);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 'A';
            solveNQueens(board, row + 1, solutionCount);
            board[row][col] = '.';
        }
    }
}

void findAllSolutions() {
    char board[N][N];
    int solutionCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '.';
        }
    }

    solveNQueens(board, 0, &solutionCount);
}

int main() {
    findAllSolutions();
    return 0;
}
