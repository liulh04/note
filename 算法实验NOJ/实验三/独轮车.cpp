#include <iostream>
#include <queue>
using namespace std;
char maze[20][20];
int sx,sy,fx,fy,sc,sd,fc;
char c1, c2, d;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int vis[20][20][5][4];
int t[20][20][5][4];
struct Node{
    int x;
    int y;
    int color;
    int direct;
    int time;
};

int direction(char ch)
{
	if(ch == 'E')
	{
		return 0;
	} 
	if(ch == 'S')
	{
		return 1;
	}
	if(ch == 'W')
	{
		return 2;
	}
	if(ch == 'N')
	{
		return 3;
	}
    return -1;
} 
 
int color(char m)
{
	if(m == 'R')
	{
		return 0;
	}
	if(m == 'Y')
	{
		return 1;
	}
	if(m == 'B')
	{
		return 2;
	}
	if(m == 'W')
	{
		return 3;
	}
	if(m == 'G')
	{
		return 4;
	}
    return -1;
}
int bfs()
{
    int i;
    queue<Node> q;
    Node now, next;
    now.x = sx - 1;
    now.y = sy - 1;
    now.direct = direction(d);
    now.color = color(c1);
    now.time = 0;
    q.push(now);
    vis[now.x][now.y][now.color][now.direct] = 1;
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        for (i = 0; i < 3; i++)
        {
            if(i == 0)
            {
                next.x = now.x;
                next.y = now.y;
                next.color = now.color;
                next.direct = (now.direct + 1) % 4;
            }
            if(i == 1)
            {
                next.x = now.x;
                next.y = now.y;
                next.color = now.color;
                next.direct = (now.direct + 3) % 4;
            }
            if(i == 2)
            {
                next.x = now.x += dir[now.direct][0];
                next.y = now.y += dir[now.direct][1];
                next.color = (now.color + 1) % 5;
                next.direct = now.direct;
            }
            if(next.x == fx - 1 &&next.y == fy - 1 && next.color == color(c2))
            {
                return now.time + 1;
            }
            if(next.x >= 0 && next.x < 20 && next.y >= 0 && next.y < 20 && vis[next.x][next.y][next.color][next.direct] == 0&&maze[next.x][next.y] == '.')
            {
                vis[next.x][next.y][next.color][next.direct] = 1;
                next.time = now.time + 1;
                q.push(next);
            }
        }
    }
    return -1;
}
int main()
{
    int i, j;
    cin >> sx >> sy >> c1 >> d >> fx >> fy >> c2;
    for (i = 0; i < 20;i++)
    {
        for (j = 0; j < 20;j++)
        {
            cin >> maze[i][j];
        }
    }
    cout << bfs() << endl;
}

