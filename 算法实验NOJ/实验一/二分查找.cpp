#include<stdio.h> 
/*描述
给定一个单调递增的整数序列，问某个整数是否在序列中。
输入
第一行为一个整数n，表示序列中整数的个数；第二行为n（n不超过10000）个整数；
第三行为一个整数m（m不超过50000），表示查询的个数；接下来m行每行一个整数k。
输出
每个查询的输出占一行，如果k在序列中，输出Yes，否则输出No。
输入样例
5
1 3 4 7 11
3
3
6
9
输出样例
Yes
No
No
*/

int main(){
    int n;
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
		}	
	int m;
	scanf("%d",&m);
 	int x[m];		 
	for(int i=0;i<m;i++){
	  scanf("%d",&x[i]);
	}
	//扫描	
	for(int b=0;b<m;b++){
		int flag=0;
		for(int j=0;j<n;j++){
	  	if(A[j]==x[b]){
		  flag=1;
		  break;
		  }
		}
	  if(flag==1){
	  	printf("Yes\n");
	  }
	  else{
	  	printf("No\n");
	  }
		}


	
 
	return 0;
} 
