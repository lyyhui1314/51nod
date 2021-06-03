// 1050 循环数组最大子段和
// N个整数组成的循环序列a[1],a[2],a[3],…,a[n]，
// 求该序列如a[i]+a[i+1]+…+a[j]的连续的子段和的最大值（循环序列是指n个数围成一个圈，因此需要考虑a[n-1],a[n],a[1],a[2]这样的序列）。当所给的整数均为负数时和为0。
// 例如：-2,11,-4,13,-5,-2，和最大的子段为：11,-4,13。和为20。
// 输入
// 第1行：整数序列的长度N（2 <= N <= 50000)
// 第2 - N+1行：N个整数 (-10^9 <= S[i] <= 10^9)
// 输出
// 输出循环数组的最大子段和。
// 输入样例
// 9
// 7
// -2
// 11
// -40
// 13
// -5
// -2
// 30
// -1
// 输出样例
// 20

#include <stdio.h>

typedef long long ll;

int n, a[50001];
ll sum = 0, sumNeg = 0, tmpSumNeg = 0, tmpSum = 0, total = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        total += a[i];
    }

    for(int i = 0; i < n; i++)
    {
        if (tmpSum >= 0)
            tmpSum += a[i];
        else
            tmpSum = a[i];
        if (tmpSumNeg >= 0)
            tmpSumNeg += -a[i];
        else
            tmpSumNeg = -a[i];
        if (tmpSum > sum)
            sum = tmpSum;
        if (tmpSumNeg > sumNeg)
            sumNeg = tmpSumNeg;
    }
    printf("%I64d\n", sum > total+sumNeg ? sum : total+sumNeg);
}