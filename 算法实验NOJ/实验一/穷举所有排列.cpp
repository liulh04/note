#include<stdio.h>
 
/*����
����һ��С��10��������n������ÿ��Ԫ�ض���������ǰ��һ�εķ��������ǰn��Сд��ĸ���������С�
����
����һ��С��10��������n��
���
����ÿ��Ԫ�ض���������ǰ��һ�εķ��������ǰn��Сд��ĸ���������С�
��������
3
�������
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
        swap(&str[start], &str[i]); // �ָ�ԭʼ˳��
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
