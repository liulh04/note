/*
����
��1��20���������У�ʹ�����к������A���㣺
a. ��������������֮��������
b. ��������������a������Bʹ�ã�A��B��ǰk��0 <= k <= 19������ͬ��B�ĵ�k+1���A�ĵ�k+1��С��(�����ֵ������еĵ�һ��)

����
û�����롣

���
���A����������֮����һ���ո��������һ������ǰ������һ�����ֺ���û�пո�
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

