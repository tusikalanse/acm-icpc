#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL mod = 998244353;
LL n;

LL fac[1000008];

LL qp(LL a, LL b)
{
    LL ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

LL inv(LL a)
{
    return qp(a, mod - 2);
}

void init()
{
    fac[1] = 1;
    for (int i = 2; i <= 1000000; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
}

LL getc(LL n, LL m)
{
    if (n == 0)
        return 1;
    if (m == 0)
        return 1;
    if (n == m)
        return 1;
    LL ret = fac[n];
    ret = ret * inv(fac[m]) % mod;
    ret = ret * inv(fac[n - m]) % mod;
    //printf("C(%I64d,%I64d) = %I64d\n", n, m, ret);
    return ret;
}
int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    LL ans = 0;
    init();
    for (int i = 1; i <= n; ++i)  /*??*/
    {
        if (i <= (2 * n - 1) / 3)
        {
            ans += 2 * getc(n - i - 1, (i + 1) / 2 - 1) % mod * getc(n - i - 1, i + 1 - (i + 1) / 2 - 1) % mod;
            ans %= mod;
            //printf("AC(%I64d, %d), C(%I64d, %d), i = %d  ans = %I64d\n", n - i - 1, (i + 1) / 2 - 1, n - i - 1, i + 1 - (i + 1) / 2 - 1, i, ans);
        }
        if (i >= 2 && i <= 2 * n / 3)
        {
            ans += 4 * getc(n - i - 1, i / 2 - 1) % mod * getc(n - i - 1, i - i / 2 - 1) % mod;
            ans %= mod;
            //printf("BC(%I64d, %d), C(%I64d, %d), i = %d  ans = %I64d\n",n - i - 1, i / 2 - 1, n - i - 1, i - i / 2 - 1, i, ans);
        }
        if (i >= 3 && i <= (2 * n + 1) / 3)
        {
            ans += 2 * getc(n - i - 1, (i - 1) / 2 - 1) % mod * getc(n - i - 1, i - 1 - (i - 1) / 2 - 1) % mod;
            ans %= mod;
            //printf("CC(%I64d, %d), C(%I64d, %d), i = %d  ans = %I64d\n",n - i - 1, (i - 1) / 2 - 1, n - i - 1, i - 1 - (i - 1) / 2 - 1, i, ans);
        }
    }
    cout << ans << endl;
}