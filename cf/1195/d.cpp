#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 998244353;

int f[25];

int a[N], n, ans, cnt[12];
vector<int> v[12];
int cc[12][12];
int pi[22], pj[22];

void pre(int i) {
	for(auto f: v[i]) {
		for(int len = 1; len <= i; ++len) {
			cc[i][len] = (cc[i][len] + f % 10) % mod;
			f /= 10;
		}
	}
}

int get(int x) {
	int ans = 0;
	while(x) {
		ans++;
		x /= 10;
	}
	return ans;
}

long long calc(int i, int j) {
	long long ans = 0;
	int now = 1, ii = 1, jj = 1;
	memset(pi, 0, sizeof(pi));
	memset(pj, 0, sizeof(pj));
	while(ii <= i && jj <= j) {
		pi[ii] = now;
		now++, ii++;
		pj[jj] = now;
		now++, jj++;
	}
	while(ii <= i) {
		pi[ii] = now;
		now++, ii++;
	}
	while(jj <= j) {
		pj[jj] = now;
		now++, jj++;
	}
	for(int ii = 1; ii <= i; ++ii) {
		ans = (ans + 1LL * cnt[j] * cc[i][ii] % mod * f[pi[ii]]) % mod;
	}
	for(int jj = 1; jj <= j; ++jj) {
		ans = (ans + 1LL * cnt[i] * cc[j][jj] % mod * f[pj[jj]]) % mod;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	f[1] = 1;
	for(int i = 2; i < 22; ++i) 
		f[i] = 10LL * f[i - 1] % mod;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		int c = get(a[i]);
		cnt[c]++;
		v[c].push_back(a[i]);
	}
	for(int i = 1; i <= 10; ++i)
		pre(i);
	for(int i = 1; i <= 10; ++i) {
		for(int j = 1; j <= 10; ++j) {
			ans = (ans + calc(i, j)) % mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}