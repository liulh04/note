/*
描述
把1到20这重新排列，使得排列后的序列A满足：
a. 任意相邻两个数之和是素数
b. 不存在满足条件a的序列B使得：A和B的前k（0 <= k <= 19）项相同且B的第k+1项比A的第k+1项小。(即按字典序排列的第一项)

输入
没有输入。

输出
输出A，两个数字之间用一个空格隔开，第一个数字前面和最后一个数字后面没有空格。
*/
#include <stdio.h>
 
int circle[20], a[20], sign;
 
int IsPrime (int n);
int check (int n);
void Output ();
void llh (int n);
 
int main ()
{
	llh(0);
	return 0;
}
 
int IsPrime (int n)
{
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0)	return 0;
	return 1;
}
 
int check(int n)
{
	if (n == 19)
	{
		if (IsPrime(circle[n] + circle[0]) && IsPrime(circle[n] + circle[n - 1]))	return 1;
	}
	else
	{
		if (IsPrime(circle[n] + circle[n - 1]))	return 1;
	}
	return 0;
}
 
void Output()
{
	int i;
	for (i = 0; i < 19; i++)	printf ("%d ", circle[i]);
	printf ("%d\n", circle[i]);
	return ;
}
 
void llh(int n)
{
	int i;
	if (sign == 1)	return ;
	for (i = 0; i < 20; i++)
		if (a[i] == 0)	break;
	if (i == 20)	Output(), sign = 1;
	else
	{
		for (i = 0; i < 20; i++)
		{
			if (a[i] == 0)
			{
				circle[n] = i + 1;
				if (check(n))
				{
					a[i] = 1;
					llh(n + 1);
					a[i] = 0;
					circle[n] = 0;
				}
			}
		}
	}
}

