// 1919 炮兵阵地
// 司令部的将军们打算在N*N的网格地图上部署他们的炮兵部队。
// 一个N*N的地图由N行N列组成，地图的每一格可能是山地（用"X"表示），也可能是平原（用"."表示）。
// 在每一格平原地形上最多可以布置一支炮兵部队（山地上不能够部署炮兵部队）；
// 一支炮兵部队在地图上的攻击范围是它所在位置的对应的行和列，但是大炮打出去之后如果被山地阻挡 了，那么攻击范围就到那块山地。
// 在防止误伤的前提下（保证任何两支炮兵部队之间不能互相攻击，即任何一支炮兵部队都不在其他支炮兵部队的攻击范围内），
// 在整个地图区域内最多能够摆放多少我军的炮兵部队。
// .X..     #X.#        .X#.        .X..
// ....     .#..        .#..        #..#
// XX..     XX#.        XX..        XX..
// ....     #...        .#..        ...X
// 样例解释：
//上图中显示的是相同的地图中不同的放置大炮的方案。"X"表示山地，"."表示平原，"#"表示对应的平原放置了大炮。
// 第一张是不放大炮的情况。第二张和第三张是合理的放置大炮的方案。最后一张是不合理的放置大炮的方案.
// 对于这个地图来讲，最多能放置5门大炮。第二张图就是一种最优的放置方案，当然还有其它的最优放置方案。
// 输入
// 单组测试数据。
// 第一行有一个整数N(1<=N<=4)。
// 接下来N行，每行有N个字符（只有两种字符：'.' 表示平原， 'X'表示山地）。
// 输出
// 输出一个整数表示答案。
// 输入样例
// 样例输入1
// 4
// .X..
// ....
// XX..
// ....
// 输出样例
// 样例输出1
// 5

#include <stdio.h>

char c;
int n, max = 0, sum = 0, res[10][10];

bool check(int row, int col)
{
    if (res[row][col] != 0)
        return false;
    for (int i = row; res[i][col] != 1; i--)
    {
        if (res[i][col] == 2)
            return false;
    }
    for (int i = row + 1; res[i][col] != 1; i++)
    {
        if (res[i][col] == 2)
            return false;
    }
    for (int i = col; res[row][i] != 1; i--)
    {
        if (res[row][i] == 2)
            return false;
    }
    for (int i = col + 1; res[row][i] != 1; i++)
    {
        if (res[row][i] == 2)
            return false;
    }
    return true;
}

void find()
{
    int i = 1, j = 1;
    while (i)
    {
        while (i <= n)
        {
            if (check(i, j))
            {
                res[i][j] = 2;
                sum++;
            }
            if (++j > n)
            {
                i++;
                j = 1;
            }
        }
        if (sum > max)
            max = sum;
        while (res[i][j] != 2 && i)
        {
            if (--j < 1)
            {
                i--;
                j = n;
            }
        }
        if (i)
        {
            res[i][j] = 0;
            sum--;
            if (++j > n)
            {
                i++;
                j = 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%c", &c);
            if (c == 'X')
                res[i][j] = 1;
        }
        getchar();
    }
    for(int i = 0; i < n+2; i++)
    {
        res[0][i] = 1;
        res[n+1][i] = 1;
    }
    for (int i = 0; i < n+2; i++)
    {
        res[i][0] = 1;
        res[i][n+1] = 1;
    }
    find();
    printf("%d\n", max);
    return 0;
}
