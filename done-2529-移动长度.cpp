// 有n个点，第i号点在一维数轴的i坐标位置。
// 你现在在1号点，你需要移动k次，每次可以移动到1−n的任何一个点，不能够不动，最终移动的总长度为S
// 问这样的方案是否存在。

// 输入
// 第一行三个数n,k,s(2<=n<=10^9,1<=k<=2*10^5,1<=s<=10^18)。
// 输出
// 如果存在方案，输出YES，否则输出NO。
// 输入样例
// 10 2 15
// 输出样例
// YES

#include <stdio.h>

int main(int argc, char const *argv[])
{
    double n, k, s;
    scanf("%lf%lf%lf", &n, &k, &s);
    int flg = s * 1.0 / (n - 1) <= k ? 1 : 0;
    if (flg && k <= s)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
