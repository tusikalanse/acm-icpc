#include <bits/stdc++.h>
#define LL long long
using namespace std;

__int128_t mod;
LL MOD;

__int128_t qp(__int128_t a, __int128_t b)
{
    __int128_t ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

__int128_t inv(__int128_t a)
{
    return qp(a, mod - 2);
}

bool isprime(LL x)
{
    if (x == 1)
        return false;
    for (LL i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &MOD);
        mod = MOD;
        LL q;
        for (q = mod - 1; q >= 0; --q)
        {
            if (isprime(q))
                break;
        }
        __int128_t ans = mod - 1;
        for (LL x = q + 1; x <= mod - 1; ++x)
        {
            ans = ans * inv(x) % mod;
        }
        printf("%lld\n", (long long)ans);
    }
}