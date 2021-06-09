#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

vector<int> v[N];

int a[N], cnt[3], sz[N][3], n, ans, x, y;

void dfs(int rt, int fa) {
	sz[rt][a[rt]]++;
	for(int i : v[rt]) {
		if(i == fa) continue;
		dfs(i, rt);
		sz[rt][0] += sz[i][0];
		sz[rt][1] += sz[i][1];
		sz[rt][2] += sz[i][2];
		if((sz[i][1] == cnt[1] && sz[i][2] == 0) || (sz[i][2] == cnt[2] && sz[i][1] == 0))
			ans++;
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}