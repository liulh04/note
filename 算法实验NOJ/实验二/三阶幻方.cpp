#include <stdio.h>

int magicSquare[3][3]; // �洢�÷�����
int visited[10]; // ��¼�����Ƿ��ѱ�ʹ�ù�

void backtrack(int row, int col) {
    if (row == 3 && col == 0) {
        // �÷������������ϣ��ж��Ƿ���������
        int sum = magicSquare[0][0] + magicSquare[0][1] + magicSquare[0][2];
        // �ж϶Խ��ߵĺ��Ƿ�Ϊ15
        if (magicSquare[0][0] + magicSquare[1][1] + magicSquare[2][2] == 15 &&
            magicSquare[0][2] + magicSquare[1][1] + magicSquare[2][0] == 15 &&
            // �ж�ÿһ�еĺ��Ƿ�Ϊ15
            magicSquare[0][0] + magicSquare[0][1] + magicSquare[0][2] == 15 &&
            magicSquare[1][0] + magicSquare[1][1] + magicSquare[1][2] == 15 &&
            magicSquare[2][0] + magicSquare[2][1] + magicSquare[2][2] == 15 &&
            // �ж�ÿһ�еĺ��Ƿ�Ϊ15
            magicSquare[0][0] + magicSquare[1][0] + magicSquare[2][0] == 15 &&
            magicSquare[0][1] + magicSquare[1][1] + magicSquare[2][1] == 15 &&
            magicSquare[0][2] + magicSquare[1][2] + magicSquare[2][2] == 15) {
            // ����÷�����
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
            // ������i���뵱ǰλ��
            magicSquare[row][col] = i;
            visited[i] = 1;
            // ���������һ��λ��
            if (col == 2) {
                backtrack(row + 1, 0);
            } else {
                backtrack(row, col + 1);
            }
            // �ָ���ǰλ�õ�ֵΪ0���Ա㳢����������
            magicSquare[row][col] = 0;
            visited[i] = 0;
        }
    }
}

int main() {
    // ��ʼ���÷������visited����
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            magicSquare[i][j] = 0;
        }
    }
    for (int i = 0; i <= 9; i++) {
        visited[i] = 0;
    }

    // �ӵ�һ��λ�ÿ�ʼ���÷�����
    backtrack(0, 0);

    return 0;
}
