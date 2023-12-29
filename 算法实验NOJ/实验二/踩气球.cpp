/*
描述
六一儿童节，小朋友们做踩气球游戏，气球的编号是1～100，两位小朋友各踩了一些气球，要求他们报出自己所踩气球的编号的乘积。
现在需要你编一个程序来判断他们的胜负，判断的规则是这样的：如果两人都说了真话，数字大的人赢；如果两人都说了假话，数字大的人赢；
如果报小数字的人说的是真话而报大数字的人说谎，则报小数字的人赢（注意：只要所报的小数字是有可能的，即认为此人说了真话）。
输入
输入为两个数字，0 0表示结束；
输出
输出为获胜的数字。
输入样例
36 62 49 343 0 0
输出样例
62 49
*/
#include <iostream>
 using namespace std;
int a[101]; //气球状态，0==完好无损，1==朋友1踩爆，2==朋友2踩爆
int n1,n2;  //朋友1、2所报数字
int x1,x2;  //当前朋友1、2踩爆气球乘积
int flag1;  //小数字是否为真，0==假，1==真
int flag2;  //大数字，同上
 
void dfs(int m);
int main()
{
    cin>>n1>>n2;
    while(!(n1==0&&n2==0)){
        x1=x2=1;
        flag1=flag2=0;
        //初始化 
        if(n1>n2) swap(n1,n2);   //n1为小数字
 
        dfs(1);
 
        if(flag1==1&&flag2==1)
            cout<<n2<<endl;
        // 两个数字都是真 
        else if(flag1==0&&flag2==0)
            cout<<n2<<endl;
    	//都是假 
        else
            cout<<n1<<endl;
        
        cin>>n1>>n2;
    }
    return 0;
}
 
void dfs(int m)
{
    if(m==101){
        if(x1==n1&&x2==n2){ //两人为真，大数字赢
            flag1=flag2=1;
        }
        if(x1==n1){     //小数字为真，小数字赢
            flag1=1;
        }
    }
    else{
        a[m]=0;
        dfs(m+1);
 
        if((x1*m<=n1)&&(n1%m==0)){  //限界条件
            a[m]=1;
            x1*=m;
            dfs(m+1);
            x1/=m;
        }
        if((x2*m<=n2)&&(n2%m==0)){  //限界条件
            a[m]=2;
            x2*=m;
            dfs(m+1);
            x2/=m;
        }
    }
}

