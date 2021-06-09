#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10, mod = 1e9 + 7;

LL a[N], ans;
int n, p[N], ok[N];

struct Base {
    LL a[63];
    int m;
    Base() {
        memset(a, 0, sizeof(a));
        m = 0;
    }
    bool insert(LL x) {
        for(int i = 62; ~i; --i) {
            if((x >> i) & 1) {
                if(a[i] == 0) {
                    a[i] = x;
                    m++;
                    return 1;
                }
                else {
                    x ^= a[i];
                }
            }
        }
        return 0;
    }
}suf[N];

int main() {
    p[0] = 1;
    for(int i = 1; i < N; ++i)
        p[i] = 2LL * p[i - 1] % mod;
    while(~scanf("%d", &n)) {
        ans = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
        }
        Base s, s2;
        suf[n + 1] = s;
        for(int i = n; ~i; --i) {
            suf[i] = suf[i + 1];
            suf[i].insert(a[i]);
        }
        for(int i = 1; i <= n; ++i) ok[i] = s.insert(a[i]);
        for(int i = 1; i <= n; ++i) {
            if(!ok[i]) ans = (ans + p[n - 1 - s.m]) % mod;
            else {
                Base t = s2;
                for(int j = 0; j < 63; ++j)
                    t.insert(suf[i + 1].a[j]);
                if(!t.insert(a[i])) ans = (ans + p[n - 1 - t.m]) % mod;
            }
            s2.insert(a[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}