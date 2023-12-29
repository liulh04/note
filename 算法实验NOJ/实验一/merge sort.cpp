#include<stdio.h>
#include<stdlib.h>
/*����
����һ�����У��ù鲢�����㷨�����ų�����
����
��һ����һ������n��n������10000������ʾҪ��������ĸ�����
����һ�����ÿո������n��������
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
void Merge(int A[], int B[], int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    while(i <= mid && j <= end) {
        if(A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while(i <= mid)
        B[k++] = A[i++];
    while(j <= end)
        B[k++] = A[j++];

    for(i = start; i <= end; i++)
        A[i] = B[i];
}

void MergeSort(int A[], int B[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        MergeSort(A, B, start, mid);
        MergeSort(A, B, mid + 1, end);
        Merge(A, B, start, mid, end);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *A = (int*)malloc(sizeof(int) * n);
    int *B = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    MergeSort(A, B, 0, n - 1);

    for(int i = 0; i < n; i++){
        printf("%d\n", A[i]);
    }

    free(A);
    free(B);

    return 0;
}

