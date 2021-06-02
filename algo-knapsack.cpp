#include <algorithm>
#include <stdio.h>
#include <string.h>
// 背包容量
#define Capa 5
// 物品个数
#define Cnt 4

// w: 重量, v: 价值
int w[Cnt] = {2, 1, 3, 2}, v[4] = {12, 10, 20, 15};

// 递归
int maxValueByRecu(int index, int remain)
{
    if (remain <= 0 || index < 0)
        return 0;
    int res = maxValueByRecu(index - 1, remain); // 当前物品不放入背包
    // 若当前物品可放入背包，则比较放入背包和不放的最大价值
    // 当前物品i放入背包的最大价值为：前i-1个中背包剩余为j-w[i]的价值加上i的价值
    if (w[index] <= remain)
        res = std::max(res, maxValueByRecu(index - 1, remain - w[index]) + v[index]);
    return res;
}

// 记忆话搜索，保存已经搜索过的结果
int memo[Cnt + 1][Capa + 1];
int maxValueByMemo(int index, int remain)
{
    if (remain <= 0 || index < 0)
        return 0;
    if (memo[index][remain])
        return memo[index][remain];
    int res = maxValueByMemo(index - 1, remain);
    if (w[index] <= remain)
        res = std::max(res, maxValueByMemo(index - 1, remain - w[index]) + v[index]);
    memo[index][remain] = res;
    return res;
}

// 动态规划，保存所有结果
int dp[Cnt + 1][Capa + 1];
int maxValueByDP(int index, int remain)
{
    for (int i = 0; i < remain; i++)
    {
        dp[0][i] = w[0] <= i ? v[0] : 0;
    }

    for (int i = 1; i < index; i++)
    {
        for (int j = 0; j <= remain; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (w[i] <= j)
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    return dp[index - 1][remain];
}

// 空间优化，由于f(i, j) = max(f(i-1, j), f(i-1, j-w[i])+v[i]), 第i个结果需要用到i-1的结果，且会覆盖i-1的结果，所以从后向前计算
int dpOpti[Capa + 1];
int maxValueByOpti(int index, int remain)
{
    for (int i = 0; i <= remain; i++)
        dpOpti[i] = w[0] <= i ? v[0] : 0;
    for (int i = 1; i < index; i++)
        for (int j = remain; j >= w[i]; j--)
            dpOpti[j] = std::max(dpOpti[j], dpOpti[j - w[i]] + v[i]);
    return dpOpti[remain];
}

int main()
{
    int maxV;

    maxV = maxValueByRecu(Cnt, Capa);
    printf("%d\n", maxV);

    memset(memo, 0, sizeof(memo));
    maxV = maxValueByMemo(Cnt, Capa);
    printf("%d\n", maxV);

    memset(dp, 0, sizeof(dp));
    maxV = maxValueByDP(Cnt, Capa);
    printf("%d\n", maxV);

    memset(dpOpti, 0, sizeof(dpOpti));
    maxV = maxValueByOpti(Cnt, Capa);
    printf("%d\n", maxV);
    return 0;
}