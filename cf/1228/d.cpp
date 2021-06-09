#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> G[N];
int n, m, a, b;
int vis[N];
int cnt[3];

bool check() {
	for(int i = 1; i <= n; ++i) {
		for(auto j: G[i]) {
			if(vis[i] == vis[j])
				return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	vis[0] = vis[n + 1] = 100;
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i = 1; i <= n; ++i) {
		G[i].push_back(0);
		G[i].push_back(n + 1);
	}
	vis[1] = 1;
	sort(G[1].begin(), G[1].end());
	for(int i = 0; i + 1 < G[1].size(); ++i) {
		for(int j = G[1][i] + 1; j < G[1][i + 1]; ++j) 
			vis[j] = 1;
	}
	int s = 0;
	for(int i = 1; i <= n; ++i) {
		if(vis[i] != 1) {
			s = i;
			break;
		}
	}
	if(s == 0) {
		puts("-1");
		return 0;
	}
	sort(G[s].begin(), G[s].end());
	vis[s] = 2;
	for(int i = 0; i + 1 < G[s].size(); ++i) {
		for(int j = G[s][i] + 1; j < G[s][i + 1]; ++j) 
			vis[j] = 2;
	}
	for(int i = 1; i <= n; ++i)
		cnt[vis[i]]++;
	if(1LL * cnt[0] * cnt[1] + 1LL * cnt[1] * cnt[2] + 1LL * cnt[0] * cnt[2] != m || 1LL * cnt[0] * cnt[1] * cnt[2] == 0 || !check()) {
		puts("-1");
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		printf("%d%c", vis[i] + 1, " \n"[i == n]);
	return 0;
}