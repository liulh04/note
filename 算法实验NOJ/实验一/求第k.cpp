#include <stdio.h>
/*
描述
求第k小数

输入
先输入一个小于10000的正整数n，再输入n个整数，最后输入一个小于等于n的正整数k，

输出
输出其中第k小的数。

输入样例
5
2 98 34512 8492 1000
2

输出样例
98
*/
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int qs(int arr[], int low, int high, int k) {
    if (low <= high) {
        int p = partition(arr, low, high);

        if (p == k - 1)
            return arr[p];
        else if (p > k - 1)
            return qs(arr, low, p - 1, k);
        else
            return qs(arr, p + 1, high, k);
    }

    return -1; 
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[10000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    int result = qs(arr, 0, n - 1, k);
    printf("%d\n", result);

    return 0;
}

