#include <stdio.h>

int main()
{
    int n;
    int num[1001];
    scanf("%d", &n);
    for(int i=0;i<n; i++)
        scanf("%d",&num[i]);
    int ans=num[0];//赋初值，令ans等于第一个数
    for(int i=1;i<n;i++)
    {//对于从第一个开始的每一个数，如果前面的数字大于0，那么这个值变为与前面的和，从第一个开始，如此一来，
     //num[i]就变为前i个数的最大和    
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
