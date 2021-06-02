// 2497 数三角形
// 小b有一个仅包含非负整数的数组a，她想知道有多少个三元组(i,j,k)，满足i<j<k且a[i],a[j],a[k]可能作为某个三角形的三条边的边长。
// 输入
// 第一行输入一个正整数n，表示数组a中元素个数；
// 第二行n个非负整数，表示a中元素，以空格隔开；
// 其中0＜n≤1000，a中任意元素a[i]满足0≤a[i]≤1000。
// 输出
// 输出一个数，表示满足题意的三元组个数
// 输入样例
// 4
// 2 2 3 4
// 输出样例
// 3

#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[1001], cnt = 0;

int get_cnt(int index, int sum)
{
    int l = index, r = n, mid;
    while (l < r)
    {
        mid = (l+r)/2;
        if (a[mid] < sum)
            l = mid + 1;
        else
            r = mid;
    }
    return l - index;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            cnt += get_cnt(j + 1, a[i] + a[j]);
    }
    printf("%d\n", cnt);
    return 0;
}
