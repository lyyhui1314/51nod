// 3063 小明爱正方形
// 1.0 秒 131,072.0 KB 5 分 1级题
// C

// 输入
// 第一行一个数T，表示数据的组数(1≤T≤10)；
// 对于每组数据，
// 第一行输入一个数n，表示火柴的数目，其中1≤n≤15；
// 第二行n个数表示每根火柴的长度，其中火柴长度总和≤10^9。
// 输出
// 对于每组数据输出一行，
// 如果所有的火柴可以拼成正方形，输出true，否者输出false。
// 数据范围
// 对于25%的数据，1≤n≤8；
// 对于50%的数据，1≤n≤10；
// 对于100%的数据，1≤n≤15，1≤T≤10，每组火柴长度总和≤10^9；
// 输入样例
// 1
// 5
// 1 1 2 2 2
// 输出样例
// true
// 样例解释
// 能拼成一个边长为2的正方形。

#include <algorithm>
#include <stdio.h>

bool cmp(int v1, int v2)
{
    return v1 > v2;
}

int main()
{
    int t, n, a[16], l, flg, cur;
    scanf("%d", &t);
    while (t--)
    {
        l = 0, flg = 1;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            l += a[i];
        }
        if (l % 4)
        {
            printf("false\n");
            continue;
        }
        std::sort(a, a + n, cmp);
        l /= 4;
        for (int j = 0; j < 4 && flg; j++)
        {
            cur = 0;
            for (int i = 0; i < n; i++)
            {
                cur += a[i];
                if (cur <= l)
                    a[i] = 0;
                else
                    cur -= a[i];
                if (cur == l)
                    break;
            }
            if (cur != l)
                flg = 0;
        }
        printf("%s\n", flg ? "true" : "false");
    }
}