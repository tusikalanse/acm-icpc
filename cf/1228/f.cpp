#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 17) + 10;

vector<int> G[N], deg[N];
int fa[N], dis[N], n, a, b, st, mx;
vector<int> ans;

void dfs(int rt, int pre, int d) {
	dis[rt] = d;
	fa[rt] = pre;
	for(auto i: G[rt]) {
		if(i == pre) continue;
		dfs(i, rt, d + 1);
	}
}

bool check(int rt, int pre) {
	int f = true;
	if(G[rt].size() == 1) return 1;
	if(G[rt].size() != 3) return 0;
	for(auto i: G[rt]) {
		if(i == pre) continue;
		f &= check(i, rt);
	}
	return f;
}

void gao() {
	int ed = 1;
	for(int i = 1; i <= (1 << n) - 2; ++i) {
		if(dis[i] > dis[ed])
			ed = i;
	}
	vector<int> s;
	while(ed != 0) {
		s.push_back(ed);
		ed = fa[ed];
	}
	if(check(s[n - 2], s[n - 1]) && check(s[n - 1], s[n - 2])) {
		ans.push_back(s[n - 2]);
		ans.push_back(s[n - 1]);
	}
}

void solve() {
	for(int i = 1; i <= (1 << n) - 2; ++i)
		deg[G[i].size()].push_back(i);
	if(deg[1].size() + deg[2].size() + deg[3].size() + deg[4].size() != (1 << n) - 2)
		return;
	int ed = 1;
	for(int i = 1; i <= (1 << n) - 2; ++i) {
		if(dis[i] > dis[ed])
			ed = i;
	}
	vector<int> s;
	while(ed != 0) {
		s.push_back(ed);
		ed = fa[ed];
	}
	dfs(s[s.size() / 2], 0, 0);
	int c = 0;
	for(int i = 1; i <= (1 << n) - 2; ++i) {
		if(G[i].size() == 1 && dis[i] != n - 1 && dis[i] != n - 2) return;
		c += G[i].size() == 1 && dis[i] == n - 2;
	}
	if(c & 1) return;
	if((c & (c - 1)) != 0) return;
	if(deg[4].size() != 0) {
		if(deg[4].size() == 1 && deg[2].size() == 1 && deg[3].size() == (1 << (n - 1)) - 4 && deg[1].size() == (1 << (n - 1))) {
			ans.push_back(deg[4][0]);
		}
	}
	if(deg[2].size() != 0) {
		if(deg[2].size() == 2 && deg[4].size() == 0 && deg[1].size() == (1 << (n - 1)) - 1 && deg[3].size() == (1 << (n - 1)) - 3) {
			if(deg[2][0] == s[s.size() / 2])
				ans.push_back(deg[2][1]);
			else
				ans.push_back(deg[2][0]);
		}
	}
}

int main() {
	scanf("%d", &n);
	if(n == 2) {
		printf("2\n1 2\n");
		return 0;
	}
	for(int i = 1; i <= (1 << n) - 3; ++i) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1, 0, 0);
	st = 1;
	for(int i = 1; i <= (1 << n) - 2; ++i) {
		if(dis[i] > dis[st])
			st = i;
	}
	dfs(st, 0, 0);
	mx = 0;
	for(int i = 1; i <= (1 << n) - 2; ++i)
		mx = max(mx, dis[i]);
	if(mx == 2 * n - 3) 
		gao();
	else if(mx == 2 * n - 2)
		solve();
	printf("%d\n", (int)(ans.size()));
	sort(ans.begin(), ans.end());
	for(auto i: ans)
		printf("%d%c", i, " \n"[i == ans.back()]);
	return 0;
}