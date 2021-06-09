#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e5 + 10;

LL dp[N][220], sum[N];

int l, r, d, w, nxt, val, n, m, k;
int vis[N];
pair<int, int> tmp;
vector<pair<int, int>> t[N], s[N];
multiset<pair<int, int>> mp;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= k; ++i) {
		scanf("%d%d%d%d", &l, &r, &d, &w);
		tmp.first = -w, tmp.second = -d;
		s[r].push_back(tmp);
		t[l].push_back(tmp);
	}
	memset(dp[n + 1], 0, sizeof(dp[n + 1]));
	for(int i = n; i; --i) {
		for(auto &it: s[i])
			mp.insert(it);
		if(!mp.empty()) {
			tmp = *mp.begin();
			nxt = -tmp.second + 1;
			val = -tmp.first;
		}
		else {
			nxt = i + 1;
			val = 0;
		}
		for(int j = 0; j <= m; ++j) {
			dp[i][j] = dp[nxt][j] + val;
			if(j)
				dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
		}
		for(auto &it: t[i]) {
			mp.erase(mp.find(it));
		}
	}
	printf("%lld\n", dp[1][m]);
	return 0;
}