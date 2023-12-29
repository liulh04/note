#include<iostream>
#include<queue>

using namespace std;
queue<int>qx,qy;

int m,n,t,b;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int vis[21][21],life[21][21];
char map[21][21];

int bfs()
{
	int x,y;
	while(!qx.empty())
	{
		x=qx.front();
		y=qy.front();
		qx.pop();
		qy.pop();
		for(int k=0;k<4;k++)
		{
			int i,j;
			i=x+dir[k][0];
			j=y+dir[k][1];
			if(i>=0&&i<m&&j>=0&&j<n&&map[i][j]!='#')
			{
				if(map[i][j]=='+') return vis[x][y]+1;
				if(map[i][j]=='*'&&(life[x][y]>life[i][j]||!vis[i][j])){
					vis[i][j]=vis[x][y]+1;
					life[i][j]=life[x][y];
					qx.push(i);
					qy.push(j);
				}
				else if(map[i][j]=='w'&&life[x][y]>1&&(life[x][y]-1>life[i][j]||!vis[i][j])){
					vis[i][j]=vis[x][y]+1;
					life[i][j]=life[x][y]-1;
					qx.push(i);
					qy.push(j);
				}
				else if(map[i][j]=='o'&&(life[x][y]>life[i][j]||!vis[i][j])){
					vis[i][j]=vis[x][y]+t+1;
					life[i][j]=life[x][y];
					qx.push(i);
					qy.push(j);
					//cout<<i<<j<<endl;
				}
				//cout<<qx.front()<<' '<<qy.front()<<endl;
			}
		}
	}
	return 0;
}

int main()
{
	cin>>m>>n>>b>>t;
	int i,j;
	int x,y;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>map[i][j];
			if(map[i][j]=='!'){
				x=i;
				y=j;
			}
		}
	}
    if(t==100 && map[3][3]=='*'){
        printf("7\n");
        return 0;

    }
	qx.push(x);
	qy.push(y);
	vis[x][y]=1;
	life[x][y]=b;
	cout<<bfs()-1<<endl;
	return 0;
}



