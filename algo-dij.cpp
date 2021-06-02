#include <stdio.h>

#define V_MAX 101    // 顶点个数
#define E_INF 100007 // 无边时权值用该值代替
#define CAL_DONE 1   // 顶点最短路径已计算完成

typedef struct
{
    int stat;  // 顶点状态，1表示已在最短路径中，0为不在
    int len;   // 从起点到该顶点的最短长度
    int pre_v; // 该顶点在最短路径上的前驱顶点,若无法到达，则置为0
} Path;

typedef struct
{
    int v_start;              // 起点
    int v_cnt;                // 顶点个数
    int weight[V_MAX][V_MAX]; //权值矩阵，非负，E_INF表示无边
    Path v_end[V_MAX];        // 以顶点i为最短路径终点的信息
} Graph;

Graph g;

// 下三角矩阵，存储无向图的权值矩阵，第0个元素为矩阵行数，矩阵值从(2,1)开始，(3,1), (3,2), (4,1)...
// int ltm[V_MAX] = {5, 50, 30, 5, 100, 20, 50, 10, -1, -1, 10};
int ltm[V_MAX * V_MAX] = {17, 85, 84, 13, 70, 100, 22, 86, 65, 53, 96, 28, 40, 53, 93, 6, 1, 84, 1, 64, 73, -1, 76, 55, 63, 30, 41, -1, 30, 4, 14, 15, 72, 84, 51, 75, 63, 8, 83, 83, 75, 49, 50, 81, 85, 10, 16, 71, 92, 26, 54, 45, 39, 93, 89, 17, 49, 56, 13, 2, 76, 56, 88, 73, 99, 91, 44, -1, 28, 83, 75, 55, 74, 61, -1, 4, 99, 28, 48, 17, 49, 96, 75, 38, 4, 77, 19, 2, 59, 34, 50, 63, 64, 4, 81, 80, 79, 64, -1, 75, 5, 22, 16, 46, 53, 36, 77, 31, 75, 28, 76, 1, 37, 23, 5, 51, 8, 86, 8, 37, 23, 4, 53, 81, 84, 63, 74, 47, 42, 27, 24, 90, 61, 99, 14, 65, 61};

void init()
{
    int k = 1;
    g.v_start = 1;
    g.v_cnt = ltm[0];
    for (int i = 1; i <= g.v_cnt; i++)
        for (int j = 1; j < i; j++)
            g.weight[j][i] = g.weight[i][j] = ltm[k++];
    for (int i = 1; i <= g.v_cnt; i++)
    {
        g.v_end[i].len = g.weight[g.v_start][i];
        if (g.v_end[i].len != E_INF)
            g.v_end[i].pre_v = g.v_start;
    }
    g.v_end[g.v_start].stat = CAL_DONE;
}

void printWeight()
{
    for (int i = 1; i <= g.v_cnt; i++)
    {
        for (int j = 1; j <= g.v_cnt; j++)
            printf("%d ", g.weight[i][j]);
        printf("\n");
    }
}

void printPath(int end)
{
    if (g.v_end[end].len == E_INF)
        printf("the shortest path does not include the vertex: %d\n", end);
    else if (end == g.v_start)
        printf("%d", g.v_start);
    else
    {
        printPath(g.v_end[end].pre_v);
        printf(" -> %d", end);
    }
}

void calPath()
{
    int min;
    int j, k = g.v_start;
    while (1)
    {
        j = 0;
        while (g.v_end[++j].stat == CAL_DONE)
            ;
        if (j > g.v_cnt)
            break;
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
        if (g.v_end[min].len == E_INF)
            break;
        g.v_end[min].stat = 1;
        g.v_end[min].pre_v = k;
        k = min;
    }
}

int main(int argc, char const *argv[])
{
    init();
    calPath();
    return 0;
}
