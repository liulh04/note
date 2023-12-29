#include<stdio.h>
#include<stdlib.h>
/*
描述
给定一个数列，用快速排序算法把它排成升序。
输入
第一行是一个整数n(n不大于10000)，表示要排序的数的个数；下面一行是用空格隔开的n个整数。
输出
输出排序后的数列，每个数字占一行。
输入样例
5
3 2 1 4 5
输出样例
1
2
3
4
5 
*/
void Quick_Sort(int *arr, int begin, int end){
    if(begin > end)
        return;
    //如果前指针大于后指针，即已经全覆盖，则直接退出 
    int tmp = arr[begin];   //建立key 
    int i = begin;
    int j = end;            //建立前后比较指针 
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
    }//排序展示 

     
    return 0;
	
}
