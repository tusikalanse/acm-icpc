#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10, mod = 1e9 + 7;

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


int n, fac[N], invfac[N], ans = 1;
long long a[N];
LL A(int n, int m) {
	return 1LL * fac[n] * invfac[n - m] % mod;
}

int main() {
	fac[0] = invfac[0] = 1;
	for(int i = 1; i < N; ++i)
		fac[i] = 1LL *fac[i - 1] * i % mod;
	invfac[N - 1] = qp(fac[N - 1], mod - 2);
	for(int i = N - 2; i; --i)
		invfac[i] = 1LL *(i + 1) * invfac[i + 1] % mod;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	long long tmp = a[1];
	int now = 1;
	for(int i = 2; i <= n; ++i) {
		if(a[i] == tmp) {
			now++;
			continue;
		}
		if(tmp + now <= a[i]) {
			ans = (ans * A(now, now)) % mod;
			tmp = a[i];
			now = 1;
		}
		else {
			ans = (ans * A(now, a[i] - tmp)) % mod;
			now = 1 + now - a[i] + tmp;
			tmp = a[i];
		}
		// cout << ans << endl;
	}
	ans =  (ans * A(now, now)) % mod;
	printf("%d\n", ans);
	return 0;
}