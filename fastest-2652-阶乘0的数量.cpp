// 2652 给出一个数k，求最小的n，使得n的阶乘后面0的数量>=k。

// 例如k=1，

// 5的阶乘 = 1*2*3*4*5 = 120，120后面有1个0。并且4的阶乘后面没有0，所以5是最小的结果。

// 输入
// 一个数k(1 <= k <= 10^9)
// 输出
// 输出最小的满足条件的n.
// 输入样例
// 1
// 输出样例
// 5

#include <math.h>
#include <stdio.h>

typedef long long ll;

// 得到n阶乘的0的数量，打表可得0个数规律为0-4为0个，5-9为1个，10-14为2个，即n的0的数量为n/5个
ll getNum(ll n)
{
    ll num = 0;
    while (n)
    {
        n /= 5;
        num += n;
    }
    return num;
}

int main()
{
    ll l = 0, r = 1e12 + 1, mid, k, num;
    scanf("%lld", &k);
    while(l < r)
    {
        mid = (l + r) / 2;
        num = getNum(mid);
        if (num >= k)
            r = mid;
        else
            l = mid+1;
    }
    printf("%lld\n", r);
    return 0;
}
