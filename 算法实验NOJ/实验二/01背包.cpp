/*
描述
需对容量为c 的背包进行装载。从n 个物品中选取装入背包的物品，每件物品i 的重量为wi ，价值为pi 。对于可行的背包装载，背包中物品的总重量不能超过背包的容量，最佳装载是指所装入的物品价值最高。
输入
多个测例，每个测例的输入占三行。第一行两个整数：n（n<=10）和c，第二行n个整数分别是w1到wn，第三行n个整数分别是p1到pn。
n 和 c 都等于零标志输入结束。
输出
每个测例的输出占一行，输出一个整数，即最佳装载的总价值。
输入样例
1 2
1
1
2 3
2 2
3 4
0 0
输出样例
1
4
*/
#include<stdio.h>
//装载函数 
int max(int a,int b){
	return a>=b?a:b;
}
void   bagloading(int n,int c,int wi[],int pi[]){
	
    int dp[11][101] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (wi[i - 1] <= j) {
                dp[i][j] = max(pi[i - 1] + dp[i - 1][j - wi[i - 1]], dp[i - 1][j]);
            } 
			else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d\n",dp[n][c]);
    return ;
}	
 


int main(){
	while(1){
	
	int n,c;
	scanf("%d%d",&n,&c);
	//终止判断 
	if(n==0&&c==0){
		break;
	}
	//读取wi，pi 
	int wi[n];int pi[n];
	for(int i=0;i<n;i++){
		scanf("%d",&wi[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&pi[i]);
	}
	bagloading(n,c,wi,pi);
	
 }
	
	return 0;
}

