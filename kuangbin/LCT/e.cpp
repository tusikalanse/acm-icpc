#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 3e5 + 10;

struct node {
	int fa, ch[2], mx, val, lazy;
	bool rev, is_root;
}LCT[N];

int n, m;

void pushup(int rt) {
	if(!rt) return;
	LCT[rt].mx = max(LCT[rt].val, max(LCT[LCT[rt].ch[0]].mx, LCT[LCT[rt].ch[1]].mx));
}

void pushlazy(int rt, int w) {
	if(!rt) return;
	LCT[rt].mx += w;
	LCT[rt].val += w;
	LCT[rt].lazy += w;
}

void pushreverse(int rt) {
	if(!rt) return;
	swap(LCT[rt].ch[0], LCT[rt].ch[1]);
	LCT[rt].rev ^= 1;
}

void pushdown(int rt) {
	if(!rt) return;
	if(LCT[rt].lazy) {
		pushlazy(LCT[rt].ch[0], LCT[rt].lazy);
		pushlazy(LCT[rt].ch[1], LCT[rt].lazy);
		LCT[rt].lazy = 0;
	}
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

bool link(int x, int y) {
	if(judge(x, y)) return false;
	makeroot(x);
	LCT[x].fa = y;
	return true;
}

bool cut(int x, int y) {
	if(x == y || !judge(x, y)) return false;
	makeroot(x);
	access(y);
	splay(y);
	pushdown(y);
	LCT[LCT[y].ch[0]].fa = LCT[y].fa;
	LCT[LCT[y].ch[0]].is_root = 1;
	LCT[y].fa = LCT[y].ch[0] = 0;
	pushup(y);
	return true;
}

bool add(int x, int y, int w) {
	if(!judge(x, y)) return false;
	makeroot(x);
	access(y);
	splay(y);
	pushlazy(y, w);
	return true;
}

int query(int x, int y) {
	if(!judge(x, y)) return -1;
	makeroot(x);
	access(y);
	splay(y);
	return LCT[y].mx;
}

void solve() {
	int op, x, y, w;
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1) {
			if(!link(x, y)) puts("-1");
		}
		else if(op == 2) {
			if(!cut(x, y)) puts("-1");
		}
		else if(op == 3) {
			scanf("%d", &w);
			if(!add(y, w, x)) puts("-1");
		}
		else
			printf("%d\n", query(x, y));
	}
}

int nxt[N << 1], pnt[N << 1], head[N], cnt, u, v;

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void dfs(int u, int pre) {
	LCT[u].fa = pre;
	for(int i = head[u]; ~i; i = nxt[i]) if(pnt[i] != pre) {
		dfs(pnt[i], u);
	}
}

void init() {
	memset(head, -1, sizeof(head));
	cnt = 0;
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		for(int i = 1; i < n; ++i) {
			scanf("%d%d", &u, &v);
			add(u, v);  add(v, u);
		}
		dfs(1, 0);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &LCT[i].val);
			LCT[i].mx = LCT[i].val;
			LCT[i].ch[0] = LCT[i].ch[1] = LCT[i].rev = 0;
			LCT[i].is_root = 1;
		}
		solve();
		putchar('\n');
	}
	return 0;
}