// 1889 制铁棒

// 工厂里面，有n根待加工的铁棒，长度以米为单位，精确到小数点后两位（即厘米），现在市场上需求量是m根相同长度的铁棒。
// 现在厂长想把这n根铁棒进行切割，切割的时候要精确到厘米，
// 比如说，原来铁棒是1.00米的，那么可以切成0.50和0.50的，但是不能切成0.499和0.501的。
// 并且不能将两根铁棒拼成一根铁棒。现在厂长想知道切出来的m根铁棒最长能有多长。

// 输入
// 单组测试数据。
// 第一行给出两个整数n(1 <= n<= 10000)和m(1 <= m< = 10000)。
// 接下来n行给出原始铁棒的长度L[1],L[2],L[3],...,L[n] ，(1<=L[i]<=100,000)。以米为单位，精确到小数点后两位。
// 输出
// 输出一个小数表示答案，精确到小数点后两位。
// 输入样例
// 样例输入1
// 4 11
// 8.02
// 7.43
// 4.57
// 5.39
// 输出样例
// 样例输出1
// 2.00

#include <stdio.h>
#include <algorithm>

int n, m, a[10001];

int getNum(int max)
{
    int num = 0;
    for (int i = 0; i < n; i++)
        num += a[i] / max;
    return num;
}

int main()
{
    double len;
    int maxLen = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &len);
        a[i] = len * 100;
        maxLen = std::max(maxLen, a[i]);
    } 

    int num, mid, l = 1, r = maxLen;
    while (l <= r)
    {
        mid = (l+r)/2;
        num = getNum(mid);
        if (num >= m)
            l = mid+1;
        else
            r = mid-1;
    }
    printf("%.2f\n", (r*1.0)/100);
    return 0;
}
