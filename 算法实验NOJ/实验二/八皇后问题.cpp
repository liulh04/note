/*
����
���8�ʺ��������н����

����
û�����롣

���
ÿ�������һ����No n������ʽ��n��ʾ������ǵڼ������������8�У�ÿ��8���ַ�����A����ʾ�ʺ󣬡�.����ʾ�ո񡣲�ͬ�Ľ���У��������һ���ʺ�λ�ÿ�ǰ�Ľ������һ���ʺ�λ����ͬ��������ڶ����ʺ�λ�ÿ�ǰ�Ľ�����������ơ�

��������
 ����������

�������
�����ǰ���У�
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

��ʾ
�����������ȷ��������ǰ���С�
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
    // ��鵱ǰλ�õ���
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'A') {
            return 0;
        }
    }

    // ��鵱ǰλ�õ����϶Խ���
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'A') {
            return 0;
        }
    }

    // ��鵱ǰλ�õ����϶Խ���
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
