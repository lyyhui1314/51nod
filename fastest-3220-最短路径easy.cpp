// 3220 最短路径 easy ver.
// 给出一张包含n个节点、m条边的无向图（无重边，无自环），请你求出图上两点s,t间的最短路径长度。
// 输入
// 第一行两个数n,m，分别表示节点数和边数，以空格隔开，其中1≤n≤500,1≤m≤10000；
// 之后m行，每行3个数u,v,w[i]，表示点u和v间有一条权值为w[i]的边，
// 其中1≤u,v≤n，1≤w[i]≤500000；
// 最后一行，两个数s,t表示选择的两个点，以空格隔开。
// 输出
// 输出一个数，表示s,t间最短路径的长度。
// 输入样例
// 4 3
// 1 2 6
// 1 3 4
// 2 4 2
// 3 4
// 输出样例
// 12

#include <stdio.h>

#define CAL_DONE 1
#define V_MAX 501
#define E_INF 500001

typedef struct
{
    int stat;
    int len;
} Path;

typedef struct
{
    int v_start;
    int v_cnt;
    int v_dest;
    int weight[V_MAX][V_MAX];
    Path v_end[V_MAX];
} Graph;

Graph g;

void calPath()
{
    int min;
    int j, k = g.v_start;
    while (1)
    {
        j = 0;
        if (g.v_end[g.v_dest].stat == CAL_DONE)
            break;
        while (g.v_end[++j].stat)
            ;
        min = j;
        for (int i = 1; i <= g.v_cnt; i++)
        {
            if (g.v_end[i].stat != CAL_DONE)
            {
                if (g.v_end[k].len + g.weight[k][i] < g.v_end[i].len)
                    g.v_end[i].len = g.v_end[k].len + g.weight[k][i];
                if (g.v_end[i].len < g.v_end[min].len)
                    min = i;
            }
        }
        g.v_end[min].stat = 1;
        k = min;
    }
}

int main(int argc, char const *argv[])
{
    int row, col, w, eCnt;
    scanf("%d%d", &g.v_cnt, &eCnt);
    g.v_start = 1;
    for (int i = 1; i <= eCnt; i++)
    {
        scanf("%d%d%d", &row, &col, &w);
        g.weight[row][col] = g.weight[col][row] = w;
    }
    for (int i = 1; i <=g.v_cnt; i++)
        for (int j = 1; j < i; j++)
            if (!g.weight[i][j])
                g.weight[i][j] = g.weight[j][i] = E_INF;
    g.weight[1][1] = 0;
    scanf("%d%d", &g.v_start, &g.v_dest);
    for (int i = 1; i <= g.v_cnt; i++)
        g.v_end[i].len = g.weight[g.v_start][i];
    g.v_end[g.v_start].stat = CAL_DONE;
    calPath();
    printf("%d\n", g.v_end[g.v_dest].len);
    return 0;
}
