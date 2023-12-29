#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
 
int main(){
	int n, m;
    double arr1[2000];
	double arr2[2000];
	int i, j;
	double ans, minn;
	while(~scanf("%d%d",&n, &m)){
        
		for(i = 0; i < n; i++){
		    arr1[i] = i*(10000.0/n);
		}
		for(i = 0; i < (m+n); i++){
		    arr2[i] = i*(10000.0/(m+n));
		}
		ans = 0;
		for(i = 0; i < n; i++){
			minn = 10000;
			for(j = 0; j < (m+n); j++){
			    minn = min(minn, fabs(arr1[i]-arr2[j]));
			}
			ans += minn;
		}
		printf("%.4lf\n", ans);
	}
}
