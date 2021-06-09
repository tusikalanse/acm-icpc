#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int mod = 998244353;

typedef long long LL;

LL f[N], ans[N], g[N];
int n;

void init() {
    for(int i = 0; i < 1000; ++i) {
        g[i << 1] = 1LL * i * (i * 3 - 1) / 2;
        g[i << 1 | 1] = 1LL * i * (i * 3 + 1) / 2;
    }
    f[0] = 1, f[1] = 1, f[2] = 2;
    for(int i = 3; i < N; ++i) {
        f[i] = 0;
        int k = 0;
        for(int j = 2; g[j] <= i; ++j) {
            if(k & 2) 
                f[i] = ((f[i] - f[i - g[j]]) % mod + mod) % mod;
            else
                f[i] = ((f[i] + f[i - g[j]]) % mod + mod) % mod;
            k++; k %= 8;
        }
    }
    ans[1] = ans[2] = 0;
    for(int i = 3; i < N; ++i)
        ans[i] = ((f[i] + f[i - 3] - f[i - 1] - f[i - 2]) % mod + mod) % mod;
}

int main() {
    init();
    while(~scanf("%d", &n))
        printf("%lld\n", ans[n]);
    return 0;
}
