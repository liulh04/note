/*
����
ͨ��ջ������ĸ˳�򡣸��������ַ�����Ҫ�����еĽ�ջ�ͳ�ջ���У�i��ʾ��ջ��o��ʾ��ջ����ʹ���ַ���2����
�õĽ���ջ���еĲ����£�����ַ���1���������������ֵ�������TROT �� TORT:
[
i i i i o o o o
i o i i o o i o
]
����
���������ַ�������һ���ַ�����Դ�ַ������ڶ����ַ���Ŀ��Ŀ���ַ�����
���
���еĽ�ջ�ͳ�ջ����,�������������ֵ���
��������
madam adamm bahama bahama long short eric rice
�������
[ i i i i o o o i o o i i i i o o o o i o i i o i o i o i o o i i o i o i o o i o ] [ i o i i i o o i i o o o i o i i i o o o i o i o i o i 
o i o i i i o o o i o i o i o i o i o i o ] [ ] [ i i o i o i o o ]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char ch[1000];
	int top;
	int last;
} chStack;

typedef struct
{
	int operation[1000];
	int top;
} inStack;

chStack start;
chStack end;
chStack mid;
chStack ans;
inStack op;

void dfs();
int issame();
void output();

int main()
{
	//input and init
	while (scanf("%s%s", start.ch, end.ch) != EOF)
	{
		start.last = strlen(start.ch) - 1;
		end.last = strlen(end.ch) - 1;

		start.top = -1;
		end.top = -1;
		mid.top = -1;
		ans.top = -1;
		op.top = -1;

		printf("[\n");
		dfs();
		printf("]\n");

	}
}


void dfs()
{
	if (ans.top == end.last && issame())
	{
		output();
	}
	/*
	* ��ջ
	* startָ������ƶ�һλ
	* mid��һλ��ָ�����һλ
	* ans����
	* op��һλ1��ָ�����һλ
	*/
	if (start.top < start.last)
	{
		start.top++;
		mid.top++;
		 
		mid.ch[mid.top] = start.ch[start.top];

		op.top++;
		op.operation[op.top] = 1;

		dfs();

		/*
		* �ָ���ջ֮ǰ��״̬
		* opָ���һλ
		* midָ���һλ
		* startָ���һλ
		*/
		op.top--;

		mid.top--;

		start.top--;
	}
	/*
	* ��ջ
	* startָ�벻��
	* mid��һλ��ָ����ǰһλ
	* ans��һλ��ָ�����һλ
	* op��һλ0��ָ�����һλ
	*/
	if (mid.top != -1)
	{
		ans.top++;
		ans.ch[ans.top] = mid.ch[mid.top];

		mid.top--;

		op.top++;
		op.operation[op.top] = 0;

		/*
		* �Ƚ�ans��ǰkλ��end�Ƿ���ͬ
		*/
		if (issame())
		{
			dfs();
		}

		/*
		* �ָ���ջ֮ǰ��״̬
		* op��һλ
		* ans��һλ
		* mid��һλ��ָ�����һλ
		*/
		op.top--;

		mid.top++;
		mid.ch[mid.top] = ans.ch[ans.top];

		ans.top--;
	}
}

int issame()
{
	int i;
	for (i = 0; i <= ans.top; i++)
	{
		if (ans.ch[i] != end.ch[i])
		{
			return 0;
		}
	}
	return 1;
}

void output()
{
	int i;
	for (i = 0; i <= op.top; i++)
	{
		if (op.operation[i] == 1)
		{
			printf(" i" + !i);//����ʹ���˼򵥵ļ��ɣ�ʹ��������βû�пո�
		}
		else
		{
			printf(" o" + !i);
		}
	}
	printf("\n");
}


