#include <bits/stdc++.h>
using namespace std;

const int N = 110;

vector<int> G[N], F[N];
int T, n, m, x, y, deg[2][N], vis[N], mark[N], vv[N], l[N], r[N], sz[N];
bitset<N> bs[N];

bool topo() {
	int cnt = 0;
	queue<int> que;
	for(int i = 1; i <= n; ++i) {
		if(deg[0][i] == 0) {
			que.push(i);
		}
	}
	while(!que.empty()) {
		stack<int> s, ss;
		while(!que.empty()) {
			int t = que.front();
			que.pop();
			cnt++;
			for(auto j : G[t]) {
				if(--deg[0][j] == 0)
					que.push(j);
			}
		}
	}
	return cnt == n;
}

bitset<N> dfs(int rt) {
	if(vv[rt])
		return bs[rt];
	vv[rt] = 1;
	bs[rt].set(rt);
	for(int i : F[rt]) {
		bs[rt] |= dfs(i);
	}
	sz[rt] = bs[rt].count();
	l[rt] = sz[rt];
	return bs[rt];
}

bitset<N> dfs2(int rt) {
	if(vv[rt])
		return bs[rt];
	vv[rt] = 1;
	bs[rt].set(rt);
	for(int i : G[rt]) {
		bs[rt] |= dfs2(i);
	}
	sz[rt] = bs[rt].count();
	r[rt] = n - sz[rt] + 1;
	return bs[rt];
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			bs[i].reset();
			G[i].clear();
			F[i].clear();
			deg[0][i] = deg[1][i] = 0;
			vis[i] = 0;
			vv[i] = 0;
			mark[i] = 0;
			l[i] = r[i] = 0;
		}
		for(int i = 1; i <= m; ++i) {
			scanf("%d%d", &x, &y);
			G[x].push_back(y);
			F[y].push_back(x);
			deg[0][y]++;
			deg[1][x]++;
			vis[x] = vis[y] = 1;
		}
		if(topo()) {
			memset(vv, 0, sizeof(vv));
			memset(sz, 0, sizeof(sz));
			for(int i = 1; i <= n; ++i) if(!vv[i]) {
				dfs(i);
			}
			for(int i = 1; i <= n; ++i) bs[i].reset();
			memset(vv, 0, sizeof(vv));
			memset(sz, 0, sizeof(sz));
			for(int i = 1; i <= n; ++i) if(!vv[i]) {
				dfs2(i);
			}
			for(int i = 1; i <= n; ++i) {
				if(vis[i] == 0) {
					putchar('1');
					continue;
				}
				//printf("l[%d], r[%d] = %d, %d\n", i, i, l[i], r[i]);
				putchar(l[i] <= (n + 1) / 2 && r[i] >= (n + 1) / 2 ? '1' : '0');
			}
			puts("");
		}
		else {
			for(int i = 1; i <= n; ++i) 
				putchar('0');
			puts("");
		}
	}
	return 0;
}