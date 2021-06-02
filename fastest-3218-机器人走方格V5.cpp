// 3218 机器人走方格 V5
// M∗N的方格，一个机器人从左上走到右下，每步只能向右一格、或向下一格、或向右下一格走。有多少种不同的走法？
// 由于方法数量可能很大，只需要输出mod 1e9+7的结果。
// 输入
// 第一行输入两个数M,N，以空格隔开。（2≤m,n≤1000)
// 输出
// 输出一个数，走法的数量。
// 数据范围
// 对于45%的数据，2≤m,n≤20；
// 对于100%的数据，2≤m,n≤1000；
// 输入样例
// 2 3
// 输出样例
// 5

#include <stdio.h>
#include <string.h>

#define MAXN 1001
#define MOD 1000000007

typedef long long LL;

int m, n;
LL res[MAXN][MAXN];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &m, &n);
    memset(res, 0, sizeof(res));
    res[0][0] = 1;
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= m; i++)
            res[i][j] = (res[i - 1][j] + res[i][j - 1] + res[i - 1][j - 1]) % MOD;
    printf("%I64d", res[m][n]);
    return 0;
}
