// 3022 奇怪的二叉树
// 现在给定一棵二叉树，让你判断这棵二叉树是不是二叉平衡树，聪明的你可以解决这个问题吗？
// 输入
// 第一行包括一个整数K(1<=K<=5)，表示数据的组数。
// 第二行输入一个整数n(1 <= n <= 50000)
// 接下来n行，每行有两个整数，第i行表示编号为i的结点的左子节点和右子节点的编号（没有该子节点，则输入0）。
// 输出
// 输出包括K行，如果是二叉平衡树，输出“Yes”，否则输出“No”。(输出不包含引号)
// 数据范围
// 对于10%的数据，1 <= n <= 2500
// 对于50%的数据，1 <= n <= 25000
// 对于100%的数据，1 <= n <= 50000，数据组数 K<= 5
// 输入样例
// 3
// 5
// 2 0
// 3 4
// 0 0
// 5 0
// 0 0
// 2
// 2 0
// 0 0
// 3
// 2 3
// 0 0
// 0 0
// 输出样例
// No
// Yes
// Yes


#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef struct
{
    int l, r, max;
} Node;

int k, n;
Node a[50001];

int cal(int i)
{
    if (i == 0)
        return 0;
    if (a[i].max)
        return a[i].max;
    if (!a[i].l && !a[i].r)
        return a[i].max = 1;
    if (!a[i].l)
        return a[i].max = cal(a[i].r) + 1;
    if (!a[i].r)
        return a[i].max = cal(a[i].l) + 1;
    return a[i].max = max(cal(a[i].l), cal(a[i].r)) + 1;
}

int main(int argc, char const *argv[])
{
    int lc, rc, eq, i;
    scanf("%d", &k);
    while (k--)
    {
        memset(a, 0,sizeof(a));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &a[i].l, &a[i].r);
        cal(1);
        for (i = 1; i <= n; i++)
        {
            lc = a[i].l, rc = a[i].r, eq = a[lc].max - a[rc].max;
            if (eq > 1 || eq < -1)
                break;
        }
        if (i > n)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
