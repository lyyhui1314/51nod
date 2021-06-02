// 小b有一个01序列，她每次可以翻转一个元素，即将该元素从0变1或者从1变0。

// 现在她希望序列不降，求最少翻转次数。

// 输入
// 第一行输入一个数n，其中1≤n≤20000；
// 第二行输入一个由‘0’和‘1’组成的字符串
// 输出
// 输出一个非负整数，表示翻转次数
// 输入样例
// 6
// 010110
// 输出样例
// 2

#include <stdio.h>

typedef struct node
{
    char data;
    int pre;
    int post;
} Node;

Node a[20001];

int main()
{
    int i, n, min = 20001;
    scanf("%d %c", &n, &a[0].data);
    a[0].pre = 0;
    a[n - 1].post = 0;
    for (i = 1; i < n; i++)
    {
        scanf(" %c", &a[i].data);
        a[i].pre = a[i - 1].data == '1' ? a[i - 1].pre + 1 : a[i - 1].pre;
    }
    while (i--)
        a[i].post = a[i + 1].data == '0' ? a[i + 1].post + 1 : a[i + 1].post;
    for (int j = 0; j < n; j++)
        if (a[j].pre + a[j].post < min)
            min = a[j].pre + a[j].post;
    printf("%d\n", min);
}