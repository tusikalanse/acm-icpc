#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e3 + 10, mod = 1e9 + 7;

int a[N], n;
LL ans;

LL qp(LL a, LL n) {
	LL res = 1;
	while(n) {
		if(n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}


int main() {
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; ++i) 
			scanf("%d", &a[i]);
		ans = 0;
		for(int i = 1; i <= n; ++i) {
			LL q = qp(2 * a[i] % mod, mod - 2), p = 1;
			for(int j = 1; j <= n; ++j) {
				if(i == j) continue;
				p = (((1LL * a[j] * a[j] % mod - 1LL * a[i] * a[i] % mod) % mod) + mod) % mod * p % mod;
			}
			ans = (ans + qp(p, mod - 2) * q % mod) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}