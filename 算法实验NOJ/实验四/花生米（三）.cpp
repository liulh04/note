#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000+50;
int n,dp[maxn][maxn];
int min(int x,int y){
    if(x<=y)return x;
    return y;
}
int dfs(int res,int c){
    int i;
    if(res==1){
        dp[res][c]=0;
        return 0;
    }
    if(dp[res][c]!=-1)return dp[res][c];
    int sign=1;
    for(i=1;i<=2*c;i++){
    	if(i>res)break;
        sign=sign&dfs(res-i,i);//下一个dfs就是Jerry先手的状态了，必须全部为1，才能使得当前dfs中的为后手必胜 
        if(sign==0)break;
    }
    dp[res][c]=0;
    if(sign==0)
    dp[res][c]=1;
    return dp[res][c];
}
int main(){
    int i,j;
    while(1){
        cin>>n;
        if(n==1){
        	cout<<0<<endl;
        	continue;
		}
        if(n==0)break;
        for(i=0;i<=1000;i++){
            for(j=0;j<=1000;j++){
                dp[i][j]=-1;
            }
        }
        cout<<1-dfs(n-1,1)<<endl;
    }
}


