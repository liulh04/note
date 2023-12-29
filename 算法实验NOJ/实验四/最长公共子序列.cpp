#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;


int main(){
    char a[205],b[205];
    int  l[205][205];

    fgets(a,205,stdin);
    fgets(b,205,stdin);

    for(int i=1;i<=strlen(a);i++){
        for(int j=1;j<=strlen(b);j++){
            if(a[i-1]==b[j-1]){
                l[i][j]=l[i-1][j-1]+1;
            }
            else{
                l[i][j]=max(l[i-1][j],l[i][j-1]);
            }
        }
    }
    printf("%d",(l[strlen(a)][strlen(b)]-1));
    return 0;
}
