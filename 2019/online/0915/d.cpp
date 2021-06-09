#include <bits/stdc++.h>
#define LL long long
#define MAXN 10000
using namespace std;
const int mod = 1000000007;
int n, tot;
LL ans = 0;
map<int,int> mp;
LL inv[3008], fac[3008], invfac[3008];
LL init()
{
    fac[0] = invfac[0] = inv[1] = fac[1] = invfac[1] = 1;
    for (int i = 2; i <= 3000; ++i)
    {
        inv[i] = (LL) (mod - mod / i) * inv[mod%i] % mod;
        fac[i] = fac[i - 1] * i % mod;
        invfac[i] = invfac[i - 1] * inv[i] % mod;
    }
}
LL C(LL n, LL m)
{
    return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}
void dfs(int v, int s, int p, int cnt)
{
    if (cnt == tot && s == p)
    {
        int r = n;
        LL t = fac[n];
        for (auto pr: mp)
        {
            if (pr.second)
            {
                t = t * invfac[pr.second] % mod;
            }
        }
        t = t * invfac[n - tot] % mod;
        ans = (ans + t) % mod;
        return;
    }
    if(cnt == tot) return;
    int cp = p, cs = s;
    for (int c = v; ; ++c)
    {
        if (p * pow(c, tot - cnt) > s + c * (tot - cnt))
            break;
        mp[c]++;
        dfs(c, s + c, p * c, cnt + 1);
        mp[c]--;
    }
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%d", &n);
        for(tot = min(12, n); tot >= 2; --tot) {
            mp.clear();
            dfs(2, n - tot, 1, 0);
        }
        printf("%lld\n", ans);
    }
	return 0;
}