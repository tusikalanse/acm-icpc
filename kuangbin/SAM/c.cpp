#include <bits/stdc++.h>
using namespace std;

const int N = 25e4 + 10;

int len[N << 1], nxt[N << 1][26], par[N << 1];
int last, sz, n;
int c[N << 1], pos[N << 1], dp[N], g[N << 1];
char s[N];

int newnode(int l) {
	len[sz] = l;
	memset(nxt[sz], 0, sizeof(nxt[sz]));
	return sz++;
}

void init() {
	sz = last = 0;
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
	init();
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; ++i)
		add(s[i] - 'a');
	for(int i = 0; i <= n; ++i) c[i] = 0;
	for(int i = 0; i < sz; ++i) c[len[i]]++;
	for(int i = 1; i <= n; ++i) c[i] += c[i - 1];
	for(int i = 0; i < sz; ++i) pos[--c[len[i]]] = i;
	int p = 0;
	for(int i = 0; i < n; ++i)
		g[p = nxt[p][s[i] - 'a']]++;
	for(int i = sz - 1; i; --i) {
		int t = pos[i];	
		dp[len[t]] = max(dp[len[t]], g[t]);
		if(g[t] && par[t])
			g[par[t]] += g[t];
	}
//	for(int i = n - 1; i; --i)
//		dp[i] = max(dp[i], dp[i + 1]);
	for(int i = 1; i <= n; ++i)
		printf("%d\n", dp[i]);
	return 0;
}