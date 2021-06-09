#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL n, ans;
int k;
const int mod = 1e9 + 7;
vector< pair<LL, int> > v;


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

void foo(LL n) {
	LL a = 2;
	while(a * a <= n) {
		if(n % a == 0) {
			int tmp = 0;
			while(n % a == 0) {
				n /= a;
				tmp++;
			}
			v.push_back(make_pair(a, tmp));
		}
		a++;
	}
	if(n != 1)
		v.push_back(make_pair(n % mod, 1));
}

LL dp[30][60][10010];

void dfs(LL pos, LL a) {
	if(pos == v.size()) {
		ans = (ans + a) % mod;
		return;
	}
	dfs(pos + 1, a * dp[pos][0][k] % mod);
	for(int i = 1; i <= v[pos].second; ++i) {
		a = a * v[pos].first % mod;
		dfs(pos + 1, a * dp[pos][i][k] % mod);
	}
}

int main() {
	cin >> n >> k;
	foo(n);
	for(int i = 0; i < v.size(); ++i) {
		dp[i][v[i].second][0] = 1;
		for(int j = 1; j <= k; ++j) {
			for(int ii = 0; ii <= v[i].second; ++ii) if(dp[i][ii][j - 1]) {
				LL inv = qp(ii + 1, mod - 2);
				for(int jj = 0; jj <= ii; ++jj)
					dp[i][jj][j] = (dp[i][jj][j] + dp[i][ii][j - 1] * inv % mod) % mod;
			}
		}
	}
	dfs(0, 1);
	cout << ans << endl;
	return 0;
}