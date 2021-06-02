// 2067 n 皇后问题
// 在 n*n 格（n<=8）的国际象棋棋盘上摆放 n 个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法。

// 输入
// 一行一个正整数，表示 n
// 输出
// 输出一个正整数，表示八皇后摆放的个数
// 输入样例
// 8
// 输出样例
// 92

#include <stdio.h>

int n, sum = 0;
int board[10];

int check(int row, int col)
{
    if (row == 0)
        return 1;
    for (int i = 1; i <= row; i++)
    {
        if ((col >= i && board[row - i] == col - i) || board[row - i] == col || (col + i < n && board[row - i] == col + i))
            return 0;
    }
    return 1;
}

void queen()
{
    int i = 0;
    while (i>=0)
    {
        if (i == n)
        {
            sum++;
            board[--i]++;
        }
        else if (board[i] == n)
        {
            board[i] = 0;
            board[--i]++;
        }
        else if (check(i, board[i]))
            i++;
        else
            board[i]++;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    queen();
    printf("%d\n", sum);
    return 0;
}
