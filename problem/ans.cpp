#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], n, m, x, y;

vector<int> edge[N];

int dfs(int u, int fa, int now) {
	int cnt = 0, res = 0;
	if(a[u])
		now++;
	else
		now = 0;
	if(now > m) 
		return 0;
	for(int i = 0; i < edge[u].size(); ++i) {
		int v = edge[u][i];
		if(v == fa) continue;
		cnt++;
	}
	if(cnt == 0) 
		return 1;
	for(int i = 0; i < edge[u].size(); ++i) {
		int v = edge[u][i];
		if(v == fa) continue;
		res += dfs(v, u, now);
	}
	return res;
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i < n; ++i) {
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	cout << dfs(1, 0, 0) << endl;
	return 0;
}