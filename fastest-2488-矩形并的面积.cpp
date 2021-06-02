// 2488 矩形并的面积
// 2.0 秒 262,144.0 KB 5 分 1级题
// 在二维平面上，给定两个矩形，满足矩形的每条边分别和坐标轴平行，求这个两个矩形的并的面积。即它们重叠在一起之后的总的面积。

// 输入
// 8个数，分别表示第一个矩形左下角坐标为(A,B)，右上角坐标为(C,D)；第二个矩形左下角坐标为(E,F)，右上角坐标为(G,H)。
// 保证A<C，B<D，E<G，F<H。
// 保证所有数的绝对值不超过2*10^9，矩形并的面积≤2*10^9。
// 输出
// 输出一个数表示矩阵并的面积。
// 输入样例
// -3 0 3 4 0 -1 9 2
// 输出样例
// 45

#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct
{
    int x1, y1, x2, y2, area;
} Rectangle;

Rectangle a, b, c;

int main(int argc, char const *argv[])
{
    scanf("%d%d%d%d%d%d%d%d", &a.x1, &a.y1, &a.x2, &a.y2, &b.x1, &b.y1, &b.x2, &b.y2);
    c.x1 = max(a.x1, b.x1);
    c.y1 = max(a.y1, b.y1);
    c.x2 = min(a.x2, b.x2);
    c.y2 = min(a.y2, b.y2);
    a.area = (a.x2 - a.x1) * (a.y2 - a.y1);
    b.area = (b.x2 - b.x1) * (b.y2 - b.y1);
    c.area = (c.x2 - c.x1) * (c.y2 - c.y1);
    if (c.x2 > c.x1 && c.y2 > c.y1)
        printf("%d\n", a.area + b.area - c.area);
    else
        printf("%d\n", a.area + b.area);
    return 0;
}
