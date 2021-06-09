#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

const int MAXN = 1e6 + 10;
int a[MAXN], n, q, l, r, b[MAXN], v;
char s[10];

struct SplayTree {
	int ch[MAXN][2], fa[MAXN], key[MAXN], sz, root, size[MAXN];
	LL sum[MAXN], num[MAXN], lazy[MAXN];

	void clear(int rt) {
		sum[rt] = ch[rt][0] = ch[rt][1] = fa[rt] = key[rt] = lazy[rt] = size[rt] = 0;
	}

	void newnode(int pre, int val, int v, int &rt) {
		rt = ++sz;
		fa[rt] = pre;
		size[rt] = 1;
		key[rt] = val;
		num[rt] = v;
		ch[rt][0] = ch[rt][1] = 0;
		sum[rt] = val;
		lazy[rt] = 0;
	}

	void pushup(int rt) {
		sum[rt] = num[rt] + sum[ch[rt][0]] + sum[ch[rt][1]];
		size[rt] = 1 + size[ch[rt][0]] + size[ch[rt][1]];
	}

	void build(int pre, int l, int r, int &rt) {
		if(l > r) return;
		int mid = l + r >> 1;
		newnode(pre, a[mid], b[mid], rt);
		build(rt, l, mid - 1, ch[rt][0]);
		build(rt, mid + 1, r, ch[rt][1]);
		pushup(rt);
	}

	void init() {
		root = sz = 0;
		ch[root][0] = ch[root][1] = fa[root] = lazy[root] = sum[root] = 0;
		build(0, 1, n, root);
		pushup(root);
	}

	void pushdown(int rt) {
		if(lazy[rt]) {
			if(ch[rt][0]) {
				lazy[ch[rt][0]] += lazy[rt];
				num[ch[rt][0]] += lazy[rt];
				sum[ch[rt][0]] += lazy[rt] * size[ch[rt][0]];
			}
			if(ch[rt][1]) {
				lazy[ch[rt][1]] += lazy[rt];
				num[ch[rt][1]] += lazy[rt];
				sum[ch[rt][1]] += lazy[rt] * size[ch[rt][1]];
			}
			lazy[rt] = 0;
		}
	}

	int get(int x) {
		return x == ch[fa[x]][1];
	}

	void rotate(int x) {
		int pre = fa[x], pa = fa[pre], which = get(x);
		ch[pre][which] = ch[x][which ^ 1];
		fa[ch[pre][which]] = pre;
		ch[x][which ^ 1] = pre;
		fa[pre] = x;		
		fa[x] = pa;
		if(pa)
			ch[pa][ch[pa][1] == pre] = x;
		pushup(pre);
		pushup(x);
	}

	void splay(int x, int tar) {
		pushdown(x);
		for(int pre = fa[x]; (pre = fa[x]) != tar; rotate(x)) {
			if(fa[pre] != tar)
				pushdown(fa[pre]), pushdown(pre), pushdown(x), rotate(get(x) == get(pre) ? pre : x);
			else
				pushdown(pre), pushdown(x);
		}
		pushup(x);
		if(tar == 0)
			root = x;
	}

	int Find_min(int rt) {
		pushdown(rt);
		return ch[rt][0] ? Find_min(ch[rt][0]) : (splay(rt, 0), rt);
	}

	int Find_max(int rt) {
		pushdown(rt);
		return ch[rt][1] ? Find_max(ch[rt][1]) : (splay(rt, 0), rt);
	}

	int Find_kth(int rt, int k) {
		pushdown(rt);
		int t = size[ch[rt][0]] + 1;
		if(t == k) {
			// splay(rt, 0);
			return rt;
		}
		return t > k ? Find_kth(ch[rt][0], k) : Find_kth(ch[rt][1], k - t);
	}

	void update(int rt, int val) {
		pushdown(rt);
		sum[rt] += val * size[rt];
		num[rt] += val;
		lazy[rt] += val;
	}

	void del() {
		int old = root;
		if(!ch[root][0]) {
			root = ch[old][1];
			fa[root] = 0;
		}
		else {
			Find_max(ch[root][0]);
			ch[root][1] = ch[old][1];
			fa[old] = root;
		}
		clear(old);
	}

	void insert(int v, int n) {
		int rt = root;
		if(root == 0) 
			newnode(0, v, n, root);
		else {
			while(ch[rt][key[rt] < v])
				rt = ch[rt][key[rt] < v];
			newnode(rt, v, n, ch[rt][key[rt] < v]);
			splay(ch[rt][key[rt] < v], 0);
		}
	}
}spt;

int main() {
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
		a[i] = i;
	}
	spt.init();
	spt.insert(0, 0);
	spt.insert(n + 1, 0);
	while(q--) {
		scanf("%s%d%d", s, &l, &r);
		spt.splay(spt.Find_kth(spt.root, l), 0);
		spt.splay(spt.Find_kth(spt.root, r + 2), spt.root);
		if(s[0] == 'Q')
			printf("%lld\n", spt.sum[spt.ch[spt.ch[spt.root][1]][0]]);
		else {
			scanf("%d", &v);
			spt.update(spt.ch[spt.ch[spt.root][1]][0], v);
		}
	}

	return 0;
}