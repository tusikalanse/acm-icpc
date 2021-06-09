#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN = 3e5 + 10;
int a[MAXN], n, m;
char ch[20];
int A, B, C;

struct SplayTree {
	int ch[MAXN][2], fa[MAXN], key[MAXN], sz, root, size[MAXN], rev[MAXN];
	bool first;

	void clear(int rt) {
		ch[rt][0] = ch[rt][1] = fa[rt] = key[rt] = size[rt] = rev[rt] = 0;
	}

	void newnode(int pre, int val, int &rt) {
		rt = ++sz;
		fa[rt] = pre;
		key[rt] = val;
		ch[rt][0] = ch[rt][1] = 0;
		size[rt] = 1;
		rev[rt] = 0;
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
		root = sz = first = 0;
		ch[root][0] = ch[root][1] = fa[root] = size[root] = 0;
		build(0, 0, n + 1, root);
		pushup(root);
	}

	void update_rev(int rt) {
		if(!rt) return;
		swap(ch[rt][0], ch[rt][1]);
		rev[rt] ^= 1;
	}

	void pushdown(int rt) {
		if(rev[rt]) {
			update_rev(ch[rt][0]);
			update_rev(ch[rt][1]);
			rev[rt] = 0;
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

	void FLIP(int A, int B) {
		splay(Find_kth(root, A), 0);
		splay(Find_kth(root, B + 2), root);
		update_rev(ch[ch[root][1]][0]);
	}

	void CUT(int A, int B, int C) {
		splay(Find_kth(root, A), 0);
		splay(Find_kth(root, B + 2), root);
		pushdown(root);
		pushdown(ch[root][1]);
		int tmp = ch[ch[root][1]][0];
		ch[ch[root][1]][0] = 0;
		pushup(ch[root][1]);
		pushup(root);
		splay(Find_kth(root, C + 1), 0);
		splay(Find_kth(root, C + 2), root);
		pushdown(root);
		pushdown(ch[root][1]);
		assert(ch[ch[root][1]][0] == 0);
		ch[ch[root][1]][0] = tmp;
		fa[tmp] = ch[root][1];
		pushup(ch[root][1]);
		pushup(root);
	}

	void print(int rt) {
		if(!rt) 
			return;
		//cout << "RT = " << rt << endl;
		pushdown(rt);
		print(ch[rt][0]);
		if(key[rt] != 0 && key[rt] != n + 1) {
			if(!first) {
				first = 1;
				printf("%d", key[rt]);
			}
			else
				printf(" %d", key[rt]);
		}
		print(ch[rt][1]);
	}

}spt;

int main() {
	for(int i = 0; i < MAXN; ++i) a[i] = i;
	while(~scanf("%d%d", &n, &m) && (n >= 0 || m >= 0)) {
		spt.init();
		while(m--) {
			scanf("%s", ch);
			if(ch[0] == 'C') {
				scanf("%d%d%d", &A, &B, &C);
				spt.CUT(A, B, C);
			}
			else {
				scanf("%d%d", &A, &B);
				spt.FLIP(A, B);
			}
		}
		spt.print(spt.root);
		puts("");
	}
	return 0;
}