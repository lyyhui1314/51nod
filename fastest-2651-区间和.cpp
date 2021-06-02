// 输入一个长度为n的数组a，a包括(n+1)n/2个区间。每个区间所有数的和，被称为区间和，求所有(n+1)n/2个区间和的和。由于数值较大，输出mod 1e9+7的结果。

// 例如：

// 3个数1 2 3，共有6个子区间，包含的数字如下：

// {1} {2} {3} {1 2} {2 3} {1 2 3}，这些区间求和为1 2 3 3 5 6，这6个数字再求和为20.

// 输入
// 第一行一个整数n，表示数组长度(2<=n<=100000)
// 接下来n行，每行一个整数ai，表示数组的内容。(0<=ai<=50000)
// 输出
// 输出答案mod 1e9+7
// 输入样例
// 3
// 1
// 2
// 3
// 输出样例
// 20

#include <stdio.h>

int MOD_NUM = (int)(1e9 + 7);

long long a[100001];
long long sum = 0;

int main(int argc, char const *argv[])
{
    long long n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (long long i = 1; i <= n; i++)
        sum += (i * (n - i + 1)) % MOD_NUM * a[i] % MOD_NUM;
    printf("%lld\n", sum%MOD_NUM);
    return 0;
}
