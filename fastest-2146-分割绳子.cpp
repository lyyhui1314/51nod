// 2146 分割绳子
// 1.0 秒 131,072.0 KB 5 分 1级题
// 现在有N(1 <= N <= 1000)条绳子，
// 他们的长度分别为L1，L2，……，Ln(1 <= Li <= 10000)，如果从他们中切割出K(1 <= K <= 1000)条长度相同的绳子，
// 这K条绳子每条最长能多长？

// 输入
// 共有两行，第一行包含两个正整数N和K，用一个空格分割；第二行包含N个数，一次表示N条绳子的长度，两数间用一个空格分隔，每条绳子的长度的小数不超过两位。
// 输出
// 仅包含一个数，表示所得K条绳子的最大长度。答案四舍五入保留小数点后两位

// 原题的样例似乎出了个问题，样例的精确的答案是2.005，四舍五入的话应该是2.01才对。
// 输入样例
// 4 11
// 8.02 7.43 4.57 5.39
// 输出样例
// 2.01

#include <stdio.h>

int n, k, maxLen = 0, a[10001];

int getNum(int len)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] / len;
    return sum;
}

double getMax(int sum)
{
    int num, l = 1, r = sum/k+1, mid = (l+r)/2;
    while (l < r)
    {
        mid = (l + r) / 2;
        num = getNum(mid);
        if (num < k)
            r = mid - 1;
        else if (num >= k)
            l = mid + 1;
    }
    return r%10>4 ? (r+5)/1000.0: r/1000.0;
}

int main(int argc, char const *argv[])
{
    int sum = 0;
    double tmp;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &tmp);
        a[i] = int(tmp * 1000);
        sum += a[i];
    }
    printf("%.2f\n", getMax(sum));
    return 0;
}
