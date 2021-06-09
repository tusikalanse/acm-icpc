#include <bits/stdc++.h>
using LL = long long;
using namespace std;

const int N = 200010;
struct Node{int to,next;};
int T, n, m, q, u, v, dfn[N], clo, rev[N], f[N], semi[N], idom[N], deg[N], dep[N], fa[N][18];

struct Graph{
	Node E[N << 1]; int head[N], tot;
	inline void clear(){
		tot = 0;
		for(int i = 0; i <= n; ++i) head[i] = -1;
	}
	inline void link(int u, int v){
		E[tot] = (Node){v, head[u]}; head[u] = tot++;
	}
}pre, nxt, dom;

struct uset{
	int fa[N], Mi[N];
	inline void init(){
		for(int i = 1; i <= n; ++i)
			fa[i] = Mi[i] = semi[i] = i;
	}
	inline int find(int x){
		if(fa[x] == x) return x;
		int fx = fa[x], y = find(fa[x]);
		if(dfn[semi[Mi[fx]]] < dfn[semi[Mi[x]]]) Mi[x] = Mi[fx];
		return fa[x] = y;
	}
}uset;

inline void tarjan(int x) {
	dfn[x] = ++clo; rev[clo] = x;
	for(int e = nxt.head[x]; ~e; e = nxt.E[e].next){
		if(!dfn[nxt.E[e].to])
			f[nxt.E[e].to] = x, tarjan(nxt.E[e].to);
	}
}

inline void dfs(int x, int pre, int depth) {
	dep[x] = depth;
	fa[x][0] = pre;
	for(int i = 1; i < 18; ++i)
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for(int e = dom.head[x]; ~e; e = dom.E[e].next)
		dfs(dom.E[e].to, x, depth + 1);
}

inline int LCA(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 17; ~i; --i) {
		if(dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	}
	if(u == v) return u;
	for(int i = 17; ~i; --i) {
		if(fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	}
	return fa[u][0];
}

inline void calc(){
	for(int i = n; i >= 2; --i){
		int y = rev[i], tmp = n;
		for(int e = pre.head[y]; ~e; e = pre.E[e].next){
			int x = pre.E[e].to; if(!dfn[x]) continue;
			if(dfn[x] < dfn[y]) tmp = min(tmp, dfn[x]);
			else uset.find(x), tmp = min(tmp, dfn[semi[uset.Mi[x]]]);
		}
		semi[y] = rev[tmp]; uset.fa[y] = f[y];
		dom.link(semi[y], y);
		y = rev[i - 1];
		for(int e = dom.head[y]; ~e; e = dom.E[e].next){
			int x = dom.E[e].to; uset.find(x);
			if(semi[uset.Mi[x]] == y) idom[x] = y;
			else idom[x] = uset.Mi[x];
		}
	}
	for(int i = 2; i <= n; ++i){
		int x = rev[i];
		if(idom[x] != semi[x])
			idom[x] = idom[idom[x]];
	}
	dom.clear();
	for(int i = 1; i < n; ++i) //except the start
		dom.link(idom[i], i);
	dfs(n, 0, 0);
}

int main() {
	//hdu6604
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		clo = 0; n++; dep[0] = -1;
		for(int i = 1; i <= n; ++i)
			deg[i] = dfn[i] = rev[i] = semi[i] = idom[i] = f[i] = 0;
		pre.clear(); nxt.clear(); dom.clear(); uset.init();
		for(int i = 1; i <= m; ++i){
			scanf("%d%d", &u, &v);
			pre.link(u, v);
			nxt.link(v, u);
			deg[u]++;
		}
		for(int i = 1; i < n; ++i) {
			if(deg[i] == 0) {
				nxt.link(n, i);
				pre.link(i, n);
			}
		}
		tarjan(n); //start
		calc();
		scanf("%d", &q);
		while(q--) {
			scanf("%d%d", &u, &v);
			printf("%d\n", dep[u] + dep[v] - dep[LCA(u, v)]);
		}
	}
	return 0;
}