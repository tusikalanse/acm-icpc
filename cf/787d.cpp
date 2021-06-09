#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
using LL = long long;
vector<pair<int,int>> G[N << 3];
int in[N << 2], out[N << 2], pos[N], n, q, s, t, v, u, l, r, w, tot;
LL dis[N << 3];

inline void add(int x, int y, int v) {
	G[x].push_back(make_pair(y, v));
}

void build_in(int rt, int l, int r) {
	if(l == r) {
		pos[l] = rt;
		return;
	}
	int mid = l + r >> 1;
	build_in(rt << 1, l, mid);
	build_in(rt << 1 | 1, mid + 1, r);
	add(rt, rt << 1, 0);
	add(rt, rt << 1 | 1, 0);
}

void build_out(int rt, int l, int r) {
	add(rt, tot + rt, 0);
	if(l == r) {
		return;
	}
	int mid = l + r >> 1;
	build_out(rt << 1, l, mid);
	build_out(rt << 1 | 1, mid + 1, r);
	add(tot + (rt << 1), tot + rt, 0);
	add(tot + (rt << 1 | 1), tot + rt, 0);
}

void update_in(int rt, int l, int r, int L, int R, int from, int val) {
	if(L <= l && r <= R) {
		add(tot + pos[from], rt, val);
		return;
	}
	int mid = l + r >> 1;
	if(L <= mid)
		update_in(rt << 1, l, mid, L, R, from, val);
	if(mid < R)
		update_in(rt << 1 | 1, mid + 1, r, L, R, from, val);
}

void update_out(int rt, int l, int r, int L, int R, int pnt, int val) {
	if(L <= l && r <= R) {
		add(tot + rt, pos[pnt], val);
		return;
	}
	int mid = l + r >> 1;
	if(L <= mid)
		update_out(rt << 1, l, mid, L, R, pnt, val);
	if(mid < R)
		update_out(rt << 1 | 1, mid + 1, r, L, R, pnt, val);
}

struct node {
	LL dis;
	int id;
	bool operator<(const node &rhs) const {
		return dis > rhs.dis;
	}
};

void dijk() {
	memset(dis, 0x3f, sizeof(dis));
	dis[pos[s]] = 0;
	priority_queue<node> pq;
	pq.push({0, pos[s]});
	while(!pq.empty()) {
		node u = pq.top();
		pq.pop();
		if(dis[u.id] < u.dis) continue;
		for(auto &j: G[u.id]) {
			if(dis[j.first] > u.dis + j.second) {
				dis[j.first] = u.dis + j.second;
				pq.push({dis[j.first], j.first});
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &q, &s);
	tot = n << 2;
	build_in(1, 1, n);
	build_out(1, 1, n);
	while(q--) {
		scanf("%d", &t);
		if(t == 1) {
			scanf("%d%d%d", &v, &u, &w);
			add(pos[v] + tot, pos[u], w);
		}
		if(t == 2) {
			scanf("%d%d%d%d", &v, &l, &r, &w);
			update_in(1, 1, n, l, r, v, w);
		}
		if(t == 3) {
			scanf("%d%d%d%d", &v, &l, &r, &w);
			update_out(1, 1, n, l, r, v, w);
		}
	}
	dijk();
	for(int i = 1; i <= n; ++i) {
		printf("%lld%c", dis[pos[i]] == 0x3f3f3f3f3f3f3f3f ? -1 : dis[pos[i]], " \n"[i == n]);
	}

	return 0;
}