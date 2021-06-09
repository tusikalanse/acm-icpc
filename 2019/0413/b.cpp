#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using LL = long long;
int n, m, c;
LL ans, tmp;

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

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
	scanf("%d%d%d", &n, &m, &c);
	LL tmp = qp(c, n * n);
	for(int i = 0; i < m; ++i) {
		ans = (ans + qp(tmp, gcd(i, m))) % mod;
	}
	ans = ans * qp(m, mod - 2) % mod;
	printf("%lld\n", ans);
	return 0;
}