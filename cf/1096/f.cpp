#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int mod = 998244353;

LL qp(LL a, LL n) {
	LL ret = 1;
	while(n) {
		if(n & 1) {
			ret = ret * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}
const int inv2 = qp(2, mod - 2);
LL ans;
const int N = e5 + 10;

LL a[N], s[N], t[N], c[N], tmp, n, tot;

int main() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		s[i] = t[i] = 1;
	}
	tot = n;
	for(int i = n; i; --i) {
		if(a[i] != -1) {
			for(tmp = a[i] - 1; tmp; tmp -= (tmp & -tmp)) {
				ans = (ans + c[tmp]) % mod;
			}
			for(tmp = a[i]; tmp <= n; tmp += (tmp & -tmp)) {
				c[tmp]++;
			}
			tot--;
			s[i] = t[a[i]] = 0;
		}
	}
	const LL inv = qp(tot, mod - 2);
	for(int i = 1; i <= n; ++i) {
		s[i] += s[i - 1];
		t[i] += t[i - 1];
	}
	ans = (ans + (tot * (tot - 1) / 2) % mod * inv2 % mod) % mod;
	for(int i = 1; i <= n; ++i) {
		if(a[i] != -1) {
			ans = (ans + (s[i] * (tot - t[a[i]]) % mod + (tot - s[i]) * t[a[i]] % mod) * inv % mod) % mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}