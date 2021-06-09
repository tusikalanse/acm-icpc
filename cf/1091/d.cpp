#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 1e6 + 10;
int fac[N], invfac[N], n;

long long qp(long long a, long long n) {
	long long res = 1;
	while(n) {
		if(n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

void pre() {
	fac[1] = 1;
	for(int i = 2; i < N; ++i)
		fac[i] = 1LL * fac[i - 1] * i % mod;
	invfac[N - 1] = qp(fac[N - 1], mod - 2);
	for(int i = N - 2; ~i; --i)
		invfac[i] = invfac[i + 1] * 1LL * (i + 1) % mod;
}

int main() {
	cin >> n;
	pre();
	long long ans = fac[n];
	for(int k = 1; k < n; ++k) 
		ans = (ans + 1LL * fac[n] * invfac[n - k] % mod * (fac[n - k] + mod - 1)) % mod;
	cout << ans << endl;
	return 0;
}