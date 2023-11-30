#include <stdio.h>
/*
描述
给定一个单调递增的整数序列，问某个整数是否在序列中。
输入
第一行为一个整数n，表示序列中整数的个数；第二行为n（n不超过10000）个整数；第三行为一个整数m（m不超过50000），表示查询的个数；接下来m行每行一个整数k。
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
int n;//一共n个数
int A[10000];//存下这n个数
int m;//查询的个数
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
    //录入数据
	for (int k = 0; k < m; k++) {
        int hi = n - 1;
        int lo = 0;
        Binsearch(k, lo, hi);
    }
    return 0;
}
