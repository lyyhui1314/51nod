// 3064 小明喜欢树
// 小明很喜欢树，现在小明得到一棵树，现在小明想知道树的每一层的节点权值最大值是多少，聪明的你可以可以帮助小明解决这个问题吗。
// 输入
// 第一行输入一个整数n(1 <= n <= 100000)
// 接下来n行，每行有两个整数，对于第i行，表示编号为i的节点的父节点编号(没有父节点编号为0)以及编号为i的节点的权值(1<=权值<=1e9,1为根节点)。
// 输出
// 输出每一层的最大节点编号是几，每两个数字之间用空格隔开。
// 数据范围
// 对于10%的数据，1 <= n <= 4
// 对于50%的数据，1 <= n <= 1024
// 对于100%的数据，1 <= n <= 100000，权值<=5*n
// 输入样例
// 6
// 0 1
// 1 3
// 1 2
// 3 5
// 3 3
// 2 9
// 输出样例
// 1 3 9

#include <stdio.h>

typedef struct {
    int par, weight, depth;
}Node;

int n, cnt = 0, weight[100001];
Node a[100001];


int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    a[1].par = 0, a[1].depth = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].par, &a[i].weight);
        a[i].depth = a[a[i].par].depth+1;
        if (a[i].weight > weight[a[i].depth])
            weight[a[i].depth] = a[i].weight;
    }
    for (int i = 1; weight[i]; i++)
    {
        printf("%d ", weight[i]);
    }
    return 0;
}


