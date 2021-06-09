#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 998244353;

vector<int> G[N];
map<int, int> m[N];

int sz[N], n, x, y, f[N];
long long ans;

void dfs(int rt, int fa) {
	sz[rt] = 1;
	for(auto j: G[rt]) {
		if(j == fa) continue;
		dfs(j, rt);
		m[rt][sz[j]]++;
		sz[rt] += sz[j];
	}
}

void init() {
	f[0] = 1;
	for(int i = 1; i < N; ++i) 
		f[i] = 1LL * i * f[i - 1] % mod;
}

void dd(int rt, int fa) {
	ans = ans * f[G[rt].size()] % mod;
	for(auto j: G[rt]) {
		if(j == fa) continue;
		dd(j, rt);
	}
}

int main() {
	init();
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 0);
	ans = n;
	dd(1, 0);
	printf("%lld\n", ans);
	return 0;
}