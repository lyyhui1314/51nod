// 2486 小b和矩阵
// 2.0 秒 262,144.0 KB 5 分 1级题
// 小b有一个m行n列的矩阵。

// 她会从(1,1)开始，顺时针螺旋访问该矩阵，每个元素恰好被访问一次。

// 请你按小b的访问顺序输出每个元素。

// 输入
// 第一行输入两个数m和n，其中0＜m,n≤500；
// 之后m行，每行n个数以空格隔开，表示这个矩阵。
// 输出
// 输出一行共m*n个数，表示螺旋输出的结果
// 输入样例
// 3 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 输出样例
// 1 2 3 4 8 12 11 10 9 5 6 7

#include <stdio.h>

int a[501][501];

int main(int argc, char const *argv[])
{
    int row, col;
    scanf("%d%d", &row, &col);
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            scanf("%d", &a[i][j]);
    
    int top_row = 1, bot_row = row, left_col = 1, right_col = col, sum = 0, cnt = row * col;
    while (1)
    {
        for (int i = left_col; i <= right_col; i++)
            printf("%d ", a[top_row][i]);
        sum += right_col - left_col + 1;
        if (sum == cnt)
            break;
        top_row++;
        for (int i = top_row; i <= bot_row; i++)
            printf("%d ", a[i][right_col]);
        sum += bot_row - top_row + 1;
        if (sum == cnt)
            break;
        right_col--;
        for (int i = right_col; i >= left_col; i--)
            printf("%d ", a[bot_row][i]);
        sum += right_col - left_col + 1;
        if (sum == cnt)
            break;
        bot_row--;
        for (int i = bot_row; i >= top_row; i--)
            printf("%d ", a[i][left_col]);
        sum += bot_row - top_row + 1;
        if (sum == cnt)
            break;
        left_col++;
    }
    return 0;
}
