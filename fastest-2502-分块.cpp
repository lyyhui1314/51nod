// 2502 小b有个长度为n的数组a，她想将这个数组排序。

// 然而小b很懒，她觉得对整个数组排序太累了，因此她请你将a分成一些块，使得她只需要对每一块分别排序，就能将整个数组排序。

// 请问你最多能把a分成多少块。

// 保证a为0...n-1的一个排列。

// 样例解释：

// 将a分成2块或者更多块，都无法得到所需的结果。
// 例如，分成 [4, 3], [2, 1, 0] ，排序得到的结果是 [3, 4, 0, 1, 2]，这不是有序的数组。

// 输入
// 第一行一个数n；
// 第二行n个数表示a[i]，以空格隔开。
// n<=10
// 输出
// 输出一个数表示划分块的数量
// 输入样例
// 5
// 4 3 2 1 0
// 输出样例
// 1

#include <math.h>
#include <limits.h>
#include <stdio.h>

int n, a[11], cnt, preMax[11] = {INT_MIN};

void mergeBlock()
{
    int i = 0, div, min, k = 0;
    while (i < n)
    {
        div = i, min = a[i];
        while (++i < n && a[i] < a[div])
        {
            cnt--;
            if (a[i] < min)
                min = a[i];
        }
        while (k > -1 && preMax[k--] > min)
            cnt--;
        k++;
        preMax[++k] = a[div];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    cnt = n;
    mergeBlock();
    printf("%d\n", cnt);
    return 0;
}
