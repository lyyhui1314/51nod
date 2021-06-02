// 给出区间(a,b)，b >= a，求a xor (a+1) xor (a+2).....xor b。

// 输入
// 输入2个数：a b，中间用空格分隔(1 <= a <= b <= 10^9)
// 输出
// 输出一个答案
// 输入样例
// 3 8
// 输出样例
// 11

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = a+1; i < b+1; i++)
    {
        a ^= i;
    }
    printf("%d\n", a);
    return 0;
}
