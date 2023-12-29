#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

int m, n    ;
int step[10005];
bool used[10005];
queue<int> q;

int doit(int k,int u){
    if(k==0){
        return u+1;
    }
    if(k==1){
        return 2*u;
    }
    if(k==2){
        return u*u;
    }
}
int dfs(int a){
    int u,v;
    

    while(!q.empty()){
        int flag=0;
        u=q.front();
        q.pop();

        for(int k=0;k<3;k++){
            v=doit(k,u);
            if(v==n){
                flag=1;
                printf("%d",step[u]+1);
                break;
            }
            if(v<n && used[v]){
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
    used[m]=false;
    step[m]=0;
    q.push(m);
    dfs(m);
    return 0;
}
