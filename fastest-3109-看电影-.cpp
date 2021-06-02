// 3109 看电影
// 这个世界上有很多叫小明的人，他们在不同的国家，不同国家有不同的语言。每一种语言有一个语言编号。
// 每个国家的人除了可以懂自己国家的语言，也能懂编号相邻国家的语言，例如：语言编号为：1, 7, 10, 5，其中：
// 语言编号为 1 的，可以懂编号为 1, 5 的语言
// 语言编号为 5 的懂编号为 1, 5, 7 的语言
// 语言编号为 7 的懂编号为 5, 7, 10 的语言
// 语言编号为 10 的懂编号为 7, 10 的语言
// 有一天世界上的小明突然想要聚集在一起看电影，现在有m部电影，每部电影的声音是编号 a[i] 的语言,字幕是编号 b[i] 的语言.
// 如果小明可以听懂电影声音的话他会非常满意，如果小明可以看懂字幕的话他会比较满意，否则它很不满意。
// 现在问看哪部电影会使得n个小明满意最高，输出这部电影非常满意人数和较满意人数
// （如果两部电影使得n个小明非常满意的人数相同时，选比较满意的最多的那部电影）。
// 输入
// 第一行：包含3个正整数 l,m,n (1≤l,m,n≤200000)。l为语言的数量，m为小明的数量，n为电影的数量
// 第二行：包含 l 个正整数 li(1≤li≤10^9)，对应所有语言的编号。
// 第三行：包含 m 个正整数 mi (1≤m≤10^9)，对应m个小明所在国家的语言。
// 后面n行：每行2个正整数ai, bi (1≤ai,bi≤10^9)，其中ai为第i部电影的音频语言索引，bi为第i部电影字幕语言的索引。
// 可以保证每个电影的音频语言和字幕语言是不同的，即ai≠bi。
// 输出
// 打印两个整数—表示满足条件的电影的非常满意人数以及较满意人数。
// 数据范围
// 对于10%的数据，1<= n <= 8
// 对于50%的数据，1 <= n<= 1024
// 对于100%的数据，1 <= n <= 200000
// 1 <= m <= 200000，1≤li≤10^9，1≤ai≤10^9，1≤m≤200000, 1≤bj≤10^9,1≤cj≤10^9。
// 输入样例
// 3 3 2
// 1 3 2
// 1 3 1
// 3 1
// 1 3
// 输出样例
// 2 1

#include <stdio.h>
#include <algorithm>

#define MAXN 200001

using namespace std;

int res[MAXN];
int l, m, n, li[MAXN];

int getPos(int index)
{
    return lower_bound(li, li+l, index) - li;
}

int main(int argc, char const *argv[])
{
    int pre, cur, tmp, pos1, pos2, cnt1 = 0, cnt2 = 0, voice, subtitle;
    scanf("%d%d%d", &l, &m, &n);
    for (int i = 0; i < l; i++)
        scanf("%d", &li[i]);
    sort(li, li+l);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        if (tmp)
            res[getPos(tmp)]++;
    }
    pre = res[0];
    res[0] += res[1];
    for (int i = 1; i < l; i++)
    {
        cur = res[i];
        res[i] += pre + res[i+1];
        pre = cur;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &voice, &subtitle);
        pos1 = getPos(voice);
        pos2 = getPos(subtitle);
        if (res[pos1] > cnt1)
        {
            cnt1 = res[pos1];
            cnt2 = res[pos2];
        }
        else if (res[pos1] == cnt1 && res[pos2] > cnt2)
            cnt2 = res[pos2];
    }
    printf("%d %d\n", cnt1, cnt2);
    return 0;
}