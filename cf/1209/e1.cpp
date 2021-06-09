#include <bits/stdc++.h>
using namespace std;

int d[13][1210], n, m, T, dp[13];
long long ans;
set<pair<int, pair<int, int>>> s;
vector<pair<int, pair<int, int>>> vec;

bool judge() {
	map<int, int> col;
	for(int i = 0; i < n; ++i)
		col[vec[dp[i]].second.second]++;
	if(!(n == 4 && col.size() == 2 && col.begin() -> second == 2))
		return true;
	pair<int, int> f[4];
	for(int i = 0; i < n; ++i)
		f[i] = vec[dp[i]].second;
	if(f[0].second == f[2].second)
		swap(f[1], f[2]);
	if(f[0].second == f[3].second)
		swap(f[1], f[3]);
	int d1 = max(f[0].first, f[1].first) - min(f[0].first, f[1].first);
	int d2 = max(f[2].first, f[3].first) - min(f[2].first, f[3].first);
	assert(f[2].second == f[3].second);
	assert(d1 && d2);
	if(d1 == 3) d1 = 1;
	if(d2 == 3) d2 = 1;
	if(d1 > d2) swap(d1, d2);
	if(d1 == 1 && d2 == 2) return false;
	return true;
}

long long sum() {
	long long res = 0;
	for(int i = 0; i < n; ++i)
		res += vec[dp[i]].first;
	return res;
}

void dfs(int stp, int now) {
	if(stp == n) {
		if(judge())
			ans = max(ans, sum());
		return;
	}
	for(int i = now; i < vec.size(); ++i) {
		dp[stp] = i;
		dfs(stp + 1, i + 1);
		dp[stp] = 0;
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		s.clear();
		vec.clear();
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf("%d", &d[i][j]);
				s.insert(make_pair(d[i][j], make_pair(i, j)));
				if(s.size() > n * n)
					s.erase(s.begin());
			}
		}
		for(auto i: s)
			vec.push_back(i);
		ans = 0;
		dfs(0, 0);
		printf("%lld\n", ans);
	}
	return 0;
}