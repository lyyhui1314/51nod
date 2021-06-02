// 1031 骨牌覆盖
// 在2*N的一个长方形方格中，用一个1*2的骨牌排满方格。
// 问有多少种不同的排列方法。
// 例如：2 * 3的方格，共有3种不同的排法。（由于方案的数量巨大，只输出 Mod 10^9 + 7 的结果）
//  + - *       + + *       * + +
//  + - *       - - *       * - -
//
// 输入
// 输入N(N <= 1000)
// 输出
// 输出数量 Mod 10^9 + 7
// 输入样例
// 3
// 输出样例
// 3

#include <stdio.h>

#define MOD int(1e9 + 7)

int n, res[1001] = {0, 1, 2};

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 3; i <= n; i++)
        res[i] = (res[i - 1] % MOD + res[i - 2] % MOD) % MOD;
    printf("%d\n", res[n]);
    return 0;
}
