#include <iostream>
#include <queue>
#include <map>
 
using namespace std;
 
struct node     //״̬
{
    int a[6];   //�����������
    int num;    //���������ֻ������λ��
};
 
node target;    //Ŀ��״̬
 
map <int,int> used; //����
 
queue <node> q1;    //�������ö���
 
bool bfs();     //����
 
void init(node n1); //��ʼ��������������գ�����map���
 
int getnum(node n1);    //��n1���������ַ��ػ���ɵ���λ��
 
node alpha(node n1);    //alpha����
 
node beta(node n1);     //beta����
 
bool fequal(node n1, node n2);  //�ж�����״̬�Ƿ���ͬ
 
void print(node n1);    //���һ��״̬
 
int main()
{
    for(int i=0; i<6; i++)  //�趨Ŀ��״̬
    {
        target.a[i]=i+1;
    }
 
    node n1;
    while(cin>>n1.a[0])     //��������
    {
        for(int i=1; i<6; i++)
        {
            cin>>n1.a[i];
        }
        n1.num=getnum(n1);
 
        init(n1);           //��n1Ϊ��ʼ״̬�����г�ʼ��
 
        if(bfs())           //����
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
 
bool bfs()      //����
{
    node top;   //��ǰջ���ڵ�
    node nexta; //top�ڵ㾭alpha���������ɵĽڵ�
    node nextb; //top�ڵ㾭beta���������ɵĽڵ�
    while(!q1.empty())
    {
        top=q1.front(); //ȡջ���ڵ�
        q1.pop();
 
        nexta=alpha(top);   //����alpha����
        if(fequal(nexta,target))    //�������Ŀ��ڵ㷵��true
        {
            return true;
        }
        else if(used.count(nexta.num)==0)   //�����״̬δ�ظ�
        {
            q1.push(nexta);     //���ýڵ���ջ
            used[nexta.num]=1;  //��¼��״̬���ֹ�
        }
 
        nextb=beta(top);    //����beta����������ͬ��
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
    return false;   //������Ϊ�գ����нڵ����������δ����Ŀ��״̬
}
 
void init(node n1)  //��ʼ��
{
    used.erase(used.begin(),used.end());    //�������map
 
    while(!q1.empty())  //��ն��У�����
    {
        q1.pop();
    }
 
    q1.push(n1);    //��ʼ״̬��ջ
 
    used[n1.num]=1; //��¼��ʼ״̬���ֹ�
}
 
 
int getnum(node n1) //��ȡ���
{
    int n=0;
    for(int i=0; i<6; i++)
    {
        n=n*10+n1.a[i]; //���������ֱ����λ����
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
 
bool fequal(node n1, node n2)   //���ڵ��Ƿ����
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
