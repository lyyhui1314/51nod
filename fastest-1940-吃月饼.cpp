// 1940 吃月饼
// 有一块月饼，是正三角形的，又被分割成了许多块小正三角形的月饼，里面有若干块被吃掉了。
// 现在想要在这块月饼中再找一个由小正三角形月饼的正三角形月饼，而且要求面积最大的。
// #-##----#
//  -----#-
//   ---#-
//    -#-
//     -
// 大月饼的分解情况如图，#表示已被吃掉的月饼，-表示未被吃的。最大的是由9个小月饼组成的（黑色粗线标记）。
// 输入
// 单组测试数据。
// 第一行给出一个整数n (1 <= n <= 100)，表示三角形月饼的高度。
// 接下来n行，用#, -表示该行三角形月饼的状态，#表示已经被吃掉的，－表示未被吃掉的。
// 从第一行到最后一行每行的字符的数目总是奇数个，并且是从2*n-1到1递减的。
// 输出
// 输出一个整数，表示找到的最大的月饼中包含的小三角形个数。
// 输入样例
// 样例输入1
// 5
// #-##----#
// -----#-
// ---#-
// -#-
// -
// 输出样例
// 样例输出1
// 9

#include <stdio.h>

int n, max = 0, res[233][233];

void find(int row, int col)
{
    int i, j, k = 1, rowOffset, colOffset;
    if (col & 1)
    {
        rowOffset = -1, colOffset = 1;
        if (row * row <= max)
            return;
    }
    else
    {
        rowOffset = 1, colOffset = -1;
        if ((n - row + 1) * (n - row + 1) <= max)
            return;
    }
    for (i = row; res[i][col]; i += rowOffset)
    {
        for (j = 0; j > -k && j < k; j += colOffset)
        {
            if (!res[i][j + col])
                break;
        }
        if (j > -k && j < k)
            break;
        k += 2;
    }
    if ((row - i) * (row - i) > max)
        max = (row - i) * (row - i);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    char s[233];
    int m = 2 * n + 1;
    for (int i = 1; i <= n; i++)
    {
        m -= 2;
        scanf("%s", s);
        for (int j = 1; j <= m; j++)
        {
            if (s[j-1] == '-')
                res[i][j] = 1;
        }
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= m; j++)
            find(i, j);
        m += 2;
    }

    printf("%d\n", max);
    return 0;
}
