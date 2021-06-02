// 1906 子段统计
// 给定一个字符串S，只由k种小写字母组成。现在给定一个长度L，要求统计一下S有多少种不同的长度为L的子段(S中连续的几个字符)。

// 输入
// 单组测试数据。
// 第一行两个整数L和k。（L>=1，1<=k<=26,k^L<=2*10^7）
// 第二行一个字符串S。（1<=|S|<=1000000）
// 输出
// 输出一个整数表示答案。
// 输入样例
// 1 2
// ababab
// 输出样例
// 2

#include <stdio.h>
#include <string.h>
#include <unordered_set>

typedef unsigned long long ull;

char s[1000001];
ull hashArr[1000001];
int l, k, base = 27;

void hash_bkdr(int len)
{
    hashArr[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < len; i++)
        hashArr[i] = hashArr[i - 1] * base + (s[i] - 'a' + 1);
}

int main()
{
    std::unordered_set<ull> subSet;
    scanf("%d%d%s", &l, &k, s);
    ull v, impact_factor = 1, len = strlen(s);
    hash_bkdr(len);

    for (int i = 0; i < l; i++)
        impact_factor *= base;

    subSet.insert(hashArr[l - 1]);
    for (int i = l; i < len; i++)
    {
        v = hashArr[i] - hashArr[i - l] * impact_factor;
        subSet.insert(v);
    }
    printf("%llu\n", subSet.size());
    return 0;
}