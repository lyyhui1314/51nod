// 2627 树的深度及子树大小
// 1.0 秒 131,072.0 KB 5 分 1级题
// 现在有一棵n个节点的树，节点1为这棵树的根，求出每个节点的深度以及每个节点的子树中的节点个数。

// 输入
// 第1行：一个数字n，表示树中节点的个数。(1<=n<=100000)
// 第2-n行：每行两个数字u,v，表示u与v之间有一条边。(1<=u,v<=n)
// 输出
// 输出2行，每行n个正整数，第1行的第i个正整数表示节点i的深度，第2行的第i个正整数表示以节点i为根的子树大小。
// 输入样例
// 10
// 1 2
// 1 3
// 1 4
// 2 5
// 2 8
// 4 6
// 4 7
// 6 9
// 6 10
// 输出样例
// 1 2 2 2 3 3 3 3 4 4 
// 10 3 1 5 1 3 1 1 1 1

#include <stdio.h>
#include <string.h>

typedef struct tree
{
    int parent;
    int size;
    int depth;
}Tree;

Tree t[100001];

void add(int u, int v)
{
    t[v].depth = t[u].depth + 1;
    t[v].parent = u;
    int node = v;
    while (node)
    {
        t[node].size += 1;
        node = t[node].parent;
    }
}

void init(int n)
{
    t[1].parent = 0;
    t[1].depth = 1;
    t[1].size = 1;
    for (int i = 2; i <= n; i++)
        t[i].depth = t[i].parent = t[i].size = 0;
}


int main(int argc, char const *argv[])
{
    int n, u, v;
    scanf("%d", &n);
    init(n);
    
    for (int i = 0; i < n-1; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", t[i].depth);
    printf("\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", t[i].size);
    return 0;
}
