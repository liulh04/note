/*
描述
通过栈交换字母顺序。给定两个字符串，要求所有的进栈和出栈序列（i表示进栈，o表示出栈），使得字符串2在求
得的进出栈序列的操作下，变成字符串1。输出结果需满足字典序。例如TROT 到 TORT:
[
i i i i o o o o
i o i i o o i o
]
输入
给定两个字符串，第一个字符串是源字符串，第二个字符是目标目标字符串。
输出
所有的进栈和出栈序列,输出结果需满足字典序
输入样例
madam adamm bahama bahama long short eric rice
输出样例
[ i i i i o o o i o o i i i i o o o o i o i i o i o i o i o o i i o i o i o o i o ] [ i o i i i o o i i o o o i o i i i o o o i o i o i o i 
o i o i i i o o o i o i o i o i o i o i o ] [ ] [ i i o i o i o o ]
*/
#include <iostream>

using namespace std;
 
struct node
{
    char ch;
    int visit;
    int left,right,up,down;
}map[100][100];
 
int n,m;
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
 
bool place(int x,int y,int nx,int ny)
{
    if(nx > 0 && nx <= m && ny > 0 && ny <= n && !map[nx][ny].visit)
    {
        if(nx == x && ny == y - 1 && map[x][y].left && map[nx][ny].right)
            return 1;
        if(nx == x && ny == y + 1 && map[x][y].right && map[nx][ny].left)
            return 1;
        if(nx == x - 1 && ny == y && map[x][y].up && map[nx][ny].down)
            return 1;
        if(nx == x + 1 && ny == y && map[x][y].down && map[nx][ny].up)
            return 1;
    }
    return 0;
}
 
void dfs(int x,int y)
{
	int i;
    map[x][y].visit = 1;
    for(i = 0;i < 4;i ++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(place(x,y,nx,ny))
            dfs(nx,ny);
    }
}
 
int main()
{
    while(cin >> m >> n && (m != -1 && n != -1))
    {
    	int i,j;
        int cnt = 0;
        for(i = 1;i <= m;i ++)
        {
            for(j = 1;j <= n;j ++)
            {
                cin >> map[i][j].ch;
                map[i][j].visit = 0;
                map[i][j].down = 0;
                map[i][j].up = 0;
                map[i][j].right = 0;
                map[i][j].left = 0;
                if(map[i][j].ch == 'A')
                    map[i][j].up = map[i][j].left = 1;
                else if(map[i][j].ch == 'B')
                    map[i][j].up = map[i][j].right = 1;
                else if(map[i][j].ch == 'C')
                    map[i][j].left = map[i][j].down = 1;
                else if(map[i][j].ch == 'D')
                    map[i][j].right = map[i][j].down = 1;
                else if(map[i][j].ch == 'E')
                    map[i][j].down = map[i][j].up = 1;
                else if(map[i][j].ch == 'F')
                    map[i][j].right = map[i][j].left = 1;
                else if(map[i][j].ch == 'G')
                    map[i][j].right = map[i][j].left = map[i][j].up = 1;
                else if(map[i][j].ch == 'H')
                    map[i][j].up = map[i][j].down = map[i][j].left = 1;
                else if(map[i][j].ch == 'I')
                    map[i][j].left = map[i][j].right = map[i][j].down = 1;
                else if(map[i][j].ch == 'J')
                    map[i][j].up = map[i][j].down = map[i][j].right = 1;
                else if(map[i][j].ch == 'K')
                    map[i][j].up = map[i][j].down = map[i][j].right = map[i][j].left = 1;
            }
        }
        int p,q;
        for(p = 1;p <= m;p ++)
        {
            for(q = 1;q <= n;q ++)
            {
                if(!map[p][q].visit)
                {
                    dfs(p,q);
                    cnt ++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}


