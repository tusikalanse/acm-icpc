#include <bits/stdc++.h>
using namespace std;

const int N = 90010;

int len[N << 1], nxt[N << 1][128], par[N << 1];
int last, sz, n, q, k;
long long ans;
int c[N << 1], pos[N << 1], g[N << 1];
char s[N];

int newnode(int l) {
	len[sz] = l;
	memset(nxt[sz], 0, sizeof(nxt[sz]));
	return sz++;
}

void init() {
	ans = sz = last = 0;
	par[sz] = -1;
	newnode(0);
}

void add(int c) {
	int p = last, np = newnode(len[last] + 1);
	for(; ~p && !nxt[p][c]; p = par[p]) nxt[p][c] = np;
	if(p == -1) par[np] = 0;
	else {
		int q = nxt[p][c];
		if(len[q] == len[p] + 1) par[np] = q;
		else {
			int nq = newnode(len[p] + 1);
			par[nq] = par[q];
			memcpy(nxt[nq], nxt[q], sizeof(nxt[nq]));
			par[q] = par[np] = nq;
			for(; ~p && nxt[p][c] == q; p = par[p])
				nxt[p][c] = nq;
		}
	}
	last = np;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%s", s);
		n = strlen(s);
		for(int i = 0; i < n; ++i)
			add(s[i]);
		for(int i = 1; i < sz; ++i)
			ans += len[i] - len[par[i]];
		printf("%lld\n", ans);
	}
	return 0;
}