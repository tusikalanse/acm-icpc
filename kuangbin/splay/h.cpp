#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN = 1e6 + 10;
int a[MAXN], n;

struct SplayTree {
	int ch[MAXN][2], fa[MAXN], key[MAXN], sz, root, size[MAXN];

	void clear(int rt) {
		ch[rt][0] = ch[rt][1] = fa[rt] = key[rt] = size[rt] = 0;
	}

	void newnode(int pre, int val, int &rt) {
		rt = ++sz;
		fa[rt] = pre;
		key[rt] = val;
		ch[rt][0] = ch[rt][1] = 0;
		size[rt] = 1;
	}

	void pushup(int rt) {
		size[rt] = 1 + size[ch[rt][0]] + size[ch[rt][1]];
	}

	void build(int pre, int l, int r, int &rt) {
		if(l > r) return;
		int mid = l + r >> 1;
		newnode(pre, a[mid], rt);
		build(rt, l, mid - 1, ch[rt][0]);
		build(rt, mid + 1, r, ch[rt][1]);
		pushup(rt);
	}

	void init() {
		root = sz = 0;
		ch[root][0] = ch[root][1] = fa[root] = size[root] = 0;
		//build(0, 1, n, root);
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
		return ch[rt][0] ? Find_min(ch[rt][0]) : key[rt];
	}

	int Find_max(int rt) {
		pushdown(rt);
		return ch[rt][1] ? Find_max(ch[rt][1]) : key[rt];
	}

	int Find_kth(int rt, int k) {
		pushdown(rt);
		int t = size[ch[rt][0]] + 1;
		if(t == k) {
			splay(rt, 0);
			return rt;
		}
		return t < k ? Find_kth(ch[rt][0], k) : Find_kth(ch[rt][1], k - t);
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

	void insert(int v) {
		int rt = root;
		if(root == 0) 
			newnode(0, v, root);
		else {
			while(ch[rt][key[rt] < v])
				rt = ch[rt][key[rt] < v];
			newnode(rt, v, ch[rt][key[rt] < v]);
			splay(ch[rt][key[rt] < v], 0);
		}
	}

	void print(int rt) {
		if(ch[rt][0]) {
			printf("###%d %d###", key[rt], key[ch[rt][0]]);
			print(ch[rt][0]);
		}
		printf("%d ", key[rt]);
		if(ch[rt][1]) {
			printf("###%d %d###", key[rt], key[ch[rt][1]]);
			print(ch[rt][1]);
		}
		if(rt == root)
			puts("");
	}

}spt;

int main() {
	scanf("%d", &n);
	spt.init();
	LL ans = 0;
	int t;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &t);
		spt.insert(t);
		//spt.print(spt.root);
		if(i == 0)
			ans += t;
		else {
			if(spt.ch[spt.root][0] == 0)
				ans += spt.Find_min(spt.ch[spt.root][1]) - t;
			else if(spt.ch[spt.root][1] == 0)
				ans += t - spt.Find_max(spt.ch[spt.root][0]);
			else ans += min(spt.Find_min(spt.ch[spt.root][1]) - t, t - spt.Find_max(spt.ch[spt.root][0]));
		}
	}
	printf("%lld\n", ans);
	return 0;
}