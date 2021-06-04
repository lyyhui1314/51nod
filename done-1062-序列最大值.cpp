// 1062 序列中最大的数
// 有这样一个序列a：
// a[0] = 0
// a[1] = 1
// a[2i] = a[i]
// a[2i+1] = a[i] + a[i+1]

// 输入一个数N，求a[0] - a[n]中最大的数。
// a[0] = 0, a[1] = 1, a[2] = 1, a[3] = 2, a[4] = 1, a[5] = 3, a[6] = 2, a[7] = 3, a[8] = 1, a[9] = 4, a[10] = 3。
// 例如：n = 5，最大值是3，n = 10，最大值是4。
// 输入
// 第1行：一个数T，表示后面用作输入测试的数的数量。（1 <= T <= 10)
// 第2 - T + 1行：T个数，表示需要计算的n。（1 <= n <= 10^5)
// 输出
// 共T行，每行1个最大值。
// 输入样例
// 2
// 5
// 10
// 输出样例
// 3
// 4

#include <stdio.h>

#define MAX_N int(1e5)

int t, n, a[MAX_N+1] = {0, 1}, max_from[MAX_N+1] = {0};

void gen_seq()
{
    for (int i = 0; i < MAX_N/2; i++)
    {
        a[2*i] = a[i];
        a[2*i+1] = a[i] + a[i+1];
    }
}

int main()
{
    gen_seq();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int maxnum = 0;
        for (int i = 0; i <= n; i++)
            if (a[i] > maxnum)
                maxnum = a[i];
        printf("%d\n", maxnum);
    }
}