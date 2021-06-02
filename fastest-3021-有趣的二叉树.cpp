// 3021 有趣的二叉树
// 小明很喜欢树，尤其喜欢二叉树，今天小明得到了一个有趣的二叉树问题，
//问题是这样的，给定一棵二叉树的前序和中序，现在要你求出来该二叉树的后序.
// 输入
// 输入包括三行数据，第一行包括一个数n(1=<n<=50000)，表示二叉树的节点个数。
// 第二行n个数表示这颗二叉树的前序遍历序列。
// 第三行n个数表示这颗二叉树的中序遍历序列。
// (两个数之间用空格分开)。
// 输出
// 输出包括一行n个数，表示二叉树的后序遍历序列，以空格隔开。
// 数据范围
// 对于10%的数据，1 <= n <= 2500
// 对于50%的数据，1 <= n <= 25000
// 对于100%的数据，1 <= n <= 50000
// 输入样例
// 5
// 1 2 3 4 5
// 3 2 5 4 1
// 输出样例
// 3 5 4 2 1

#include <stdio.h>

int n, pre[50001], mid[50001];

void postOrder(int preIdx, int midIdx, int maxIdx)
{
    if (midIdx == maxIdx)
        return;
    int leftCnt = 0;
    for (int i = midIdx; i < maxIdx && mid[i] != pre[preIdx]; leftCnt++, i++)
        ;
    postOrder(preIdx + 1, midIdx, midIdx + leftCnt);
    postOrder(preIdx + leftCnt + 1, midIdx + leftCnt + 1, maxIdx);
    printf("%d ", pre[preIdx]);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &mid[i]);
    postOrder(0, 0, n);
    return 0;
}
