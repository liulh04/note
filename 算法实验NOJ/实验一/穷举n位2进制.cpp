#include<stdio.h>
#include<math.h> 
/*
描述
输入一个小于20的正整数n，要求按从小到大的顺序输出所有的n位二进制数，每个数占一行。

输入
输入一个小于20的正整数n。

输出
按从小到大的顺序输出所有的n位二进制数，每个数占一行。

输入样例
3

输出样例
000
001
010
011
100
101
110
111
*/
int c[20];
void search(int m,int n){
	int i;
	if(m==n){
		for(int i=0;i<n;i++){
			printf("%d",c[i]);
		}
		printf("\n");
		
	}
	else{
		c[m]=0;search(m+1,n);
		c[m]=1;search(m+1,n);
 		
	}
	
	
}

int main(){
	int n;
	scanf("%d",&n);
	int m=0;
	search(m,n);
 	
	return 0;
}
