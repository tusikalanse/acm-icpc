#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int out[N << 2], nxt[N], pos[N], deg[N << 2], T, n, ans[N], id[N << 2];

vector<int> G[N << 2];

void add(int x, int y) {
	G[x].push_back(y);
	deg[y]++;
}

void init(int rt, int l, int r) {
	deg[rt] = 0;
	G[rt].clear();
	if(l == r)
		return;
	int mid = l + r >> 1;
	init(rt << 1, l, mid);
	init(rt << 1 | 1, mid + 1, r);
}

void build(int rt, int l, int r) {
	id[rt] = 0;
	if(l == r) {
		pos[l] = rt;
		id[rt] = l;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	add(rt << 1, rt);
	add(rt << 1 | 1, rt);
}

void update(int rt, int l, int r, int L, int R, int pnt) {
	if(L <= l && r <= R) {
		add(rt, pos[pnt]);
		return;
	}
	int mid = l + r >> 1;
	if(L <= mid)
		update(rt << 1, l, mid, L, R, pnt);
	if(R > mid)
		update(rt << 1 | 1, mid + 1, r, L, R, pnt);
}

void topo() {
	vector<int> a;
	queue<pair<int, int>> que;
	for(int i = 1; i <= n; ++i) {
		if(deg[pos[i]] == 0)
			que.push(make_pair(pos[i], i));
	}
	while(!que.empty()) {
		pair<int, int> u = que.front();
		que.pop();
		if(u.second != 0)
			a.push_back(u.second);
		for(auto &it: G[u.first]) {
			if(--deg[it] == 0) 
				que.push(make_pair(it, id[it]));
		}
	}
	if(a.size() != n) {
		puts("-1");
		return;
	}
	for(int i = 0; i < n; ++i)
		ans[a[i]] = i + 1;
	for(int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], " \n"[i == n]);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		init(1, 1, n);
		build(1, 1, n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &nxt[i]);
			if(nxt[i] == -1)
				continue;
			else if(nxt[i] == n + 1) {
				if(i != n)
					update(1, 1, n, i + 1, n, i);
			}
			else {
				if(i + 1 != nxt[i])
					update(1, 1, n, i + 1, nxt[i] - 1, i);
				add(pos[i], pos[nxt[i]]);
			}
		}
		topo();
	}
	return 0;
}