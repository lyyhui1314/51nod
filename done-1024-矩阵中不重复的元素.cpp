// 1024 矩阵中不重复的元素
// 一个m*n的矩阵。

// 该矩阵的第一列是a^b,(a+1)^b,.....(a + n - 1)^b
// 第二列是a^(b+1),(a+1)^(b+1),.....(a + n - 1)^(b+1)
// .......
// 第m列是a^(b + m - 1),(a+1)^(b + m - 1),.....(a + n - 1)^(b + m - 1)
// (a^b表示a的b次方）

// 下面是一个4*4的矩阵：

// 2^2=4, 2^3=8, 2^4=16, 2^5=32
// 3^2=9, 3^3=27, 3^4=81, 3^5=243
// 4^2=16, 4^3=64, 4^4=256, 4^5=1024
// 5^2=25, 5^3=125, 5^4=625, 5^5=3125

// 问这个矩阵里有多少不重复的数（比如4^3 = 8^2，这样的话就有重复了)

// 2^2=4, 2^3=8, 2^4=16, 2^5=32
// 3^2=9, 3^3=27, 3^4=81, 3^5=243
// 4^2=16, 4^3=64, 4^4=256, 4^5=1024

// m = 4, n = 3, a = 2, b = 2。其中2^4与4^2是重复的元素。
// 输入
// 输入数据包括4个数：m,n,a,b。中间用空格分隔。m，n为矩阵的长和宽（2 <= m,n <= 100)。a，b为矩阵的第1个元素，a^b（2 <= a , b <= 100）。
// 输出
// 输出不重复元素的数量。
// 输入样例
// 4 3 2 2
// 输出样例
// 11

#include <stdio.h>
#include <set>

typedef long long LL;

#define MOD1 LL(1e9 + 7)
#define MOD2 LL(1e7 + 7)

using namespace std;

set<LL> resSet;

LL power(LL a, LL b, LL mod)
{
    LL res = 1;
    while (b)
    {
        if (b & 1)
            res = ((res % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b /= 2;
    }
    return res;
}

void add(int a, int b)
{
    resSet.insert(power(a, b, MOD1)+ power(a, b, MOD2));
}

int main(int argc, char const *argv[])
{
    int m, n, a, b;
    scanf("%d%d%d%d", &m, &n, &a, &b);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            add(a + i, b + j);
    printf("%d\n", resSet.size());
    return 0;
}
