#include <bits/stdc++.h>
#define LL long long
#define MAXN 200000
using namespace std;
int T;
LL n, mod, rot;
LL prime[MAXN + 4], a[MAXN + 4], b[MAXN + 4];
bool notprime[MAXN + 4];
int ind = 0;
void getprime() {
    notprime[1] = true;
    for (int i = 2; i <= MAXN; ++i) {
        if (!notprime[i]) {
            prime[++ind] = i;
        }
        for (int j = 1; j <= ind && i * prime[j] <= MAXN; ++j) {
            notprime[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
inline LL& mp(LL x) {
    return x>=rot?a[n/x]:b[x];
}


int main() {
    getprime();
    scanf("%d", &T);
    vector<LL> vec;
    vec.reserve(1000000);
    while (T--) {
        vec.clear();
        scanf("%lld %lld", &n, &mod);
        n++;
        rot = (LL)sqrt(n + 0.5);
        for (int i = 1; i <= rot; ++i) {
            LL x = n / i;
            vec.push_back(x);
            if (x % 2 == 0) {
                mp(x) = (x / 2 % mod * ((x + 1) % mod) + mod - 1) % mod;
            } else {
                mp(x) = ((x + 1) / 2 % mod * (x % mod) + mod - 1) % mod;
            }
            
        }
        for (LL j = n / rot; j > 0; --j) {
            vec.push_back(j);
            mp(j) = (j * (j + 1) / 2 - 1) % mod;
        }
        for (int id = 1; id <= ind && prime[id] <= rot; ++id) {
            LL p = prime[id];
            for (LL x : vec) {
                if (p * p > x)
                    break;
                mp(x) = mp(x) - p * (mp(x / p) - mp(prime[id - 1]) + mod) % mod;
            }
        }
        LL ans = 0;
        if (n % 2 == 0) {
            ans = n / 2 % mod * ((n + 1) % mod) % mod;
        } else {
            ans = (n + 1) / 2 % mod * (n % mod) % mod;
        }
        printf("%lld\n", ((mp(n) + ans - 5 + mod) % mod + mod) % mod);
    }
    return 0;
}