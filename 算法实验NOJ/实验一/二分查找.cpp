#include<stdio.h> 
/*����
����һ�������������������У���ĳ�������Ƿ��������С�
����
��һ��Ϊһ������n����ʾ�����������ĸ������ڶ���Ϊn��n������10000����������
������Ϊһ������m��m������50000������ʾ��ѯ�ĸ�����������m��ÿ��һ������k��
���
ÿ����ѯ�����ռһ�У����k�������У����Yes���������No��
��������
5
1 3 4 7 11
3
3
6
9
�������
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
	//ɨ��	
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
