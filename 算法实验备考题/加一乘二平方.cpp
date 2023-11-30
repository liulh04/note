#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int m , n ; 
int step[10005];
bool used[10005];
queue<int> q;

int doit(int k ,int u){
    if(k==0){
        return u+1;
    }
    if(k==1){
        return u*2;
    }
    if(k==2){
        return u*u;
    }
}

void dfs(int a){
    int u,v;
    int flag;

    while(!q.empty()){
    flag=0;
    u=q.front();
    q.pop();

    for(int k=0;k<3;k++){
        v=doit(k,u);
        if(v==n){
            flag=1;
            printf("%d",(step[u]+1));
            break;
        }
        else if(v<n && used[v]){
            used[v]=false;
            step[v]=step[u]+1;
            q.push(v);
        }
    }

    
    if(flag==1){
        break;
    }
    }
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=m+1;i<=n;i++){
        used[i]=true;
    }
    q.push(m);
    step[m]=0;
    used[m]=false;
    dfs(m);
    return 0;
}
