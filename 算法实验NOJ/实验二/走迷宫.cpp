/*
����
��һ��20��20���Թ������������յ����꣬�ʴ�����Ƿ��ܵ����յ㡣
����
�������������ĵ�һ����һ������n����ʾ�����ĸ�������������n��������ÿ������ռ21�У���һ���ĸ�����x1��y1��x2��y2����ֹ���λ�ã�������㿪ʼ������x1��y1������㣬��x2��y2�����յ㡣����20��ÿ��20���ַ�����.����ʾ�ո񣻡�X����ʾǽ��
���
ÿ�����������ռһ�У����Yes��No��
��������
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

�������
No
Yes*/
#include<iostream>  
#include<cstdio>  
using namespace std;  
char data[21][21];  
    int state=0;  
  
void back(int x1,int y1,int x2,int y2)  
{  
    int xShift[4]={0,0,-1,1},yShift[4]={1,-1,0,0};    //�������Ʒ���  
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
               x1=x1-xShift[i];y1=y1-yShift[i];    //Ĭ���������û������ȥ  
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



