#include <iostream>
#include <queue>
#include <map>
 
using namespace std;
 
struct node     //状态
{
    int a[6];   //存放六个数字
    int num;    //将六个数字换算成六位数
};
 
node target;    //目标状态
 
map <int,int> used; //判重
 
queue <node> q1;    //广搜所用队列
 
bool bfs();     //广搜
 
void init(node n1); //初始化，包括队列清空，判重map清空
 
int getnum(node n1);    //由n1的六个数字返回换算成的六位数
 
node alpha(node n1);    //alpha操作
 
node beta(node n1);     //beta操作
 
bool fequal(node n1, node n2);  //判断两个状态是否相同
 
void print(node n1);    //输出一个状态
 
int main()
{
    for(int i=0; i<6; i++)  //设定目标状态
    {
        target.a[i]=i+1;
    }
 
    node n1;
    while(cin>>n1.a[0])     //输入数据
    {
        for(int i=1; i<6; i++)
        {
            cin>>n1.a[i];
        }
        n1.num=getnum(n1);
 
        init(n1);           //由n1为初始状态，进行初始化
 
        if(bfs())           //广搜
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
 
bool bfs()      //广搜
{
    node top;   //当前栈顶节点
    node nexta; //top节点经alpha操作后生成的节点
    node nextb; //top节点经beta操作后生成的节点
    while(!q1.empty())
    {
        top=q1.front(); //取栈顶节点
        q1.pop();
 
        nexta=alpha(top);   //进行alpha操作
        if(fequal(nexta,target))    //如果到达目标节点返回true
        {
            return true;
        }
        else if(used.count(nexta.num)==0)   //如果该状态未重复
        {
            q1.push(nexta);     //将该节点入栈
            used[nexta.num]=1;  //记录该状态出现过
        }
 
        nextb=beta(top);    //进行beta操作，以下同上
        if(fequal(nextb,target))
        {
            return true;
        }
        else if(used.count(nextb.num)==0)
        {
            q1.push(nextb);
            used[nextb.num]=1;
        }
    }
    return false;   //若队列为空，所有节点已搜索完均未到达目标状态
}
 
void init(node n1)  //初始化
{
    used.erase(used.begin(),used.end());    //清空判重map
 
    while(!q1.empty())  //清空队列！！！
    {
        q1.pop();
    }
 
    q1.push(n1);    //初始状态入栈
 
    used[n1.num]=1; //记录初始状态出现过
}
 
 
int getnum(node n1) //获取序号
{
    int n=0;
    for(int i=0; i<6; i++)
    {
        n=n*10+n1.a[i]; //将六个数字变成六位整数
    }
    return n;
}
 
node alpha(node n1)
{
    node n2;
 
    n2.a[0]=n1.a[3];
    n2.a[3]=n1.a[4];
    n2.a[4]=n1.a[1];
    n2.a[1]=n1.a[0];
 
    n2.a[2]=n1.a[2];
    n2.a[5]=n1.a[5];
 
    n2.num=getnum(n2);
 
    return n2;
}
 
node beta(node n1)
{
    node n2;
 
    n2.a[5]=n1.a[2];
    n2.a[2]=n1.a[1];
    n2.a[1]=n1.a[4];
    n2.a[4]=n1.a[5];
 
    n2.a[0]=n1.a[0];
    n2.a[3]=n1.a[3];
 
    n2.num=getnum(n2);
 
    return n2;
}
 
bool fequal(node n1, node n2)   //两节点是否相等
{
    for(int i=0; i<6; i++)
    {
        if(n1.a[i]!=n2.a[i])
        {
            return false;
        }
    }
    return true;
}
 
void print(node n1)
{
    for(int i=0; i<6; i++)
    {
        cout<<n1.a[i]<<' ';
        if(i==2)cout<<endl;
    }
    cout<<endl;
}
