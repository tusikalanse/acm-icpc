//segment tree divide and conquer
//linear base, dsu(rollback)
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct Linear_Base {
	int a[30];
	Linear_Base() {memset(a, 0, sizeof(a));}
	void insert(int val) {
		for(int i = 29; ~i; --i) {
			if((val >> i) & 1) {
				if(a[i] == 0) {
					a[i] = val;
					return;
				}
				val ^= a[i];
			}
		}
	}
	int query(int val) {
		for(int i = 29; ~i; --i)
			val = min(val, val ^ a[i]);
		return val;
	}
};

pair<int*, int> save[N * 10];
int top;

void change(int &address, int val) {
	save[top++] = make_pair(&address, address);
	address = val;
}

void rollback(int st) {
	while(st != top) {
		top--;
		*save[top].first = save[top].second;
	}
}

struct edge {
	int x, y, d;
	edge() {x = y = d = 0;}
	edge(int _x, int _y, int _d) : x(_x), y (_y), d(_d) {}
};

struct que {
	int x, y, id;
	que() {x = y = id = 0;}
	que(int _x, int _y, int _id) : x(_x), y (_y), id(_id) {}
};

int ans[N], tot;

vector<edge> G[N << 2];
vector<que> Q[N << 2]; 

int dsu[N], size[N], dis[N];

int find(int x) {
	return x == dsu[x] ? x : find(dsu[x]);
}

int get_dist(int x) {
	return x == dsu[x] ? 0 : dis[x] ^ get_dist(dsu[x]); 
}

int unite(int x, int y, int d) {
	d ^= get_dist(x);
	d ^= get_dist(y);
	x = find(x);
	y = find(y);
	if(x == y) 
		return 0;
	if(size[x] < size[y]) swap(x, y);
	change(size[x], size[x] + size[y]);
	change(dsu[y], x);
	change(dis[y], d);
	return 1;
}

void update(int rt, int l, int r, int L, int R, const edge &x) {
	if(L <= l && r <= R) {G[rt].push_back(x); return;}
	int mid = l + r >> 1;
	if(L <= mid) update(rt << 1, l, mid, L, R, x);
	if(R > mid) update(rt << 1 | 1, mid + 1, r, L, R, x);
}

void add_query(int rt, int l, int r, int pos, const que &x) {
	if(l == r) {Q[rt].push_back(x); return;}
	int mid = l + r >> 1;
	if(pos <= mid) add_query(rt << 1, l, mid, pos, x);
	else add_query(rt << 1 | 1, mid + 1, r, pos, x);
}

void dfs(int rt, int l, int r, Linear_Base Base) {
	int st = top;
	for(auto e : G[rt]) {
		if(!unite(e.x, e.y, e.d)) {
			Base.insert(get_dist(e.x) ^ get_dist(e.y) ^ e.d);
		}
	}
	if(l == r) {
		for(auto q : Q[rt]) 
			ans[q.id] = Base.query(get_dist(q.x) ^ get_dist(q.y));
	}
	else {
		int mid = l + r >> 1;
		dfs(rt << 1, l, mid, Base);
		dfs(rt << 1 | 1, mid + 1, r, Base);
	}
	rollback(st);
}

int n, m, q, op, x, y, d;
map<pair<int, int>, pair<int, int>> st;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) dsu[i] = i, size[i] = 1, dis[i] = 0;
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &x, &y, &d);
		st[make_pair(x, y)] = make_pair(1, d);
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i) {
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1) {
			scanf("%d", &d);
			st[make_pair(x, y)] = make_pair(i, d);
		}
		else if(op == 2) {
			update(1, 1, q, st[make_pair(x, y)].first, i, edge(x, y, st[make_pair(x, y)].second));
			st.erase(make_pair(x, y));
		}
		else {
			add_query(1, 1, q, i, que(x, y, ++tot));
		}
	}
	for(auto e: st) {
		update(1, 1, q, e.second.first, q, edge(e.first.first, e.first.second, e.second.second));
	}
	dfs(1, 1, q, Linear_Base());
	for(int i = 1; i <= tot; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}