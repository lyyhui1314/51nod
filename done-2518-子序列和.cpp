// 小b有一个01序列A，她想知道A有多少个非空连续子序列和为S。

// 你能帮帮她吗？

// 输入
// 第一行输入一个数n，表示A的长度；
// 第二行输入n个数‘0’或‘1’，表示A中的元素，以空格隔开；
// 第三行输入一个非负整数S；
// 其中0≤S≤n≤30000。
// 输出
// 输出一个数，表示子数组的个数
// 输入样例
// 5
// 1 0 1 0 1
// 2
// 输出样例
// 4

#include <stdio.h>

long long cnt = 0;
int n, a[30001], s, sum;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &s);
    if (n == 1)
    {
        if ((s == 0 && a[0] == 0) || (s == 1 && a[0] == 1))
            printf("1\n");
        else
            printf("0\n");
        return 0;
    }
    int i = 0, j = 0, sum = a[0];
    while (i < n && j < n)
    {
        if (sum < s)
        {
            j++;
            if (j == n)
                break;
            if (i == j)
                sum = a[i];
            else
                sum += a[j];
        }
        else if (sum == s)
        {
            cnt++;
            int js = j;
            while (a[++j] == 0 && j < n)
                cnt++;
            if (i == js)
            {
                j = js + 1;
                sum += a[j];
            }
            else
                j = js;
            i++;
            sum -= a[i - 1];
        }
        else
        {
            if (i == j){
                j++;
                sum += a[j];
            }
            i++;
            if (i == n)
                break;
            else
                sum -= a[i - 1];
        }
    }
    printf("%lld\n", cnt);
}
