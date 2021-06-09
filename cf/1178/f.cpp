#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e6 + 10, mod = 998244353, M = 1010;
int a[N];
int n, m;
int f[M][M], mx[M], mn[M];
vector<int> d;
vector<int> C[M];


int main() {
	scanf("%d%d", &n, &m);
	d.push_back(-1);
	for(int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
		if(d.empty() || d.back() != a[i]) d.push_back(a[i]);
	}
	m = d.size() - 1;
	if(m > 2 * n + 1) {
		puts("0");
		return 0;
	}
	memset(mn, -1, sizeof(mn));
	for(int i = 1; i <= m; ++i) {
		if(mn[d[i]] == -1)
			mn[d[i]] = i;
		mx[d[i]] = i;
		C[d[i]].push_back(i);
	}
	for(int i = 1; i <= n; ++i) {
		bool flag = false;
		for(int j = mn[i]; j <= mx[i]; ++j) {
			if(d[j] < i)
				flag = true;
			if(d[j] == i && flag) {
				puts("0");
				return 0;
			}
		}
	}
	for(int i = 1; i <= m; ++i) f[i][i] = d[i];
	for(int i = 1; i <= m; ++i) 
		for(int j = i + 1; j <= m; ++j)
			f[i][j] = min(f[i][j - 1], f[j][j]);
	vector<vector<int>> dp(m + 2, vector<int>(m + 2, 1));
	for(int len = 1; len <= m; ++len) {
		for(int l = 1, r = l + len - 1; r <= m; ++l, ++r) {
			int c = f[l][r];
			if(l > mn[c] || r < mx[c]) {
				dp[l][r] = 0;
				continue;
			}
			int left = 0, right = 0;
			for(int i = l; i <= mn[c]; ++i) {
				left = (left + 1LL * dp[l][i - 1] * dp[i][mn[c] - 1] % mod) % mod;
			}
			for(int j = mx[c]; j <= r; ++j) {
				right = (right + 1LL * dp[mx[c] + 1][j] * dp[j + 1][r] % mod) % mod;
			}
			dp[l][r] = 1LL * left * right % mod;
			for(int i = 0; i + 1 < C[c].size(); ++i)
				dp[l][r] = 1LL * dp[l][r] * dp[C[c][i] + 1][C[c][i + 1] - 1] % mod;
		}
	}
	printf("%d\n", dp[1][m]);
	return 0;
}

