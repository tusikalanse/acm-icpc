#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int len[N << 1], nxt[N << 1][26], par[N << 1];
int last, sz, n, m;
int cl[N << 1], mn[N << 1];
int c[N << 1], pos[N << 1];


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

char s[N], s1[N];

int main() {
	init();
	memset(mn, 0x3f, sizeof(mn));
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; ++i)
		add(s[i] - 'a');
	for(int i = 0; i <= n; ++i) c[i] = 0;
	for(int i = 0; i < sz; ++i) c[len[i]]++;
	for(int i = 1; i <= n; ++i) c[i] += c[i - 1];
	for(int i = 0; i < sz; ++i) pos[--c[len[i]]] = i;
	while(~scanf("%s", s1)) {
		m = strlen(s1);
		int tmp = 0, p = 0;
		memset(cl, 0, sizeof(cl));
		for(int i = 0; i < m; ++i) {
			if(nxt[p][s1[i] - 'a']) 
				tmp++, p = nxt[p][s1[i] - 'a'];
			else {
				for(; ~p && !nxt[p][s1[i] - 'a']; p = par[p]);
				if(p == -1)
					tmp = p = 0;
				else
					tmp = len[p] + 1, p = nxt[p][s1[i] - 'a'];
			}
			cl[p] = max(cl[p], tmp);
		}
		for(int i = sz - 1; ~i; --i) {
			int t = pos[i];
			mn[t] = min(mn[t], cl[t]);
			if(cl[t] && par[t])
				cl[par[t]] = len[par[t]];
		}
	}
	int ans = 0;
	for(int i = 0; i < sz; ++i) {
		ans = max(ans, mn[i]);
	}
	printf("%d\n", ans);
	return 0;
}