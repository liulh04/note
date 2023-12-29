/*
描述
给一个20×20的迷宫、起点坐标和终点坐标，问从起点是否能到达终点。
输入
多个测例。输入的第一行是一个整数n，表示测例的个数。接下来是n个测例，每个测例占21行，第一行四个整数x1，y1，x2，y2是起止点的位置（坐标从零开始），（x1，y1）是起点，（x2，y2）是终点。下面20行每行20个字符，’.’表示空格；’X’表示墙。
输出
每个测例的输出占一行，输出Yes或No。
输入样例
2
0 0 19 19
....................
XXXXXXXXXXXXXXXXXXXX
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
0 0 19 19
....................
XXXXXXXXXXXXXXXXXXX.
....................
.XXXXXXXXXXXXXXXXXXX
....................
XXXXXXXXXXXXXXXXXXX.
....................
.XXXXXXXXXXXXXXXXXXX
....................
XXXXXXXXXXXXXXXXXXX.
....................
.XXXXXXXXXXXXXXXXXXX
....................
XXXXXXXXXXXXXXXXXXX.
XXXXXXXXXXXXXXXXXXX.
XXXXXXXXXXXXXXXXXXX.
XXXXXXXXXXXXXXXXXXX.
....................
.XXXXXXXXXXXXXXXXXXX
....................

输出样例
No
Yes*/
#include<iostream>  
#include<cstdio>  
using namespace std;  
char data[21][21];  
    int state=0;  
  
void back(int x1,int y1,int x2,int y2)  
{  
    int xShift[4]={0,0,-1,1},yShift[4]={1,-1,0,0};    //用来控制方向  
    if(x1==x2&&y1==y2)  
    {  
        state=1;  
        return ;  
    }     
    data[x1][y1]='*';  
    for(int i=0;i<4;i++)  
    {  
        x1=x1+xShift[i];y1=y1+yShift[i];  
        if(data[x1][y1]=='.'&&y1>=0&&y1<20&&x1>=0&&x1<20)  
        {  
            if(x1==x2&&y1==y2)  
            {  
                state=1;  
                return ;  
            }  
            back(x1,y1,x2,y2);  
              
        }  
               x1=x1-xShift[i];y1=y1-yShift[i];    //默认这个方向没有走下去  
    }  
}  
int main()  
{  
    int n;  
    cin>>n;  
    while(n)  
    {  
        int x1,y1,x2,y2;  
        cin>>x1>>y1>>x2>>y2;  
        getchar();  
        for(int i=0;i<20;i++)  
        {  
            for(int j=0;j<20;j++)  
                scanf("%c",&data[i][j]);  
            getchar();  
        }  
        back(x1,y1,x2,y2);  
        if(state==1)  
        {  
            state=0;  
            cout<<"Yes"<<endl;  
        }  
        else  
        {  
            cout<<"No"<<endl;  
        }  
        n--;  
    }  
    return 0;  
}  



