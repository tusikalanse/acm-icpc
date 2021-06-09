#include <bits/stdc++.h>
using namespace std;

const int N = 5010, mod = 998244353;

int fac[N], invfac[N], ans[3], a, b, c;

int qp(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) {
			res = 1LL * res * a % mod;
		}
		a = 1LL * a * a % mod;
		n >>= 1;
	}
	return res;
}

void init() {
	fac[0] = 1;
	for(int i = 1; i < N; ++i) 
		fac[i] = 1LL * fac[i - 1] * i % mod;
	invfac[N - 1] = qp(fac[N - 1], mod - 2);
	for(int i = N - 2; ~i; --i) {
		invfac[i] = 1LL * invfac[i + 1] * (i + 1) % mod;
	}
}

int C(int n, int m) {
	return 1LL * fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

int main() {
	init();
	scanf("%d%d%d", &a, &b, &c);
	for(int i = 0; i <= a && i <= b; ++i) {
		ans[0] = (ans[0] + 1LL * C(a, i) * C(b, i) % mod * fac[i] % mod) % mod;
	}
	for(int i = 0; i <= a && i <= c; ++i) {
		ans[1] = (ans[1] + 1LL * C(a, i) * C(c, i) % mod * fac[i] % mod) % mod;
	}
	for(int i = 0; i <= b && i <= c; ++i) {
		ans[2] = (ans[2] + 1LL * C(b, i) * C(c, i) % mod * fac[i] % mod) % mod;
	}
	printf("%lld\n", 1LL * ans[0] * ans[1] % mod * ans[2] % mod);
	return 0;
}