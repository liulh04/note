#include<stdio.h>
char map[10][10] = {0};
int m, n;
int output[10] = {0}; //ÿ�����ݵĽ����������
int cnt = 0; //��¼һ���м�������
int cx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; //�洢8���������еĸı���
int cy[] = {-1, 0, 1, -1, 1, -1, 0, 1}; //�洢8���������еĸı���
void search(int x, int y);
void len();
void print();
int main()
{
    int x, y;
    while (1)
    {
        scanf("%d%d%d%d", &m, &n, &x, &y);
        if (m == 0 && n == 0 && x == 0 && y == 0)
            break;
        cnt++;
        char temp = getchar();
        for (int i = 0; i < m; i++)
        {
            fgets(map[i], sizeof(map[i]), stdin);
        } //��������
        if (map[x - 1][y - 1] == '.')
        {
            output[cnt] = 0;
            continue;
        } //�������ĵ���'.'��ͼ�񲻴���
        else if (map[x - 1][y - 1] == 'X')
        {
            map[x - 1][y - 1] = '1'; //���
            search(x - 1, y - 1);    //������Χ�ĵ��Ƿ����Ҫ��
        }
        len();
    }
    print();
}
void search(int x, int y) //�ҳ���������ǿ�ͼ��
{
    int xt, yt;
    for (int i = 0; i < 8; i++) //�����Χ8�������ϵĵ��Ƿ����Ҫ��
    {
        xt = x + cx[i];
        yt = y + cy[i];
        if (xt < 0 || yt < 0 || xt >= m || yt >= n)
            continue; //Խ��ֱ������
        if (map[xt][yt] == 'X')
        {
            map[xt][yt] = '1';
            search(xt, yt);
        }
    }
}
void len() //����߳�
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '1')
            {
                if (i - 1 < 0 || map[i - 1][j] == '.')
                    output[cnt] += 1;
                if (i + 1 >= m || map[i + 1][j] == '.')
                    output[cnt] += 1;
                if (j - 1 < 0 || map[i][j - 1] == '.')
                    output[cnt] += 1;
                if (j + 1 >= n || map[i][j + 1] == '.')
                    output[cnt] += 1;
            }
        }
    }
}
void print() //������
{
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d\n", output[i]);
    }
}
