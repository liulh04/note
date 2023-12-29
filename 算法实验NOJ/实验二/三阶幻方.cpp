#include <stdio.h>

int magicSquare[3][3]; // 存储幻方矩阵
int visited[10]; // 记录数字是否已被使用过

void backtrack(int row, int col) {
    if (row == 3 && col == 0) {
        // 幻方矩阵已填充完毕，判断是否满足条件
        int sum = magicSquare[0][0] + magicSquare[0][1] + magicSquare[0][2];
        // 判断对角线的和是否为15
        if (magicSquare[0][0] + magicSquare[1][1] + magicSquare[2][2] == 15 &&
            magicSquare[0][2] + magicSquare[1][1] + magicSquare[2][0] == 15 &&
            // 判断每一行的和是否为15
            magicSquare[0][0] + magicSquare[0][1] + magicSquare[0][2] == 15 &&
            magicSquare[1][0] + magicSquare[1][1] + magicSquare[1][2] == 15 &&
            magicSquare[2][0] + magicSquare[2][1] + magicSquare[2][2] == 15 &&
            // 判断每一列的和是否为15
            magicSquare[0][0] + magicSquare[1][0] + magicSquare[2][0] == 15 &&
            magicSquare[0][1] + magicSquare[1][1] + magicSquare[2][1] == 15 &&
            magicSquare[0][2] + magicSquare[1][2] + magicSquare[2][2] == 15) {
            // 输出幻方矩阵
            for (int i = 0; i < 3; i++) {

                    int j=0;
                    printf("%d ", magicSquare[i][j]);
                    printf("%d ", magicSquare[i][j+1]);
                    printf("%d", magicSquare[i][j+2]);
                
                printf("\n");
            }
            printf("\n");
        }
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (!visited[i]) {
            // 将数字i填入当前位置
            magicSquare[row][col] = i;
            visited[i] = 1;
            // 继续填充下一个位置
            if (col == 2) {
                backtrack(row + 1, 0);
            } else {
                backtrack(row, col + 1);
            }
            // 恢复当前位置的值为0，以便尝试其他数字
            magicSquare[row][col] = 0;
            visited[i] = 0;
        }
    }
}

int main() {
    // 初始化幻方矩阵和visited数组
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            magicSquare[i][j] = 0;
        }
    }
    for (int i = 0; i <= 9; i++) {
        visited[i] = 0;
    }

    // 从第一个位置开始填充幻方矩阵
    backtrack(0, 0);

    return 0;
}
