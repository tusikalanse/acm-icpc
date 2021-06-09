#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int mod = 1e9 + 7, inv2 = (mod + 1) / 2;

LL n, m, ans;

LL calc(LL a, LL b, LL c, LL n) {
	if(!a) return 0;
	if(a >= c || b >= c) {
		LL tmp = calc(a % c, b % c, c, n);
		return (tmp + ((n % mod) * ((n + 1) % mod) % mod * inv2 % mod) * ((a / c) % mod) % mod + ((n + 1) % mod) * ((b / c) % mod) % mod) % mod;
	}
	LL f = ((__int128)a * n + b) / c;
	return (((n % mod) * (f % mod) % mod - calc(c, c - b - 1, a, f - 1)) % mod + mod) % mod;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < 40; ++i) if(m >> i & 1) {
		LL res = ((calc(m, 0, 1LL << i, n) - 2 * calc(m, 0, 2LL << i, n)) % mod + mod) % mod;
		ans = (ans + (1LL << i) % mod * res % mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}