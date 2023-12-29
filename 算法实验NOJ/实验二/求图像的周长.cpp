#include<stdio.h>
char map[10][10] = {0};
int m, n;
int output[10] = {0}; //每组数据的结果存在里面
int cnt = 0; //记录一共有几组数据
int cx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; //存储8个方向中行的改变量
int cy[] = {-1, 0, 1, -1, 1, -1, 0, 1}; //存储8个方向中列的改变量
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
        } //输入数据
        if (map[x - 1][y - 1] == '.')
        {
            output[cnt] = 0;
            continue;
        } //如果点击的点是'.'则图像不存在
        else if (map[x - 1][y - 1] == 'X')
        {
            map[x - 1][y - 1] = '1'; //标记
            search(x - 1, y - 1);    //查找周围的点是否符合要求
        }
        len();
    }
    print();
}
void search(int x, int y) //找出鼠标点击的那块图像
{
    int xt, yt;
    for (int i = 0; i < 8; i++) //检查周围8个方向上的点是否符合要求
    {
        xt = x + cx[i];
        yt = y + cy[i];
        if (xt < 0 || yt < 0 || xt >= m || yt >= n)
            continue; //越界直接跳过
        if (map[xt][yt] == 'X')
        {
            map[xt][yt] = '1';
            search(xt, yt);
        }
    }
}
void len() //计算边长
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
void print() //输出结果
{
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d\n", output[i]);
    }
}
