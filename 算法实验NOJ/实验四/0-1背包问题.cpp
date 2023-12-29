#include <stdio.h>

int max_weight(int n, int c, int weights[]) {
    int dp[n + 1][c + 1];

    // 初始化 dp 数组
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j - weights[i - 1]] + weights[i - 1] > dp[i - 1][j]) ? 
                           (dp[i - 1][j - weights[i - 1]] + weights[i - 1]) : dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][c];
}

int main() {
    int n, c;
    scanf("%d %d", &n, &c);

    int weights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int result = max_weight(n, c, weights);
    printf("%d\n", result);

    return 0;
}
