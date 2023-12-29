/*
描述
城堡是一个4×4的方格，为了保卫城堡，现需要在某些格子里修建一些堡垒。城堡中的某些格子是墙，其余格子都是空格，堡垒只能建在空格里，每个堡垒都可以向上下左右四个方向射击，如果两个堡垒在同一行或同一列，且中间没有墙相隔，则两个堡垒都会把对方打掉。问对于给定的一种状态，最多能够修建几个堡垒。
输入
每个测例以一个整数n（1<=n<=4）开始，表示城堡的大小。接下来是n行字符每行n个，‘X’表示该位置是墙，‘.’表示该位置是空格。n等于0标志输入结束。
输出
每个测例在单独的一行输出一个整数：最多修建堡垒的个数。
输入样例
4
.X..
....
XX..
....
2
XX
.X
3
.X.
X.X
.X.
3
...
.XX
.XX
4
....
....
....
....
0
输出样例
5
1
5
2
4
*/
#include <iostream>
 
using namespace std;
 
int n;      //城堡大小
int a[4][4];    //城堡方格，1==墙，0==空，-1==堡垒
                //左上角为方格[0,0]
 
int mcnt;   //最大堡垒个数
int cnt;    //当前已建堡垒个数
 
void dfs(int m);        //回溯深搜
bool ok(int i,int j);   //判断方格[i,j]能否放置堡垒
 
int main()
{
    cin>>n;
    while(n){
        char c;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>c;
                if(c=='X')      //墙
                    a[i][j]=1;
                else            //空
                    a[i][j]=0;
            }
        }
        //初始化
        mcnt=0;
        cnt=0;
 
        dfs(0);
 
        cout<<mcnt<<endl;
 
        cin>>n;
    }
 
    return 0;
}
 
void dfs(int m)     //判断序号为m的方格
{
    if(m==(n*n)){       //搜到最后一个方格
        if(mcnt<cnt)    //更新最大值
            mcnt=cnt;
    }
    else{
        int i=m/n;
        int j=m%n;
        if(ok(i,j)){     //若方格m内可以修建堡垒
            a[i][j]=-1;
            cnt++;
            dfs(m+1);
            cnt--;
            a[i][j]=0;
        }
        dfs(m+1);
    }
}
 
//函数功能：判断方格[i,j]内能否放置堡垒
//不能放置条件：
//1.本方格是墙
//2.本方格的上方或左方有堡垒（中间无墙相隔）
//因为是按序号顺序搜索方格，因此不必判断下方或右方（还未放置，必无堡垒）
bool ok(int i,int j)
{
    int x,y;
    if(a[i][j]==1)  return false;   //本方格是墙
 
    for(x=i-1,y=j;x>=0;x--){ //向上找
        if(a[x][y]==1)  break;
        if(a[x][y]==-1) return false;
    }
 
    for(x=i,y=j-1;y>=0;y--){ //向左找
        if(a[x][y]==1)  break;
        if(a[x][y]==-1) return false;
    }
 
    return true;
}
