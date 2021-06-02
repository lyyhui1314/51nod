// 1740 蜂巢迷宫
// 有一个无限大的蜂巢迷宫，为了方便表示每一个六边形格子，现在把座标引入到这个迷宫中.
// (-3, 2)       (-1, 2)      (1, 2)      (3, 2)
//
//        (-2, 0)       (0, 0)      (2, 0)
//
//               (-1,-2)      (1,-2)
// 艾瑞特在这个迷宫中街，刚开始他在(0,0)的位置，按照下图所示的路线在这个迷宫中行走。
// (0, 0) (1, 2) (-1, 2) (-2, 0) (-1, -2) (1, -2) (2, 0)
// 走了n步以后，他想知道自己在哪个位置了。

// 输入
// 单组测试数据。
// 一个整数n (0≤n≤10^18)，表示艾瑞特移动的步数。
// 输出
// 输出两个整数x和y，表示艾瑞所在的座标。
// 输入样例
// 3
// 输出样例
// -2 0

#include <stdio.h>

typedef long long LL;

LL xOffset[6] = {-1, -2, -1, 1, 2, 1}, yOffset[6] = {2, 0, -2, -2, 0, 2}, xStart[6] = {2, 1, -1, -2, -1, 1}, yStart[6] = {0, 2, 2, 0, -2, -2};

LL getDepth(LL step)
{
    LL multi = step / 6 + 1, l = 1, r = 1e9 + 1, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (mid * (mid - 1) / 2 + 1 > multi) // x*(x-1)/2+1表示该层最小倍数
            r = mid - 1;
        else if (mid * (mid + 1) / 2 < multi) // x*(x+1)/2表示该层最大倍数
            l = mid + 1;
        else
            return mid;
    }
    return l;
}

int main(int argc, char const *argv[])
{
    LL n;
    scanf("%lld", &n);
    LL depth = getDepth(n); // 6边形层数
    LL multi = depth * (depth - 1);
    LL first = 3 * multi;          // 到达6边形第一个点的步数, depth(depth-1)/2+1 = first/6+1
    LL edge = (n - first) / depth; // 边
    LL sequ = (n - first) % depth; // n到所在边第一个点的步数
    // 边的第一个点的横纵坐标
    if (!edge)
        depth--;
    xStart[edge] *= depth;
    yStart[edge] *= depth;
    // 特殊处理在x轴上的点
    if (!edge && sequ)
    {
        xStart[edge] += 1;
        yStart[edge] += 2;
        sequ--;
    }
    xStart[edge] += xOffset[edge] * sequ;
    yStart[edge] += yOffset[edge] * sequ;

    printf("%I64d %I64d\n", xStart[edge], yStart[edge]);
    return 0;
}
