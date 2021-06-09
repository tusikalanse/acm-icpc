#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1e4 + 10;

struct node {
	int fa, ch[2];
	bool rev, is_root;
}LCT[N];

int n, m;

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
}

void splay(int rt) {
	down(rt);
	for(int fa; !LCT[rt].is_root; rotate(rt)) {
		if(!LCT[fa = LCT[rt].fa].is_root) 
			rotate(get(rt) == get(fa) ? fa : rt);
	}
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

bool judge(int x, int y) {
	while(LCT[x].fa) x = LCT[x].fa;
	while(LCT[y].fa) y = LCT[y].fa;
	return x == y;
}

void link(int x, int y) {
	makeroot(x);
	LCT[x].fa = y;
}

void cut(int x, int y) {
	makeroot(x);
	access(y);
	splay(y);
	pushdown(y);
	LCT[LCT[y].ch[0]].fa = LCT[y].fa;
	LCT[LCT[y].ch[0]].is_root = 1;
	LCT[y].fa = LCT[y].ch[0] = 0;
}



void solve() {
	char op[30];
	int u, v;
	while(m--) {
		scanf("%s%d%d", op, &u, &v);
		if(op[0] == 'Q')
			puts(judge(u, v) ? "Yes" : "No");
		else if(op[0] == 'C')
			link(u, v);
		else
			cut(u, v);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		LCT[i].fa = LCT[i].ch[0] = LCT[i].ch[1] = LCT[i].rev = 0;
		LCT[i].is_root = 1;
	}
	solve();
	return 0;
}