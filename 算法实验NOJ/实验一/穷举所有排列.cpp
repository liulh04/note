#include<stdio.h>
 
/*描述
输入一个小于10的正整数n，按把每个元素都交换到最前面一次的方法，输出前n个小写字母的所有排列。
输入
输入一个小于10的正整数n。
输出
按把每个元素都交换到最前面一次的方法，输出前n个小写字母的所有排列。
输入样例
3
输出样例
abc
acb
bac
bca
cba
cab
*/

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char* str, int start, int end) {
    if (start == end) {
        printf("%s\n", str);
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&str[start], &str[i]);
        permute(str, start + 1, end);
        swap(&str[start], &str[i]); // 恢复原始顺序
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char str[10];
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + i;
    }
    str[n] = '\0';

    permute(str, 0, n - 1);

    return 0;
}
