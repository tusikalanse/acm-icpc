#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int mod = 998244353;
const int N = 200010;

int fac[N], inv[N], facinv[N], T, n, m, k;

void init() {
	fac[0] = fac[1] = inv[0] = inv[1] = facinv[0] = facinv[1] = 1;
	for(int i = 2; i < N; ++i) {
		fac[i] = 1LL * fac[i - 1] * i % mod;
		inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
		facinv[i] = 1LL * facinv[i - 1] * inv[i] % mod;
	}
}

LL C(LL n, LL m) {
	if(n < 0 || m < 0 || m > n)
		return 0;
	return 1LL * fac[n] * facinv[m] % mod * facinv[n - m] % mod;
}

int main() {
	init();
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &k);
		LL ans = 0;
		for(int c = 0; c * n <= k; ++c) {
			if(c & 1) 
				ans = (ans - 1LL * C(m, c) * C(k - c * n + m - 1, m - 1)) % mod;
			else
				ans = (ans + 1LL * C(m, c) * C(k - c * n + m - 1, m - 1)) % mod;
		}
		ans = (ans + mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}

