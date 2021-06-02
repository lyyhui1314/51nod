// 2071 不相交子区间
// 1.0 秒 131,072.0 KB 5 分 1级题
// 给定 x 轴上 N（0<N<100）条线段 [ai,bi] i=1,2,……N，端点坐标都是区间（－999，999）内的整数。
// 请你编写一个程序，从给出的线段中去掉尽量少的线段，使得剩下的线段两两之间没有内部公共点。
// 所谓的内部公共点是指一个点同时属于两条线段且至少在其中一条线段的内部（即除去端点的部分）。

// 输入
// 输入第一行是一个正整数 N，表示线段个数。
// 接下来有 N 行，第 i 行有两个空格隔开的整数，表示第 i 条线段两个端点的坐标。
// 输出
// 输出一个数，表示最多剩下的线段数。
// 输入样例
// 3
// 6 3
// 1 3
// 2 5
// 输出样例
// 2

#include <algorithm>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int start, end;
} LineSeg;

LineSeg ls[101];

bool cmp(LineSeg s1, LineSeg s2)
{
    return s1.end <= s2.end;
}

int main()
{
    int n, start, end, t = -1000, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &ls[i].start, &ls[i].end);
        if (ls[i].start > ls[i].end)
        {
            ls[i].start ^= ls[i].end;
            ls[i].end ^= ls[i].start;
            ls[i].start ^= ls[i].end;
        }
    }
    std::sort(ls, ls+n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (ls[i].start >= t)
        {
            t = ls[i].end;
            sum++;
        }
    }
    printf("%d\n", sum);
    return 0;
}
