// 3002 整数划分 easy ver.
// 2.0 秒 131,072.0 KB 5 分 1级题
// 将N分为若干个不同整数的和，有多少种不同的划分方式，例如：n = 6，{6} {1,5} {2,4} {1,2,3}，共4种。由于数据较大，输出Mod 10^9+7的结果即可。

// 输入
// 输入1个数N(1 <= N <= 1000)。
// 输出
// 输出划分的数量Mod 10^9 + 7。
// 数据范围
// 对于10%的数据，1≤N≤10；
// 对于40%的数据，1≤N≤100；
// 对于100%的数据，1≤N≤2000；
// 输入样例
// 6
// 输出样例
// 4

#include <stdio.h>
#include <string.h>
#define MAX_CNT int(1e9 + 7)

int memo[1001][1001];

int div(int n, int m)
{
    if (memo[n][m])
        return memo[n][m];
    if ((n == 1 && n <= m) || (n == 2 && n <= m))
        return memo[n][m] = 1;
    if ((n == 1 && n > m) || (n == 2 && n > m) ||  n > m * (m+1) / 2)
        return 0;
    if (n < m)
        return memo[n][m] = div(n, n) % MAX_CNT;
    if (n == m)
        return memo[n][m] = (1 + div(n, n-1)) % MAX_CNT;
    if (n - m >= m)
        return memo[n][m] = (div(n-m, m-1) + div(n, m-1)) % MAX_CNT;
    return memo[n][m] = (div(n-m, m) + div(n, m-1)) % MAX_CNT;
}

int main()
{
    int n, res, m;
    scanf("%d", &n);
    memset(memo, 0, sizeof(memo));
    res = div(n, n);
    printf("%d\n", res);
}