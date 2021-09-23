// 1092 回文字符串
// 1.0 秒 131,072.0 KB 10 分 2级题
// 回文串是指aba、abba、cccbccc、aaaa这种左右对称的字符串。每个字符串都可以通过向中间添加一些字符，使之变为回文字符串。

// 例如：abbc 添加2个字符可以变为 acbbca，也可以添加3个变为 abbcbba。方案1只需要添加2个字符，是所有方案中添加字符数量最少的。

// 输入
// 输入一个字符串Str，Str的长度 <= 1000。
// 输出
// 输出最少添加多少个字符可以使之变为回文字串。
// 输入样例
// abbc
// 输出样例
// 2

#include <stdio.h>
#include <string.h>

#include <algorithm>

using namespace std;

char s[1001];
int cost[1001][1001] = {{0}};

int calc(int si, int slen)
{
    if (slen <= 1)
        return cost[si][slen];
    if (cost[si][slen])
        return cost[si][slen];
    if (s[si] == s[si+slen-1])
        return cost[si][slen] = calc(si+1, slen-2);
    else
        return cost[si][slen] = min(calc(si, slen-1), calc(si+1, slen-1)) + 1;
}

int main(int argc, char const *argv[])
{
    scanf("%s", s);
    printf("%d\n", calc(0, strlen(s)));
    return 0;
}
