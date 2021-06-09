#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 2e5 + 10;

int k[N];

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
	makeroot(n + 1);
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

void solve() {
	int u, v, op;
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d", &op, &u);
		u++;
		if(op == 1)
			printf("%d\n", query(u));
		else {
			scanf("%d", &v);
			cut(u, k[u]);
			k[u] = min(v + u, n + 1);
			link(u, k[u]);
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &k[i]);
		LCT[i].size = 1;
		LCT[i].fa = LCT[i].ch[0] = LCT[i].ch[1] = LCT[i].rev = 0;
		LCT[i].is_root = 1;
	}
	LCT[n + 1].size = LCT[n + 1].is_root = 1;
	LCT[n + 1].fa = LCT[n + 1].ch[0] = LCT[n + 1].ch[1] = LCT[n + 1].rev = 0;
	for(int i = 1; i <= n; ++i) {
		k[i] = i + k[i];
		if(k[i] > n)
			k[i] = n + 1;
		link(i, k[i]);
	}
	solve();
	return 0;
}