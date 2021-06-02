// 2485 小b重排字符串
// 小b有一个字符串S，现在她希望重排列S，使得S中相邻字符不同。
// 请你判断小b是否可能成功。
// 样例解释：将"aab"重排为"aba"即可。
// 输入
// 输入一个只包含小写字母的字符串S，其长度n满足1≤n≤500
// 输出
// 如果可能，输出"Possible"；
// 否则，输出"Impossible"。
// 输入样例
// aab
// 输出样例
// Possible

#include <stdio.h>
#include <string.h>

int a[26];
char s[501];

int main(int argc, char const *argv[])
{
    int i;
    memset(a, 0, sizeof(a));
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        a[s[i]-'a']++;
    len += (len&1)+1;
    len /= 2;
    for (i = 0; i < 26; i++)
    {
        if( a[i] > len)
            break;
    }
    if (i == 26)
        printf("Possible\n");
    else
        printf("Impossible\n");
    return 0;
}
