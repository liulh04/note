#include <stdio.h>
/*
����
����һ�������������������У���ĳ�������Ƿ��������С�
����
��һ��Ϊһ������n����ʾ�����������ĸ������ڶ���Ϊn��n������10000����������������Ϊһ������m��m������50000������ʾ��ѯ�ĸ�����������m��ÿ��һ������k��
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
int n;//һ��n����
int A[10000];//������n����
int m;//��ѯ�ĸ���
int B[50000];


void Binsearch(int k,int lo,int hi){
	if(lo>hi){
        printf("No\n");
        return;
    }
    int f=B[k];
    int mid=(lo+hi)/2;

    if(A[mid]==f){
        printf("Yes\n");
        return;
    }
    

    else if (f>A[mid]){
        lo=mid+1;
        Binsearch(k,lo,hi);
        return;

    }

    if(f<A[mid]){
        hi=mid-1;
        Binsearch(k,lo,hi);
        return ;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }
    //¼������
	for (int k = 0; k < m; k++) {
        int hi = n - 1;
        int lo = 0;
        Binsearch(k, lo, hi);
    }
    return 0;
}
