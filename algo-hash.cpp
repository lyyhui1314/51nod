#include <stdio.h>
#include <string.h>

#define MAX_LEN 1001
#define MAX_HASH 10000001
#define SEED 97

typedef unsigned long long ull;

typedef struct {
    char data[MAX_LEN];
    int lenth;
    ull hash[MAX_HASH];
} Str;

Str s;

void hashBKDR()
{
    s.hash[0] = s.data[0] - 31;
    for (int i = 1; i < s.lenth; i++)
    {
        s.hash[i] = s.hash[i - 1] * SEED + (s.data[i] - 31);
    }
}

ull getHash(int index, int offset)
{
    if (index+offset >= s.lenth)
        return -1;
    if (index == 0)
        return s.hash[offset];
    ull impact_factor = 1;
    for (int i = 0; i < offset; i++)
        impact_factor *= SEED;
    return s.hash[index + offset] - s.hash[index - 1] * impact_factor;
}

void init(char* str, int len)
{
    strcpy(s.data, str);
    s.lenth = len;
    hashBKDR();
}

int main()
{
    char str[] = "I am a string.";
    int index = 1, offset = 0;
    int len = strlen(str);
    init(str, len);
    ull v = getHash(index, offset);
    printf("hash: %I64u, hash_%d_%d: %I64u\n", s.hash[len - 1], index, index + offset, v);
    return 0;
}
