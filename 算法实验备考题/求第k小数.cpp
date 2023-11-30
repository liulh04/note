#include<stdio.h>

int n;
int m;
int A[10000];
int B[50000];

void Binsearch(int k, int lo, int hi) {
    if (lo > hi) {
        printf("No\n");
        return ;
    }

    int mid = (hi + lo) / 2;
    int f = B[k];

    if (A[mid] == f) {
        printf("Yes\n");
        return ;
    }
    else if (f > A[mid]) {
        lo = mid + 1;
        Binsearch(k, lo, hi);
        return;
    }
    else if (f < A[mid]) {
        hi = mid - 1;
        Binsearch(k, lo, hi);
        return;
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

    for (int k = 0; k < m; k++) {
        int hi = n - 1;
        int lo = 0;
        Binsearch(k, lo, hi);
    }

    return 0;
}
