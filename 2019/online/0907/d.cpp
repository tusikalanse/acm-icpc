#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int len[N], nxt[N][26], par[N];
int sz, last;

int new_node(int l) {
	len[sz] = l;
	memset(nxt[sz], 0, sizeof(nxt[sz]));
	return sz++;
}

void init() {
	sz = last = 0;
	par[sz] = -1;
	new_node(0);
}

void add(int c) {
	int p = last, np = new_node(len[last] + 1);
	for(; ~p && !nxt[p][c]; p = par[p]) nxt[p][c] = np;
	if(-1 == p) par[np] = 0;
	else {
		int q = nxt[p][c];
		if(len[q] == len[p] + 1) par[np] = q;
		else {
			int nq = new_node(len[p] + 1);
			memcpy(nxt[nq], nxt[q], sizeof(nxt[nq]));
			par[nq] = par[q];
			par[q] = par[np] = nq;
			for(; ~p && nxt[p][c] == q; p = par[p])
				nxt[p][c] = nq;
		}
	}
	last = np;
}

char a[N >> 1], b[N >> 1];
int n, m, q;

int main() {
	init();
	scanf("%s", a);
	n = strlen(a);
	for(int i = 0; i < n; ++i)
		add(a[i] - 'a');
	scanf("%d", &q);
	while(q--) {
		scanf("%s", b);
		m = strlen(b);
		int ans = 0;
		for(int i = 0, l = 0, p = 0; i < m; ++i) {
			int x = b[i] - 'a';
			if(nxt[p][x]) l++, p = nxt[p][x];
			else {
				for(; ~p && !nxt[p][x]; p = par[p]);
				if(-1 == p) l = p = 0;
				else
					l = len[p] + 1, p = nxt[p][x];
			}
			ans = max(ans, l);
		}
		if(m == n) {
			if(ans == n)
				puts("jntm!");
			else
				puts("friend!");
		}
		else if(m > n) {
			if(ans == n)
				puts("my teacher!");
			else
				puts("senior!");
		}
		else {
			if(ans == m)
				puts("my child!");
			else
				puts("oh, child!");
		}
	}
	return 0;
}