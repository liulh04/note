#include <stdio.h>

int graph[20][20]; // �洢ͼ���ڽӾ���
int colors[20]; // �洢ÿ���������ɫ
int n, r, m; // ͼ�Ķ���������������ɫ��
int count = 0; // ��ɫ��������

int isSafe(int v, int c) {
    // �ж϶���v�Ƿ������ɫΪ��ɫc
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

void backtrack(int v) {
    if (v == n) {
        // ���ж��㶼����ɫ���ҵ�һ�ֺϷ�����ɫ����
        count++;
        return;
    }

    for (int i = 0; i < m; i++) {
        if (isSafe(v, i)) {
            // ����ǰ������ɫΪ��ɫi
            colors[v] = i;
            // ������ɫ��һ������
            backtrack(v + 1);
            // �ָ���ǰ�������ɫΪ-1���Ա㳢��������ɫ
            colors[v] = -1;
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &r, &m);

    // ��ʼ��ͼ���ڽӾ���
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // ��ȡͼ�ı���Ϣ
    for (int i = 0; i < r; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // ��ʼ����ɫ����
    for (int i = 0; i < n; i++) {
        colors[i] = -1;
    }

    // �ӵ�һ�����㿪ʼ��ɫ
    backtrack(0);

    printf("%d\n", count);

    return 0;
}
