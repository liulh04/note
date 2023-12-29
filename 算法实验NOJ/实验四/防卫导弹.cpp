#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000+50;
int n,h[maxn],dp[maxn];
int max(int x,int y){
	if(x>=y)return x;
	return y;
}
int cmp(int x,int y){
	return x>y;
}
int main(){
	int i;
	while(1){
		cin>>n;
		if(n==0)break;
		for(i=1;i<=n;i++)cin>>h[i],dp[i]=0;
		int ans=0;
		for(i=1;i<=n;i++){
			int t=upper_bound(dp+1,dp+1+n,h[i],cmp)-dp;
			dp[t]=h[i];
			ans=max(ans,t);
		}
		cout<<ans<<endl;		
	}
	return 0;
}


