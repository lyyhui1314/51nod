// 2281 树的Size之和
// 给出一棵n个节点的树，节点编号为1-n（根节点编号为1），
// 每一个节点作为根节点与他所有的子孙节点形成一棵子树，而这棵子树包含节点的数量，称作子树的Size。
// 例如：
// 1─2─4─5
// └─3
// 其中节点5的子树只包括节点5，Size = 1。节点4的子树包括节点4，5，Size = 2。节点1的子树包括节点1，2，3，4，5，Size = 5。
// 求以所有节点为根的子树的Size之和。上面例子中，节点1到5，对应的Size分别为5，3，1，2，1，所有Size的和 = 5 + 3 + 1 + 2 + 1 = 12
// 输入
// 第一行：1个数n（1 < n <= 1000），表示树的节点数量。
// 后面n-1行：每行2个数x y，表示节点x是节点y的父节点（1 <= x, y <= n）。
// 输出
// 输出1个数，表示以所有节点为根的子树的Size之和。
// 输入样例
// 5
// 1 2
// 1 3
// 2 4
// 4 5
// 输出样例
// 12

#include <stdio.h>
#include <string.h>

typedef struct {
    int parent;
    int size;
}Node;

Node a[1001];
int n;

void add(int parent, int node)
{
    a[node].parent = parent;
    while(node)
    {
        a[node].size++;
        node = a[node].parent;
    }
}

int main(int argc, char const *argv[])
{
    int v1, v2, sum = 0;
    memset(a, 0, sizeof(a));
    a[1].parent = 0;
    a[1].size = 1;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &v1, &v2);
        add(v1, v2);
    }
    for (int i = 1; i <= n; i++)
        sum += a[i].size;
    printf("%d\n", sum);
    return 0;
}
