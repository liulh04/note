#include <stdio.h>

int graph[20][20]; // 存储图的邻接矩阵
int colors[20]; // 存储每个顶点的颜色
int n, r, m; // 图的顶点数、边数和颜色数
int count = 0; // 着色方案总数

int isSafe(int v, int c) {
    // 判断顶点v是否可以着色为颜色c
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

void backtrack(int v) {
    if (v == n) {
        // 所有顶点都已着色，找到一种合法的着色方案
        count++;
        return;
    }

    for (int i = 0; i < m; i++) {
        if (isSafe(v, i)) {
            // 给当前顶点着色为颜色i
            colors[v] = i;
            // 继续着色下一个顶点
            backtrack(v + 1);
            // 恢复当前顶点的颜色为-1，以便尝试其他颜色
            colors[v] = -1;
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &r, &m);

    // 初始化图的邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // 读取图的边信息
    for (int i = 0; i < r; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // 初始化颜色数组
    for (int i = 0; i < n; i++) {
        colors[i] = -1;
    }

    // 从第一个顶点开始着色
    backtrack(0);

    printf("%d\n", count);

    return 0;
}
