/*
����
�������Ϊc �ı�������װ�ء���n ����Ʒ��ѡȡװ�뱳������Ʒ��ÿ����Ʒi ������Ϊwi ����ֵΪpi �����ڿ��еı���װ�أ���������Ʒ�����������ܳ������������������װ����ָ��װ�����Ʒ��ֵ��ߡ�
����
���������ÿ������������ռ���С���һ������������n��n<=10����c���ڶ���n�������ֱ���w1��wn��������n�������ֱ���p1��pn��
n �� c ���������־���������
���
ÿ�����������ռһ�У����һ�������������װ�ص��ܼ�ֵ��
��������
1 2
1
1
2 3
2 2
3 4
0 0
�������
1
4
*/
#include<stdio.h>
//װ�غ��� 
int max(int a,int b){
	return a>=b?a:b;
}
void   bagloading(int n,int c,int wi[],int pi[]){
	
    int dp[11][101] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (wi[i - 1] <= j) {
                dp[i][j] = max(pi[i - 1] + dp[i - 1][j - wi[i - 1]], dp[i - 1][j]);
            } 
			else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d\n",dp[n][c]);
    return ;
}	
 


int main(){
	while(1){
	
	int n,c;
	scanf("%d%d",&n,&c);
	//��ֹ�ж� 
	if(n==0&&c==0){
		break;
	}
	//��ȡwi��pi 
	int wi[n];int pi[n];
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

