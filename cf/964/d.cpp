#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;

int head[MAXN], pnt[MAXN*2], nxt[MAXN*2], cnt = 0, vis[MAXN], d[MAXN], c[MAXN], num;
vector<int> ans;
int flag = 1;

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

int rt;
void dfs1(int u) {
	vis[u] = 1; 
	int c0 = 0;
	if(d[u] == 1)
		c[u] = 0;
	for(int i = head[u]; ~i; i = nxt[i]) {
		int v = pnt[i];
		if(vis[v])
			continue;
		dfs1(v);
		c0 += (c[v] == 0);
	}
	if(u == rt && c0%2) 
		flag = 0;
	c[u] = c0 % 2;
	return ;
}

void dfs2(int u) {
	vis[u] = 1; 
	for(int i = head[u]; ~i; i = nxt[i]) {
		int v = pnt[i];
		if(vis[v])
			continue;
		if(c[v])
			dfs2(v);
	}
	ans.push_back(u);
	for(int i = head[u]; ~i; i = nxt[i]) {
		int v = pnt[i];
		if(vis[v])
			continue;
		if(!c[v])
			dfs2(v);
	}
	return ;
}

int main() {
	int n;
	cin >> n;
	int x;
	num = n;
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		if(x) {
			add(i, x);
			add(x, i);
			++d[x];
			++d[i];
		}
		else 
			rt = i;
	}
	dfs1(rt);
	memset(vis, 0, sizeof(vis));
	dfs2(rt);
	if(!flag)
		puts("NO");
	else {
		puts("YES");
		for(int i = 0; i < n; ++i)
			printf("%d\n", ans[i]);
	}
	return 0;
}