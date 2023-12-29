/*
描述
通过栈交换字母顺序。给定两个字符串，要求所有的进栈和出栈序列（i表示进栈，o表示出栈），使得字符串2在求
得的进出栈序列的操作下，变成字符串1。输出结果需满足字典序。例如TROT 到 TORT:
[
i i i i o o o o
i o i i o o i o
]
输入
给定两个字符串，第一个字符串是源字符串，第二个字符是目标目标字符串。
输出
所有的进栈和出栈序列,输出结果需满足字典序
输入样例
madam adamm bahama bahama long short eric rice
输出样例
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
	* 入栈
	* start指针向后移动一位
	* mid加一位，指针向后一位
	* ans不变
	* op加一位1，指针向后一位
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
		* 恢复入栈之前的状态
		* op指针减一位
		* mid指针减一位
		* start指针减一位
		*/
		op.top--;

		mid.top--;

		start.top--;
	}
	/*
	* 出栈
	* start指针不变
	* mid减一位，指针向前一位
	* ans加一位，指针向后一位
	* op加一位0，指针向后一位
	*/
	if (mid.top != -1)
	{
		ans.top++;
		ans.ch[ans.top] = mid.ch[mid.top];

		mid.top--;

		op.top++;
		op.operation[op.top] = 0;

		/*
		* 比较ans的前k位和end是否相同
		*/
		if (issame())
		{
			dfs();
		}

		/*
		* 恢复出栈之前的状态
		* op减一位
		* ans减一位
		* mid加一位，指针向后一位
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
			printf(" i" + !i);//这里使用了简单的技巧，使得行首行尾没有空格
		}
		else
		{
			printf(" o" + !i);
		}
	}
	printf("\n");
}


