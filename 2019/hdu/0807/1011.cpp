#include <bits/stdc++.h>
#define MAXN 1000000
#define LL long long
using namespace std;
const LL e18 = 1000000000000000001LL;
const int mod = 1000000007;
char str[50004];
LL dp[50004][22];
int n, m, Q;
vector<pair<LL, int>> query;
LL ans[100004];
int pow10_m[50004];
LL pow10_mod[50004];
void init()
{
    query.clear();
    for (int i = 0; i <= n + 1; ++i)
        memset(dp[i], 0, sizeof(dp[i]));
    dp[n][0] = 1;
    pow10_m[0] = 1;
    for (int i = 1; i <= n + 1; ++i)
    {
        pow10_m[i] = pow10_m[i - 1] * 10 % m;
    }
    for (int i = 1; i <= Q; ++i)
        ans[i] = -1;
}

void dfs(int curi, int l, int r, LL cans, int modm, LL curk)
{
    if (l > r)
        return;
    if (curi == n)
    {
        if (modm == 0)
        {
            for (int i = l; i <= r; ++i)
            {
                if(curk + 1 == query[i].first)
                    ans[query[i].second] = cans;
            }
        }
        return;
    }
    if (str[curi] != '?')
    {
        dfs(curi + 1, l, r,
            (cans + pow10_mod[n - curi - 1] * (str[curi] - '0')) % mod,
            (modm + pow10_m[n - curi - 1] * (str[curi] - '0')) % m,
            curk);
        return;
    }
    else
    {
        LL tot = curk, tt = curk;
        int ll = l, rr;
        for (int c = 0; c <= 9; ++c)
        {
            tot += dp[curi + 1][(m - ((modm + c * pow10_m[n - curi - 1]) % m)) % m];
            tot = min(e18, tot);
            LL curremain = (cans + pow10_mod[n - curi - 1] * c) % mod;
            rr = upper_bound(&query[l], &query[r + 1], pair<LL,int>(tot, 0x3f3f3f3f)) - (&query[0]);
            dfs(curi + 1, ll, rr - 1, curremain, (modm + c * pow10_m[n - curi - 1]) % m, tt);
            ll = rr;
            if(ll > r) break;
            tt = tot;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    pow10_mod[0] = 1;
    for (int i = 1; i <= 50001; ++i)
    {
        pow10_mod[i] = pow10_mod[i - 1] * 10 % mod;
    }
    while (T--)
    {
        scanf("%d %d %d %s", &n, &m, &Q, str);
        init();
        for (int i = n - 1; i >= 0; --i)
        {
            if (str[i] != '?')
            {
                for (int r = 0; r < m; ++r)
                {
                    dp[i][(r + (str[i] - '0') * pow10_m[n - i - 1] % m) % m] =
                    min(dp[i][(r + (str[i] - '0') * pow10_m[n - i - 1]) % m] + dp[i + 1][r], e18);
                }
            }
            else
            {
                for (int r = 0; r < m; ++r)
                {
                    for (int c = 0; c <= 9; ++c)
                    {
                        dp[i][(r + c * pow10_m[n - i - 1]) % m] =
                        min(dp[i][(r + c * pow10_m[n - i - 1]) % m] + dp[i + 1][r], e18);
                    }
                }
            }
        }
        for (int id = 1; id <= Q; ++id)
        {
            LL x;
            scanf("%lld", &x);
            query.push_back(pair<LL,int>(x, id));
        }
        sort(query.begin(), query.end());
        dfs(0, 0, Q - 1, 0, 0, 0);
        for (int i = 1; i <= Q; ++i)
            printf("%lld\n", ans[i]);
    }
    return 0;
}