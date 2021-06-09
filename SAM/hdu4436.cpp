#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 2012;

int len[N], nxt[N][26], par[N];
int sz, last;
int n, l;
char s[N >> 1];
int deg[N], ans, sum[N], cnt[N], vis[N];

int new_node(int l) {
	len[sz] = l;
	memset(nxt[sz], 0, sizeof(nxt[sz]));
	return sz++;
}

void init() {
	sz = last = 0;
	par[sz] = -1;
	new_node(0);
}

void add(int c) {
	int p = last, np = new_node(len[last] + 1);
	for(; ~p && !nxt[p][c]; p = par[p]) nxt[p][c] = np;
	if(-1 == p) par[np] = 0;
	else {
		int q = nxt[p][c];
		if(len[q] == len[p] + 1) par[np] = q;
		else {
			int nq = new_node(len[p] + 1);
			memcpy(nxt[nq], nxt[q], sizeof(nxt[nq]));
			par[nq] = par[q];
			par[q] = par[np] = nq;
			for(; ~p && nxt[p][c] == q; p = par[p])
				nxt[p][c] = nq;
		}
	}
	last = np;
}


int main() {
	while(~scanf("%d", &n)) {
		memset(deg, 0, sizeof(deg));
		memset(sum, 0, sizeof(sum));
		memset(cnt, 0, sizeof(cnt));
		memset(vis, 0, sizeof(vis));
		ans = 0;
		init();
		for(int i = 1; i <= n; ++i) {
			scanf("%s", s);
			for(int j = 0; s[j]; ++j) 
				add(s[j] - '0');
			if(i != n)
				add(10);
		}
		queue<int> que;
		cnt[0] = 1;
		vis[0] = 1;
		que.push(0);
		while(!que.empty()) {
			int u = que.front();
			que.pop();
			for(int i = 0; i < 10; ++i) {
				if(nxt[u][i]) {
					deg[nxt[u][i]]++;
					if(!vis[nxt[u][i]]) {
						que.push(nxt[u][i]);
						vis[nxt[u][i]] = 1;
					}
				}
			}
		}
		while(!que.empty()) que.pop();
		que.push(0);
		while(!que.empty()) {
			int u = que.front();
			que.pop();
			for(int i = 0; i < 10; ++i) {
				int v = nxt[u][i];
				if(v == 0) continue;
				if(--deg[v] == 0)
					que.push(v);
				if(len[u] == 0 && i == 0) {
					continue;
				}
				cnt[v] += cnt[u];
				cnt[v] %= mod;
				sum[v] = (sum[v] + 10LL * sum[u] + 1LL * i * cnt[u]) % mod;
			}
		}
		for(int i = 0; i < sz; ++i) {
			ans = (ans + sum[i]) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}