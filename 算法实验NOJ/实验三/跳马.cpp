#include <iostream>
#include<string.h>
#include<queue>
using namespace std;
struct addr{
    queue<int>x;
    queue<int>y;
}addr;
int sx,sy,tx,ty;
int step[201][201],used[201][201];
int dirx[8]={1,2,2,1,-1,-2,-2,-1},diry[8]={2,1,-1,-2,2,1,-1,-2};
void init()
{
    memset(step,0,sizeof(step));
    memset(used,0,sizeof(used));
    used[sx][sy]=1;
    step[sx][sy]=0;
    addr.x.push(sx);
    addr.y.push(sy);
}
void empty()
{
    while(!addr.x.empty())
        addr.x.pop();
    while(!addr.y.empty())
        addr.y.pop();
}
int bfs()
{
    while(1)
    {
        int cx,cy;
        cx=addr.x.front();
        cy=addr.y.front();
        addr.x.pop();
        addr.y.pop();
        for(int i=0;i<8;i++)
        {
            int vx,vy;
            vx=cx+dirx[i];
            vy=cy+diry[i];
            if(vx==tx&&vy==ty)
                return step[cx][cy]+1;
            else
            {
                if(used[vx][vy]==0&&vx>0&&vx<=200&&vy>0&&vy<=200)
                {
                    addr.x.push(vx);
                    addr.y.push(vy);
                    step[vx][vy]=step[cx][cy]+1;
                    used[vx][vy]=1;
                }
            }
        }
    }

}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>sx>>sy>>tx>>ty;
        empty();
        init();
        int num=bfs();
        cout<<num<<endl;
    }
    return 0;
}
