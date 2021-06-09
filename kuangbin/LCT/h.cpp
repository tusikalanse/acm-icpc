#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 3e4 + 10;
int a[N];
struct node {
	int fa, ch[2];
	int num, sum;
	bool rev, is_root;
}LCT[N];

int n, m;

void pushup(int rt) {
	if(!rt) return;
	LCT[rt].sum = LCT[rt].num + LCT[LCT[rt].ch[0]].sum + LCT[LCT[rt].ch[1]].sum;
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
		pushup(rt);
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
	if(judge(x, y)) {
		puts("no");
		return;
	}
	makeroot(x);
	LCT[x].fa = y;
	puts("yes");
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

void count(int x, int y) {
	if(!judge(x, y)) {
		puts("impossible");
		return;
	}
	makeroot(x);
	access(y);
	splay(y);
	printf("%d\n", LCT[y].sum);
}

void change(int x, int y) {
	splay(x);
	LCT[x].num = y;
	pushup(x);
}

void solve() {
	scanf("%d", &m);
	char op[30];
	int u, v;
	while(m--) {
		scanf("%s%d%d", op, &u, &v);
		if(op[0] == 'p')
			change(u, v);
		else if(op[0] == 'b')
			link(u, v);
		else
			count(u, v);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		LCT[i].fa = LCT[i].ch[0] = LCT[i].ch[1] = LCT[i].rev = 0;
		LCT[i].is_root = 1;
		scanf("%d", &LCT[i].num);
		LCT[i].sum = LCT[i].num;
	}
	solve();
	return 0;
}