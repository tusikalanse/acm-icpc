#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

long long qp(long long a, long long n, int m = mod) {
	long long res = 1;
	while(n) {
		if(n & 1)
			res = res * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return res;
}

long long fac[N], inv[N], res[55][55], num, dp[N];
int cnt[55], q, x, y, n;
char s[N];

int mp(int x) {
	if('a' <= x && x <= 'z')
		return x - 'a';
	else 
		return x - 'A' + 26;
}

void init() {
	fac[1] = 1;
	for(int i = 2; i < N; ++i) 
		fac[i] = fac[i - 1] * i % mod;
	inv[N - 1] =  qp(fac[N - 1], mod - 2, mod);
	for(int i = N - 2; ~i; --i)
		inv[i] = inv[i + 1] * (i + 1) % mod;
}

int main() {
	init();
	scanf("%s%d", s, &q);
	n = strlen(s);
	for(int i = 0; i < n; ++i) {
		cnt[mp(s[i])]++;
	}
	num = fac[n / 2] * fac[n / 2] % mod;
	dp[0] = 1;
	for(int i = 0; i < 52; ++i) {
		if(cnt[i]) {
			num = num * inv[cnt[i]] % mod;
			for(int j = n; j >= cnt[i]; --j)
				dp[j] = (dp[j] + dp[j - cnt[i]]) % mod;
		}
	}
	for(int i = 0; i < 52; ++i) {
		res[i][i] = dp[n / 2];
		if(cnt[i]) {
			for(int j = cnt[i]; j <= n; ++j) 
				dp[j] = (dp[j] - dp[j - cnt[i]] + mod) % mod;
			for(int j = i + 1; j < 52; ++j) {
				if(cnt[j]) {
					for(int k = cnt[j]; k <= n; ++k) {
						dp[k] = (dp[k] - dp[k - cnt[j]] + mod) % mod;
					}
					res[i][j] = res[j][i] = 2LL * dp[n / 2] % mod;
					for(int k = n; k >= cnt[j]; --k) {
						dp[k] = (dp[k] + dp[k - cnt[j]] + mod) % mod;
					}
				}
			}
			for(int j = n; j >= cnt[i]; --j) 
				dp[j] = (dp[j] + dp[j - cnt[i]] + mod) % mod;
		}
	}
	while(q--) {
		scanf("%d%d", &x, &y);
		printf("%lld\n", num * res[mp(s[x - 1])][mp(s[y - 1])] % mod);
	}
	return 0;
}