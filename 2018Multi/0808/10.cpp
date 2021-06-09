#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MAXN = 16e5 + 10;
const int mod = 1e9 + 7;

int prime[MAXN], cnt, T, c, n, k, p;
int nop[MAXN], fac[MAXN], inv[MAXN], facinv[MAXN];
LL ans;

LL qp(LL a, LL n) {
	LL ans = 1;
	while(n) {
		if(n & 1) 
			ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}

void init() {
	for(int i = 2; i < MAXN; ++i) {
		if(!nop[i]) prime[cnt++] = i;
		for(int j = 0; 1LL * i * prime[j] < MAXN; ++j) {
			nop[i * prime[j]] = 1;
			if(i % prime[j] == 0)
				break;
		}
	}
	facinv[1] = inv[1] = fac[0] = fac[1] = 1;
	for(int i = 2; i < MAXN; ++i) {
		fac[i] = 1LL * i * fac[i - 1] % mod;
		inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
		facinv[i] = 1LL * inv[i] * facinv[i - 1] % mod;
	}	
}

LL comb(LL n, LL m) {
	return 1LL * fac[n] * facinv[m] % mod * facinv[n - m] % mod;
}

int main() {
	init();
	//freopen("data.in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &c, &n, &k);
		p = prime[c - 1];
		ans = 0;
		for(int j = 1; j <= k; ++j) {
			LL q = comb(p + j, p - 1);
			if(q == 1) {
				ans = (ans + n) % mod;
				continue;
			}
			ans = (ans + 1LL * q * (qp(q, n) - 1) % mod * qp(q - 1, mod - 2) % mod) % mod;
		}
		ans = (ans + mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}