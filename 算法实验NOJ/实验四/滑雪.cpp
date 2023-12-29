#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
int dp[110][110];
int a[110][110];
int to[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
bool judge(int x,int y)  //判断是否在范围内
{
    if(x>=1&&x<=n&&y>=1&&y<=m)
    return 1;
    else
    return 0;
}
int find(int x,int y)     //找出从该点开始能进行的最大次数
{
    if(dp[x][y])       
    return dp[x][y];
    int d=1,k,tx,ty;
    for(k=0;k<4;k++)
    {
        tx=x+to[k][0];
        ty=y+to[k][1];
        if(judge(tx,ty)&&a[x][y]>a[tx][ty]) 
        d=max(find(tx,ty)+1,d);   
    }
    dp[x][y]=d;  
    return d;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
  	memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        int i,j;
        for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
        int s=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            s=max(find(i,j), s);
        printf("%d\n",s);
    }
    return 0;
}
