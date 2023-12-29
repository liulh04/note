#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000+50;
int n,dp[maxn];
int main(){
	dp[1]=1;dp[3]=1;dp[5]=1;dp[7]=1;dp[9]=1;dp[11]=1;
	for(int i=12;i<=1000;i++){
		if(dp[i-1]&&dp[i-5]&&dp[i-10])dp[i]=0;
		else dp[i]=1;
	}
	while(1){
		cin>>n;
		if(n==0)break;
		if(dp[n])cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}

