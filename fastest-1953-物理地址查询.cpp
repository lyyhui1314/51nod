// 1953 物理地址查询
// 在网络中，发送一个包需要知道对方的物理地址，当不知道物理地趣的时候，就要向网络中广播发送对方的IP地址，
// 然后每一台计算会收到这个广播，如果IP和自己的计算对上，就把自己的物理地址发送出去。
// 现在有n台计算，编号从1到n，现在1号计算向网络中发送广播，问经过多少时间后所有的计算机都会收到这个广播。
// 输入的网络保证所有的计算机之间是可以相互通信的。

// 输入
// 单组测试数据。
// 第一行有一个整数n(1 <= n <= 100)。
// 接下来输入一个邻接矩阵A，A的大小是n x n。里面的元素要么是一个非负整数，或者是一个字符x。
// 如果A[i][j]是x, 那么第i台计算机和第j台计算机没有直接相连。否则表示信号在第i台计算机和第j台计算机之间传播需要A[i][j]的时间。
// 自己发给自己是不需要时间的所以对于所有的 1 <= i <= n，A[i][i] = 0。
// 输入的网络是一个无向图，所以A[i][j] = A[j][i]。那么只需要输入矩阵的下三角部分即可。
// 那么接下来给出n-1行，
// 第一行有一个整数表示A[2][1]。
// 第二行有两个整数表示A[3][1]和A[3][2]。
// 。。。
// 第n-1行有n-1个整数A[n][1],A[n][2], A[n][3]... A[n][n-1]。
// 0<=A[i][j]<=100。
// 输出
// 输出一个整数表示答案。
// 输入样例
// 样例输入1
// 5
// 50
// 30 5
// 100 20 50
// 10 x x 10
// 输出样例
// 样例输出1
// 35

#include <stdio.h>
#include <string.h>
#define E_INF 101
#define V_MAX 101

int n, v[V_MAX], graph[V_MAX][V_MAX], dist[V_MAX];

int main(int argc, char const *argv[])
{
    char str[5];
    int k = 1, min = 2;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            scanf("%s", str);
            int len = strlen(str);
            if (str[0] == 'x')
                graph[i][j] = graph[j][i] = E_INF;
            else if (len == 3)
                graph[i][j] = graph[j][i] = 100;
            else if (len == 2)
                graph[i][j] = graph[j][i] = (str[0]-'0') * 10 + str[1] - '0';
            else
                graph[i][j] = graph[j][i] = str[0] - '0';
        }
        dist[i] = graph[1][i];
    }

    while (1)
    {
        int j = 1;
        while (v[++j])
            ;
        if (j > n)
            break;
        min = j;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == 0)
            {
                if (dist[k] + graph[k][i] < dist[i])
                    dist[i] = dist[k] + graph[k][i];
                if (dist[i] < dist[min])
                        min = i;
            }
        }
        v[min] = 1;
        k = min;
    }
    printf("%d\n", dist[min]);
    return 0;
}
