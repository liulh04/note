#include<stdio.h>
#include<math.h> 
/*
����
����һ��С��20��������n��Ҫ�󰴴�С�����˳��������е�nλ����������ÿ����ռһ�С�

����
����һ��С��20��������n��

���
����С�����˳��������е�nλ����������ÿ����ռһ�С�

��������
3

�������
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
