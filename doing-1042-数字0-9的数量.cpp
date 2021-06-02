// 1042 数字0-9的数量
// 给出一段区间a-b，统计这个区间内0-9出现的次数。
// 比如 10-19，1出现11次（10,11,12,13,14,15,16,17,18,19,其中11包括2个1)，其余数字各出现1次。
// 输入
// 两个数a,b（1 <= a <= b <= 10^18)
// 输出
// 输出共10行，分别是0-9出现的次数
// 输入样例
// 10 19
// 输出样例
// 1
// 11
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long ll;

char a[22], b[22];
int cntStart[10] = {0}, cntEnd[10]={0};

int setBscCnt(int cnt[10], int num, int expo)
{
    int res = 0;
    while(--expo)
        res += int(pow(10, expo));
    for (int i = 0; i < 10; i++)
        cnt[i] += res;
    for (int i = 1; i <= num; i++)
        cnt[i]++;
}

int setCnt(int cnt[10], char end[22], int len)
{
    for (int i = 0; i < len; i++)
         setBscCnt(cnt, end[i]-'0', len-i);
}

void subOne(char s[22], int len)
{
    if (s[len-1]-'0')
        s[len-1]--;
    else
    {
        int j = len - 1;
        while(!(s[j]-'0'))
            s[j--] = '9';
        if (--s[j] == '0')
        {
            for(int i = 0; i < len - 1; i++)
                s[i] = s[i+1];
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%s%s", &a, &b);
    subOne(a, strlen(a));
    setCnt(cntStart, a, strlen(a));
    setCnt(cntEnd, b, strlen(b));
    for (int i = 0; i < 10; i++)
        printf("%d\n", cntEnd[i]-cntStart[i]);
    return 0;
}
