/*
����
�����Ҵ����������ֱ���c1�� c2��n����װ�䣬������wi (i=1��n)�������м�װ���������������c1+c2��ȷ���Ƿ��п��ܽ����м�װ��ȫ��װ�����Ҵ���

����
���������ÿ������������ռ���С���һ��һ����c1��c2��n��n<=10�����ڶ���n��������ʾwi (i=1��n)��n����0��־���������

���
����ÿ�������ڵ�����һ�������Yes��No��

��������
7 8 2
8 7
7 9 2
8 8
0 0 0

�������
Yes
No

��ʾ
���������c1�����ֵmax������������max < c2����װ�뵽���Ҵ���
*/
#include <bits/stdc++.h>
using namespace std;
int n; //��װ����
int cw; // ��ǰ������, current weight
int bestw; //������������
int r;  //ʣ�༯װ������
int c1; //��һ���ִ���������
int c2; //�ڶ����ִ���������
int x[100]; //��ǰ��
int bestx[100]; //��ǰ���Ž�
int w[100]; //��װ����������
void OutPut()
{
    int restweight = 0;int wall=0;
    for(int i=1;i<=n;i++){
    	wall += w[i];
	}
    if(bestw <=c1 && ((wall -bestw) <= c2 )){
    	printf("Yes\n");
	}
	else printf("No\n");
}	
void BackTrack(int i)
{
    if(i > n)
    {
        if(cw > bestw)
        {
            for(int i = 1; i <= n; ++i)
                bestx[i] = x[i];
            bestw = cw;
        }
        return;
    }
    r -= w[i];
    if(cw + w[i] <= c1) //Լ������
    {
        cw += w[i];
        x[i] = 1;
        BackTrack(i + 1);
        x[i] = 0;
        cw -= w[i];
    }
    if(cw + r > bestw) //�޽纯��
    {
        x[i] = 0;
        BackTrack(i + 1);
    }
    r += w[i];

}
 
int main()
{
    while(1){
	
	cin>>c1>>c2;
	cin>>n;
    if(c1==0&&c2==0){
    	break;
	}
	for(int i = 1; i <= n; ++i){	
		cin>>w[i];	
	}
    bestw = 0;
    r = 0;
    cw = 0;
    for(int i = 1; i <= n; ++i)
        r += w[i];   
    BackTrack(1);
    OutPut();
}
}


