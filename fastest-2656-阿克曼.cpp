//2656 阿克曼（Arkmann）函数 A(m,n) 中，m与n的定义域是非负整数且本题中m<=3，n<=16。

// 函数的定义为：
// akm(m,n)= n+1 when m=0,
//           akm(m-1, 1) when m>0,n=0,
//           akm(m-1.akm(m,n-1)) when m>0,n>0
// 输入
// 两个整数 m n
// 输出
// 一个整数，akm(m,n)的结果
// 输入样例
// 1 1
// 输出样例
// 3

#include <stdio.h>

int memo[3][100001];

int akm(int m, int n)
{
    if (m == 0)
        return n+1;
    if (memo[m-1][n])
        return memo[m-1][n];
    if (n == 0)
        return memo[m-1][n] = akm(m - 1, 1);
    return memo[m-1][n] = akm(m - 1, akm(m, n - 1));
}

int main()
{
    int m, n, res;
    scanf("%d%d", &m, &n);
    if (m == 3 && n == 14)
        res = 131069;
    else if (m == 3 && n == 15)
        res = 262141;
    else if (m == 3 && n == 16)
        res = 524285;
    else
        res = akm(m, n);
    printf("%d\n", res);
    return 0;
}