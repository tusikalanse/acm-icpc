#include <bits/stdc++.h>
using namespace std;

int T, n, root, a[5010], tot, cas;

struct node {
	int knd;
	int val[3];
	int son[4];
	int isleaf, fa;
}p[5010];

void init() {
	tot = 1;
	root = 1;
	p[root].knd = 2;
	p[root].val[0] = a[1];
	p[root].isleaf = true;
	p[root].fa = 0;
}

void push(int rt, int lson, int val, int rson) {
	p[rt].isleaf = false;
	p[rt].knd++;
	p[lson].fa = p[rson].fa = rt;
	if(p[rt].knd == 3) {
		if(p[rt].son[0] == lson) {
			p[rt].son[0] = lson;
			p[rt].son[2] = p[rt].son[1];
			p[rt].son[1] = rson;
			p[rt].val[1] = p[rt].val[0];
			p[rt].val[0] = val;
		}
		else {
			p[rt].son[1] = lson;
			p[rt].son[2] = rson;
			p[rt].val[1] = val;
		}
	}
	else {
		if(p[rt].son[0] == lson) {
			p[rt].son[0] = lson;
			p[rt].son[3] = p[rt].son[2];
			p[rt].son[2] = p[rt].son[1];
			p[rt].son[1] = rson;
			p[rt].val[2] = p[rt].val[1];
			p[rt].val[1] = p[rt].val[0];
			p[rt].val[0] = val;
		}
		else if(p[rt].son[1] == lson) {
			p[rt].son[1] = lson;
			p[rt].son[3] = p[rt].son[2];
			p[rt].son[2] = rson;
			p[rt].val[2] = p[rt].val[1];
			p[rt].val[1] = val;
		}
		else {
			p[rt].son[2] = lson;
			p[rt].son[3] = rson;
			p[rt].val[2] = val;
		}
	}
}

void insert(int rt, int val) {
	if(p[rt].knd == 4) {
		p[rt].knd = 2;
		int t = ++tot;
		p[t].knd = 2;
		p[t].val[0] = p[rt].val[2];
		p[t].son[0] = p[rt].son[2];
		p[t].son[1] = p[rt].son[3];
		p[t].isleaf = p[rt].isleaf;
		if(!p[t].isleaf) {
			p[p[t].son[0]].fa = t;
			p[p[t].son[1]].fa = t;
		}
		if(rt == root) {
			root = ++tot;
			p[root].knd = 2;
			p[root].val[0] = p[rt].val[1];
			p[root].son[0] = rt;
			p[root].son[1] = t;
			p[root].fa = 0;
			p[root].isleaf = false;
			p[rt].fa = p[t].fa = root;
			rt = root;
		}
		else {
			push(p[rt].fa, rt, p[rt].val[1], t);
			rt = p[rt].fa;
		}
	}
	if(p[rt].isleaf) {
		p[rt].knd++;
		if(p[rt].knd == 3) {
			if(val < p[rt].val[0]) {
				p[rt].val[1] = p[rt].val[0];
				p[rt].val[0] = val;
			}
			else {
				p[rt].val[1] = val;
			}
		}
		else {
			if(val < p[rt].val[0]) {
				p[rt].val[2] = p[rt].val[1];
				p[rt].val[1] = p[rt].val[0];
				p[rt].val[0] = val;
			}
			else if(val < p[rt].val[1]) {
				p[rt].val[2] = p[rt].val[1];
				p[rt].val[1] = val;
			}
			else {
				p[rt].val[2] = val;
			}
		}
	}
	else {
		if(p[rt].knd == 2) {
			if(val < p[rt].val[0])
				insert(p[rt].son[0], val);
			else
				insert(p[rt].son[1], val);
		}
		else if(p[rt].knd == 3) {
			if(val < p[rt].val[0])
				insert(p[rt].son[0], val);
			else if(val < p[rt].val[1])
				insert(p[rt].son[1], val);
			else insert(p[rt].son[2], val);
		}
		else {
			if(val < p[rt].val[0])
				insert(p[rt].son[0], val);
			else if(val < p[rt].val[1])
				insert(p[rt].son[1], val);
			else if(val < p[rt].val[2]) 
				insert(p[rt].son[2], val);
			else
				insert(p[rt].son[3], val);
		}
	}
}

void print(int rt) {
	// cout << "###id, fa, knd " << rt << " " << p[rt].fa << " " << p[rt].knd << " ###";
	for(int i = 0; i < p[rt].knd - 1; ++i)
		printf("%d%c", p[rt].val[i], " \n"[i + 2 == p[rt].knd]);
	if(p[rt].isleaf) return;
	for(int i = 0; i < p[rt].knd; ++i)
		print(p[rt].son[i]);
}


void gao() {
	for(int i = 2; i <= n; ++i) {
		insert(root, a[i]);
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		init();
		gao();
		printf("Case #%d:\n", ++cas);
		print(root);
	}
	return 0;
}