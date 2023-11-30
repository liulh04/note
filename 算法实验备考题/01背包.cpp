#include<stdio.h>
int max(int a,int b){
	return a>=b?a:b;
}
void bagloading(int n,int c,int wi[],int pi[]){
	int dp[11][101]={0};
	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c;j++){
			if(wi[i-1]<=j){
				dp[i][j]=max(pi[i-1]+dp[i-1][j-wi[i-1]],dp[i-1][j]);
			}
			else {
				dp[i][j]=dp[i-1][j];
		}

	}	
}
	printf("%d\n",dp[n][c]);
	return ;
	
 
}

int main(){
	int n,c;
	while(1){
		scanf("%d%d",&n,&c);
		if(c==0&&n==0){
			break;
		}
		
		int wi[n];
		int pi[n];
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
