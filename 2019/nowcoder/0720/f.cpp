#include <bits/stdc++.h>
using namespace std;

const int N = 10 + (1 << 14);

long long dp[N], dp2[N];
long long p[14][N], p2[14][N], ans;

int a[28][28], n, t[N], f[N];
int c[N], tot;
vector<int> v[15];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < 2 * n; ++i) {
		for(int j = 0; j < 2 * n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	tot = (1 << n) - 1;
	c[0] = 0;
	v[0].push_back(0);
	for(int i = 1; i <= tot; ++i) {
		c[i] = c[i >> 1] + (i & 1);
		v[c[i]].push_back(i);
	}
	f[0] = 1;
	t[f[0]] = 0;
	for(int i = 1; i < n; ++i) {
		f[i] = 2 * f[i - 1];
		t[f[i]] = i;
	}
	for(int i = 0; i < n; ++i) {
		for(int mask = 0; mask <= tot; ++mask) {
			long long val = 0;
			for(int j = 0; j < n; ++j) {
				if((1 << j) & mask) {
					val += a[i][j + n];
				}
			}
			p[i][mask] = val;
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int mask = 0; mask <= tot; ++mask) {
			long long val = 0;
			for(int j = 0; j < n; ++j) {
				if((1 << j) & mask) {
					val += a[i + n][j];
				}
			}
			p2[i][mask] = val;
		}
	}
	for(int mask = 0; mask <= tot; ++mask) {
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				if(((mask >> i) & 1) == ((mask >> j) & 1)) continue;
				dp[mask] += a[i][j];
			}
		}
	}
	for(int mask = 0; mask <= tot; ++mask) {
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				if(((mask >> i) & 1) == ((mask >> j) & 1)) continue;
				dp2[mask] += a[i + n][j + n];
			}
		}
	}
	for(int mask = 0; mask <= tot; ++mask) {
		for(auto mask2: v[n - c[mask]]) {
			long long val = dp[mask] + dp2[mask2];
			for(int x = mask; x; x -= x & -x) 
				val += p[t[x & -x]][tot ^ mask2];
			for(int x = mask2; x; x -= x & -x) 
				val += p2[t[x & -x]][tot ^ mask];
			ans = max(ans, val);
		}
	}
	printf("%lld\n", ans);
	return 0;
}