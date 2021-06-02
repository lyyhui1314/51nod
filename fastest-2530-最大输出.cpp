// 给定n个技能，每个技能能打掉对手ai的血，你一共有m次发招的机会，你不能连续使用某一个技能超过k次。问你最多能打掉对手多少血。

// 输入
// 第一行3个数n,m,k，(2<=n<=2*10^5,1<=m,k<=10^9)
// 第二行n个数a[1...n]，(1<=a[i]<=10^9)
// 输出一个数，表示最大值。
// in
// 6 9 2        |   3 1000000000 1
// 1 3 3 7 4 2  |   1000000000 987654321 1000000000
// out
// 54           |   1000000000000000000

#include <stdio.h>

int main(int argc, char const *argv[])
{
    long long n, m, k, max = 0, secMax = 0, s, sum = 0;
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &s);
        if (s >= max)
        {
            secMax = max;
            max = s;
        }
        else if (s >= secMax && s <= max)
            secMax = s;
    }
    sum = m / (k + 1) * (max * k + secMax) + (m % (k + 1)) * max;
    printf("%lld\n", sum);
    return 0;
}
