#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

const int MAXN = 100005;

int cnt, le[MAXN], ri[MAXN], dfn, head[MAXN], lazy[MAXN << 2];
set<int> sum[MAXN << 2];

struct Edge {
	int nxt, pnt;
}edge[MAXN << 1];

void add(int x, int y) {
	edge[cnt].pnt = y;
	edge[cnt].nxt = head[x];
	head[x] = cnt++;
}

void dfs(int rt) {
	le[rt] = ++dfn;
	for(int i = head[rt]; ~i; i = edge[i].nxt) {
		dfs(edge[i].pnt);
	}
	ri[rt] = dfn;
} 

void init() {
	cnt = 0;
	dfn = 0;
	memset(head, -1, sizeof(head));
	memset(deg, 0, sizeof(deg));
}

void pushup(int rt) {
	if(lazy[rt << 1] == lazy[rt << 1 | 1])
		lazy[rt] = lazy[rt << 1];
	else
		lazy[rt] = -1;
	sum[rt].clear();
	if(lazy[rt << 1] == -1) {
		sum[rt].insert(sum[rt << 1].begin(), sum[rt << 1].end());
	}
	else
		sum[rt].insert(lazy[rt << 1]);
	if(lazy[rt << 1 | 1] == -1) {
		sum[rt].insert(sum[rt << 1 | 1].begin(), sum[rt << 1 | 1].end());
	}
	else
		sum[rt].insert(lazy[rt << 1 | 1]);
}

void pushdown(int rt) {
	if(lazy[rt] != -1) {
		lazy[rt << 1] = lazy[rt];
		lazy[rt << 1 | 1] = lazy[rt];
		sum[rt << 1].clear();
		sum[rt << 1 | 1].clear();
		sum[rt << 1].insert(lazy[rt]);
		sum[rt << 1 | 1].insert(lazy[rt]);
		lazy[rt] = -1;
	}
}

void build(int rt, int l, int r) {
	lazy[rt] = -1;
	if(l == r) 
		return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int L, int R, int num) {
	if(l >= L && r <= R) {
		lazy[rt] = num;
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if(mid >= L)
		update(rt << 1, l, mid, L, R, num);
	if(mid < R)
		update(rt << 1 | 1, mid + 1, r, L, R, num);
	pushup(rt);
}

int query(int rt, int l, int r, int pos) {
	if(l == r) {
		return lazy[rt];
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if(mid >= pos)
		return query(rt << 1, l, mid, pos);
	else
		return query(rt << 1 | 1, mid + 1, r, pos);
}

int main() {
	int T, n, u, v, m, x, y, cas = 0, ch;
	scanf("%d", &T);
	while(T--) {
		printf("Case #%d:\n", ++cas);
		init();
		scanf("%d", &n);
		for(int i = 1; i < n; i++) {
			scanf("%d %d", &u, &v);
			add(v, u);
			add(u, v);
		}
		dfs(1);
		build(1, 1, n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &m);
			update(1, 1, n, le[x], le[x], m);
		}
		scanf("%d", &m);
		while(m--) {
			scanf("%d", &ch);
			if(ch == 1) {
				scanf("%d", &x);
				printf("%d\n", query(1, 1, n, le[x], ri[x]));
			}
			else {
				scanf("%d %d", &x, &y);
				update(1, 1, n, le[x], ri[x], y);
			}
		}
	}
	return 0;
}
