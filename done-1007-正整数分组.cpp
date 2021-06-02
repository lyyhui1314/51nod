// 1007 正整数分组
// 1.0 秒 131,072.0 KB 10 分 2级题
// 将一堆正整数分为2组，要求2组的和相差最小。
// 例如：1 2 3 4 5，将1 2 4分为1组，3 5分为1组，两组和相差1，是所有方案中相差最少的。
// 输入
// 第1行：一个数N，N为正整数的数量。
// 第2 - N+1行，N个正整数。
// (N <= 100, 所有正整数的和 <= 10000)
// 输出
// 输出这个最小差
// 输入样例
// 5
// 1
// 2
// 3
// 4
// 5
// 输出样例
// 1

#include <stdio.h>
#include <string.h>
#include <algorithm>

int n, a[101], dp[10001];

int main()
{
    int maxC, sum = 0;
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    maxC = sum / 2;
    for (int i = 0; i <= maxC; i++)
            dp[i] = a[0] <= i ? a[0] : 0;
    for (int i = 1; i < n; i++)
        for (int j = maxC; j >= a[i]; j--)
                dp[j] = std::max(dp[j-a[i]]+a[i], dp[j]);
    printf("%d\n", abs(2*dp[maxC]-sum));
    return 0;
}
