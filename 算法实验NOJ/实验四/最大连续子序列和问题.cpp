#include <stdio.h>

int main()
{
    int n;
    int num[1001];
    scanf("%d", &n);
    for(int i=0;i<n; i++)
        scanf("%d",&num[i]);
    int ans=num[0];//����ֵ����ans���ڵ�һ����
    for(int i=1;i<n;i++)
    {//���ڴӵ�һ����ʼ��ÿһ���������ǰ������ִ���0����ô���ֵ��Ϊ��ǰ��ĺͣ��ӵ�һ����ʼ�����һ����
     //num[i]�ͱ�Ϊǰi����������    
        if(num[i-1]>0)
            num[i]+=num[i-1];
        else
            num[i]+=0;
        if(num[i]>ans)
            ans=num[i];
    }

    printf("%d\n",ans);
    return 0;
}
