#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

int n, k, x, y, z, vis[N];
long long ans;
vector<int> edge[N];

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

int dfs(int rt, int pre) {
	int res = 1;
	vis[rt] = 1;
	for(int j : edge[rt]) {
		if(j != pre)
			res += dfs(j, rt);
	}
	return res;
}

int main() {
	scanf("%d%d", &n, &k);
	ans = qp(n, k);
	for(int i = 1; i < n; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		if(z == 1)
			continue;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			ans = ((ans - qp(dfs(i, 0), k)) % mod + mod) % mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}