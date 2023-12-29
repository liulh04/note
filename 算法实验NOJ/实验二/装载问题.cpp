/*
描述
有两艘船，载重量分别是c1、 c2，n个集装箱，重量是wi (i=1…n)，且所有集装箱的总重量不超过c1+c2。确定是否有可能将所有集装箱全部装入两艘船。

输入
多个测例，每个测例的输入占两行。第一行一次是c1、c2和n（n<=10）；第二行n个整数表示wi (i=1…n)。n等于0标志输入结束。

输出
对于每个测例在单独的一行内输出Yes或No。

输入样例
7 8 2
8 7
7 9 2
8 8
0 0 0

输出样例
Yes
No

提示
求出不超过c1的最大值max，若总重量－max < c2则能装入到两艘船。
*/
#include <bits/stdc++.h>
using namespace std;
int n; //集装箱数
int cw; // 当前载重量, current weight
int bestw; //最优载重重量
int r;  //剩余集装箱重量
int c1; //第一艘轮船的载重量
int c2; //第二艘轮船的载重量
int x[100]; //当前解
int bestx[100]; //当前最优解
int w[100]; //集装箱重量数组
void OutPut()
{
    int restweight = 0;int wall=0;
    for(int i=1;i<=n;i++){
    	wall += w[i];
	}
    if(bestw <=c1 && ((wall -bestw) <= c2 )){
    	printf("Yes\n");
	}
	else printf("No\n");
}	
void BackTrack(int i)
{
    if(i > n)
    {
        if(cw > bestw)
        {
            for(int i = 1; i <= n; ++i)
                bestx[i] = x[i];
            bestw = cw;
        }
        return;
    }
    r -= w[i];
    if(cw + w[i] <= c1) //约束条件
    {
        cw += w[i];
        x[i] = 1;
        BackTrack(i + 1);
        x[i] = 0;
        cw -= w[i];
    }
    if(cw + r > bestw) //限界函数
    {
        x[i] = 0;
        BackTrack(i + 1);
    }
    r += w[i];

}
 
int main()
{
    while(1){
	
	cin>>c1>>c2;
	cin>>n;
    if(c1==0&&c2==0){
    	break;
	}
	for(int i = 1; i <= n; ++i){	
		cin>>w[i];	
	}
    bestw = 0;
    r = 0;
    cw = 0;
    for(int i = 1; i <= n; ++i)
        r += w[i];   
    BackTrack(1);
    OutPut();
}
}


