#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;

int k[N];
int pre[N][17];

struct node {
	int fa, ch[2], size;
	bool rev, is_root;
}LCT[N];

int n, m;

void pushup(int rt) {
	LCT[rt].size = 1 + LCT[LCT[rt].ch[0]].size + LCT[LCT[rt].ch[1]].size;
}

void pushreverse(int rt) {
	if(!rt) return;
	swap(LCT[rt].ch[0], LCT[rt].ch[1]);
	LCT[rt].rev ^= 1;
}

void pushdown(int rt) {
	if(!rt) return;
	if(LCT[rt].rev) {
		pushreverse(LCT[rt].ch[0]);
		pushreverse(LCT[rt].ch[1]);
		LCT[rt].rev = 0;
	}
}

void down(int rt) {
	if(!LCT[rt].is_root) down(LCT[rt].fa);
	pushdown(rt);
}

int get(int rt) {
	return rt == LCT[LCT[rt].fa].ch[1];
}

void rotate(int rt) {
	if(LCT[rt].is_root) return;
	int fa = LCT[rt].fa, pa = LCT[fa].fa, witch = get(rt);
	pushdown(fa); pushdown(rt);
	LCT[fa].ch[witch] = LCT[rt].ch[witch ^ 1];
	if(LCT[rt].ch[witch ^ 1])	LCT[LCT[rt].ch[witch ^ 1]].fa = fa;
	LCT[rt].ch[witch ^ 1] = fa;
	LCT[fa].fa = rt;
	LCT[rt].fa = pa;
	if(!LCT[fa].is_root) LCT[pa].ch[fa == LCT[pa].ch[1]] = rt;
	else LCT[fa].is_root = 0, LCT[rt].is_root = 1;
	pushup(fa); pushup(rt);
}

void splay(int rt) {
	down(rt);
	for(int fa; !LCT[rt].is_root; rotate(rt)) {
		if(!LCT[fa = LCT[rt].fa].is_root) 
			rotate(get(rt) == get(fa) ? fa : rt);
	}
	pushup(rt);
}

void access(int rt) {
	int y = 0;
	do {
		splay(rt);
		LCT[LCT[rt].ch[1]].is_root = 1;
		LCT[LCT[rt].ch[1] = y].is_root = 0;
		rt = LCT[y = rt].fa;
	} while(rt);
}

void makeroot(int rt) {
	access(rt);
	splay(rt);
	pushreverse(rt);
}

int query(int rt) {
	makeroot(0);
	access(rt);
	splay(rt);
	return LCT[rt].size - 1; 
}

void link(int x, int y) {
	makeroot(x);
	LCT[x].fa = y;
	splay(x);
}

void cut(int x, int y) {
	makeroot(x);
	access(y);
	splay(y);
	pushdown(y);
	LCT[LCT[y].ch[0]].fa = LCT[y].fa;
	LCT[LCT[y].ch[0]].is_root = 1;
	LCT[y].fa = LCT[y].ch[0] = 0;
	pushup(y);
}

int find(int rt, int k) {
	for(int i = 0; i < 17; ++i) {
		if((1 << i) & k)
			rt = pre[rt][i];
	}
	return rt;
}

void solve() {
	int u, v, op;
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d", &op, &u);
		if(op == 1)
			printf("%d\n", query(u));
		else {
			scanf("%d", &v);
			cut(u, k[u]);
			k[u] = find(u, v);
			link(u, k[u]);
		}
	}
}

int T;

int main() {
	for(scanf("%d", &T); T; --T) {
		scanf("%d", &n);
		LCT[1].size = LCT[1].is_root = 1;
		LCT[1].fa = LCT[1].ch[0] = LCT[1].ch[1] = LCT[1].rev = 0;
		for(int i = 2; i <= n; ++i) {
			scanf("%d", &pre[i][0]);
			LCT[i].size = 1;
			LCT[i].fa = LCT[i].ch[0] = LCT[i].ch[1] = LCT[i].rev = 0;
			LCT[i].is_root = 1;
		}
		pre[1][0] = 0;
		LCT[0].size = LCT[0].is_root = 1;
		LCT[0].fa = LCT[0].ch[0] = LCT[0].ch[1] = LCT[0].rev = 0;
		for(int j = 0; j < 17; ++j) pre[0][j] = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j < 17; ++j)
				pre[i][j] = pre[pre[i][j - 1]][j - 1];
		}
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &k[i]);
			k[i] = find(i, k[i]);
			link(i, k[i]);
		}
		solve();
	}	
	return 0;
}