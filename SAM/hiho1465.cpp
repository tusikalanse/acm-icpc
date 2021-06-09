#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;


int len[N], nxt[N][26], par[N];
int sz, last, lenth;
int n, ll, x;
char s[N >> 1], t[N];
int cnt[N], vis[N], pos[N], c[N];



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
	cnt[np] = 1;
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


int main() {
	init();
	scanf("%s %d", s, &n);
	x = strlen(s);
	for(int i = 0; s[i]; ++i) 
		add(s[i] - 'a');
	for(int i = 0; i <= x; ++i) c[i] = 0;
	for(int i = 0; i < sz; ++i) c[len[i]]++;
	for(int i = 1; i <= x; ++i) c[i] += c[i - 1];
	for(int i = 0; i < sz; ++i) pos[--c[len[i]]] = i;
	for(int i = sz - 1; ~i; --i) {
		int j = pos[i];
		if(par[j]) {
			cnt[par[j]] += cnt[j];
		}
	}
	while(n--) {
		scanf("%s", t);
		lenth = ll = strlen(t);
		for(int i = 0; i < ll - 1; ++i) {
			t[i + ll] = t[i];
		}
		t[ll + ll - 1] = '\0';
		int p = 0, l = 0;
		long long ans = 0;
		ll = 2 * ll - 1;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < ll; ++i) {
			int x = t[i] - 'a';
			while(~p && !nxt[p][x])
				p = par[p], l = len[p];
			if(p == -1) {
				p = l = 0;
				continue;
			}
			p = nxt[p][x], l++;
			if(l > lenth) {
				while(len[par[p]] >= lenth)
					p = par[p], l = len[p];
			}
			if(l >= lenth && vis[p] != n + 100) {
				vis[p] = n + 100;
				ans += cnt[p];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}