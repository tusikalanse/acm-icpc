#include <bits/stdc++.h>
#define LL long long
#define MAXN 10000
using namespace std;
const int mod = 998244353;
LL n;
int T;
int prime[MAXN + 8];
bool notprime[MAXN + 8];
int ind = 0;
void getprime()
{
    notprime[1] = true;
    for (int i = 2; i <= MAXN; ++i)
    {
        if (!notprime[i])
            prime[++ind] = i;
        for (int j = 1; j <= ind && i * prime[j] <= MAXN; ++j)
        {
            notprime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

bool check(LL q, LL a)
{
    for (LL x = max(1LL, q - 2); x <= q + 3; ++x)
    {
        LL t = 1;
        for (int i = 1; i <= a; ++i)
            t *= x;
        if (t == n)
            return true;
    }
    return false;
}

int main()
{
    getprime();
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &n);
        int ans = 72;
        for (int i = 1; i <= ind; ++i)
        {
            int p = prime[i];
            if (n % p == 0)
            {
                int c = 0;
                while (n % p == 0)
                {
                    n /= p;
                    c++;
                }
                ans = min(ans, c);
            }
        }
        if (n == 1)
        {
            printf("%d\n", ans);
            continue;
        }
        LL q4 = floor(pow(n, 1.0 / 4));
        if (check(q4, 4))
        {
            ans = min(ans, 4);
        }
        else
        {
            LL q3 = floor(pow(n, 1.0 / 3));
            if (check(q3, 3))
            {
                ans = min(ans, 3);
            }
            else
            {
                LL q2 = floor(pow(n, 1.0 / 2));
                if (check(q2, 2))
                {
                    ans = min(ans, 2);
                }
                else
                {
                    ans = min(ans, 1);
                }
            }
        }
        printf("%d\n", ans);
    }
}