#include <bits/stdc++.h>
using namespace std;
using LL = long long;
 
const int maxn = (1 << 20) + 2;
const LL mmax = 1e18;
 
int cnt[maxn];
int a[25];
LL l, r, k;
 
LL check(int p) {
    LL ans = 1;
    for(int i = 0; i < k; ++i) {
        if((1 << i) & p) {
            if(ans > mmax / a[i])
                return 0;
            ans *= a[i];
        }
    }
    return ans;
}
 
 
int main() {
    LL ans = 0;
    scanf("%lld %lld %lld", &l, &r, &k);
    cnt[0] = 0;
    cnt[1] = 1;
    for(int i = 1; (i << 1) < maxn; ++i) {
        cnt[i << 1] = cnt[i];
        cnt[i << 1 | 1] = cnt[i] + 1;
    }
    for(int i = 0; i < k; ++i)
        scanf("%d", &a[i]);
    for(int p = 1; p < (1 << k); ++p) {
        LL t = check(p);
        if(t) {
            if(cnt[p] % 2 == 1)
                ans += ((r) / t - (l - 1) / t);
            else
                ans -= ((r) / t - (l - 1) / t);
        }
    }
    ans = r - l + 1 - ans;
    printf("%lld\n", ans);
    return 0;
}