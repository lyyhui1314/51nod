// 3051 找数字 V2
// 将大于0的整数写成一排组成一个无限长的数，即：
// 12345678910111213141516....
// 问这个数的第n位的数字是什么？
// 输入
// 第一行：1个数T表示询问的数量（2≤T≤100000）。
// 第2至n+1行：每行1个数，对应询问的 n 。（1≤n≤10^9）
// 输出
// 输出共t行，对应t次询问的答案。
// 数据范围
// 对于4%的数据，2≤T≤10，1≤n≤100；
// 对于40%的数据，2≤T≤500，1≤n≤50000；
// 对于100%的数据，2≤T≤100000，1≤n≤10^9；
// 输入样例
// 3
// 3
// 10
// 21
// 输出样例
// 3
// 1
// 5

#include <stdio.h>
#include <math.h>
#include <sstream>

int a[9];

void genArr()
{
    a[0] = 0;
    for (int i = 1; i < 9; i++)
    {
        a[i] = a[i - 1] + 9 * i * int(pow(10, i - 1));
    }
}

int main()
{

    genArr();
    int t, n, offset, seq, v, base_offset, i;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (i = 1; i < 9; i++)
        {
            if (n <= a[i])
                break;
        }
        offset = n - a[i - 1];
        if (offset == 1)
            printf("1\n");
        else if (offset <= i)
            printf("0\n");
        else
        {
            base_offset = offset % i;
            if (base_offset == 0)
                base_offset = i;
            if (base_offset == i)
                seq = offset / i - 1;
            else
                seq = offset / i;
            v = int(pow(10, i-1)) + seq;
            printf("%c\n", std::to_string(v)[base_offset-1]);
        }
    }
}