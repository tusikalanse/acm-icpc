#include <bits/stdc++.h>
using namespace std;

const int N = 500 * 500 + 10;

int fat[N];
int n, m, v, q, a, b, c, d;
char ch[10];

int head[N], pnt[N << 1], nxt[N << 1], cnt;
int dep[N], son[N], fa[N], dfn[N], rnk[N], size[N], top[N], num;

void init() {
	memset(head, -1, sizeof(head));
	cnt = num = 1;
}


void add(int x, int y) {
    pnt[num] = y;
    nxt[num] = head[x];
    head[x] = num++;
}

void dfs1(int u, int pre, int depth) {
    size[u] = 1;
    fa[u] = pre;
    son[u] = -1;
    dep[u] = depth;
    for(int i = head[u]; ~i; i = nxt[i]) if(pnt[i] != pre) {
        int v = pnt[i];
        dfs1(v, u, depth + 1);
        size[u] += size[v];
        if(son[u] == -1 || size[v] > size[son[u]]) 
            son[u] = v;
    }
}

void dfs2(int u, int t) {
    top[u] = t;
    dfn[u] = cnt;
    rnk[cnt] = u;
    cnt++;
    if(son[u] == -1)
        return;
    dfs2(son[u], t);
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(v != fa[u] && v != son[u])
            dfs2(v, v);
    }
}

int getsum(int va, int vb) {
	int ans = 0, f1 = top[va], f2 = top[vb];
	while(f1 != f2) {
		if(dep[f1] < dep[f2])
			swap(va, vb), swap(f1, f2);
		ans += 1 + dfn[va] - dfn[f1];
		va = fa[f1];
		f1 = top[va];
	}
	if(dep[va] > dep[vb])
		swap(va, vb);
	ans += 1 + dfn[vb] - dfn[va];
	return ans - 1;
}

int find(int x) {
	return x == fat[x] ? x : fat[x] = find(fat[x]);
}

void unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx != fy)
		fat[fx] = fy;
}

struct edge {
	int x, y, val;
	bool operator<(const edge &rhs) const {
		return val < rhs.val;
	}
};

void kru() {
	priority_queue<edge> pq;
	for(int i = 1; i <= n * m; ++i) {
		fat[i] = i;
		scanf("%s %d", ch, &v);
		if(ch[0] == 'D')
			pq.push({i, i + m, v});
		else if(ch[0] == 'R')
			pq.push({i, i + 1, v});
		scanf("%s %d", ch, &v);
		if(ch[0] == 'D')
			pq.push({i, i + m, v});
		else if(ch[0] == 'R')
			pq.push({i, i + 1, v});
	}
	for(int i = 1; i < n * m; ++i) {
		edge u;
		do {
			u = pq.top();
			pq.pop();
		} while(find(u.x) == find(u.y));
		unite(u.x, u.y);
		add(u.x, u.y); add(u.y, u.x);
	}
}


int main() {
	scanf("%d%d", &n, &m);
	init();
	kru();
	scanf("%d", &q);
	dfs1(1, 0, 0);
	dfs2(1, 1);
	while(q--) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int x = (a - 1) * m + b, y = (c - 1) * m + d;
		printf("%d\n", getsum(x, y));
	}
	return 0;
}