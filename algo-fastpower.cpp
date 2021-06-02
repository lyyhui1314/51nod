#include <stdio.h>

// m: 底数, n: 指数, mod: 模
int m = 9, n = 10, mod = int(1e9+7);

int powerFastly(int base, int power, int mod)
{
    long long res = 1;
    while(power)
    {
        if (power & 1)
            res = (res % mod) * (base % mod) % mod;
        base = (base % mod) * (base % mod) % mod;
        power /= 2;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int res;
    res = powerFastly(m, n, mod);
    printf("%d\n", res);
    return 0;
}
