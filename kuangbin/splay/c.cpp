#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN = 2e5 + 10;
int a[MAXN], n, A, B, m, b[MAXN];
char c[20];

struct SplayTree {
	int ch[MAXN][2], fa[MAXN], key[MAXN], sz, root, num[MAXN], mx[MAXN], size[MAXN];

	void clear(int rt) {
		ch[rt][0] = ch[rt][1] = fa[rt] = key[rt] = mx[rt] = num[rt] = size[rt] = 0;
	}

	void newnode(int pre, int val, int ky, int &rt) {
		rt = ++sz;
		size[rt] = 1;
		fa[rt] = pre;
		key[rt] = val;
		mx[rt] = num[rt] = ky;
		ch[rt][0] = ch[rt][1] = 0;
	}

	void pushup(int rt) {
		size[rt] = 1 + size[ch[rt][0]] + size[ch[rt][1]];
		mx[rt] = num[rt];
		if(ch[rt][0])
			mx[rt] = max(mx[rt], mx[ch[rt][0]]);
		if(ch[rt][1])
			mx[rt] = max(mx[rt], mx[ch[rt][1]]);
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
		ch[root][0] = ch[root][1] = fa[root] = size[root] = 0;
		build(0, 1, n, root);
		insert(0, 0);
		insert(n + 1, 0);
		pushup(root);
	}

	void pushdown(int rt) {}

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
	//		splay(rt, 0);
			return rt;
		}
		return t > k ? Find_kth(ch[rt][0], k) : Find_kth(ch[rt][1], k - t);
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

	void update(int rt, int val) {
		num[rt] = val;
		mx[rt] = max(mx[rt], val);
	}

	void insert(int v, int val) {
		int rt = root;
		if(root == 0) 
			newnode(0, v, val, root);
		else {
			while(ch[rt][key[rt] < v])
				rt = ch[rt][key[rt] < v];
			newnode(rt, v, val, ch[rt][key[rt] < v]);
			splay(ch[rt][key[rt] < v], 0);
		}
	}
}spt;

int main() {
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
			a[i] = i;
		}
		spt.init();
		while(m--) {
			scanf("%s%d%d", c, &A, &B);
			if(c[0] == 'Q') {
				spt.splay(spt.Find_kth(spt.root, A), 0);
				spt.splay(spt.Find_kth(spt.root, B + 2), spt.root);
				printf("%d\n", spt.mx[spt.ch[spt.ch[spt.root][1]][0]]);
			}
			else {
				spt.splay(spt.Find_kth(spt.root, A + 1), 0);
				spt.update(spt.root, B);
			}
		}
	}
	return 0;
}