
/*描述
用分治算法生成循环赛日程表（1到2的n次方个人）
输入
一个小于等于7的正整数n
输出
循环赛日程表（1到2的n次方个人）
输入样例
3
输出样例
1 2 3 4 5 6 7 8
2 1 4 3 6 5 8 7
3 4 1 2 7 8 5 6
4 3 2 1 8 7 6 5
5 6 7 8 1 2 3 4
6 5 8 7 2 1 4 3
7 8 5 6 3 4 1 2
8 7 6 5 4 3 2 1
*/

#include<cstdio>
#include<cstdlib>
using namespace std;
 
int a[150][150]={0}; 
 
void Plan(int k)
{
	int i,j,n=2,temp;
	a[1][1]=1;
	a[1][2]=2;
	a[2][1]=2;
	a[2][2]=1;
	for(int t=1;t<k;t++)
	{
		temp=n;
		n=n*2;
		for(i=temp+1;i<=n;i++)
			for(j=1;j<=temp;j++)
				a[i][j]=a[i-temp][j]+temp;
		for(i=1;i<=temp;i++)
			for(j=temp+1;j<=n;j++)
				a[i][j]=a[i+temp][(j+temp)%n];
		for(i=temp+1;i<=n;i++)
			for(j=temp+1;j<=n;j++)
				a[i][j]=a[i-temp][j-temp];
	}			
}
 
int main()
{
	int n,k;
	scanf("%d",&n);
	k=1<<n;          
	Plan(n);
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			printf("%d",a[i][j]);
            if(j==k) printf("\n");
        	else printf(" ");
 	    }
	}
	return 0;
}
