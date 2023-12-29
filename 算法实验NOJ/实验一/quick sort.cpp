#include<stdio.h>
#include<stdlib.h>
/*
����
����һ�����У��ÿ��������㷨�����ų�����
����
��һ����һ������n(n������10000)����ʾҪ��������ĸ���������һ�����ÿո������n��������
���
������������У�ÿ������ռһ�С�
��������
5
3 2 1 4 5
�������
1
2
3
4
5 
*/
void Quick_Sort(int *arr, int begin, int end){
    if(begin > end)
        return;
    //���ǰָ����ں�ָ�룬���Ѿ�ȫ���ǣ���ֱ���˳� 
    int tmp = arr[begin];   //����key 
    int i = begin;
    int j = end;            //����ǰ��Ƚ�ָ�� 
    while(i != j){             
        while(arr[j] >= tmp && j > i)
            j--;
        while(arr[i] <= tmp && j > i)
            i++;
        if(j > i){
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    arr[begin] = arr[i];
    arr[i] = tmp;
    Quick_Sort(arr, begin, i-1);
    Quick_Sort(arr, i+1, end);
}

 
int main(){
    int n;
    scanf("%d", &n);

    int *A = (int*)malloc(sizeof(int) * n);
     

    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    Quick_Sort(A,0,n-1); 
    

    for(int i = 0; i < n; i++){
        printf("%d\n", A[i]);
    }//����չʾ 

     
    return 0;
	
}
