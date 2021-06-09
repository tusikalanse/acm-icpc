#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int nxt[N << 1][26], par[N << 1], len[N << 1], c[N], pos[N << 1], mx[N << 1];
int sz, last;
long long ans;
int n, m, k, T, cas = 0;
char s[N], s1[N];

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

void add(int x) {
	int p = last, np = newnode(len[last] + 1);
	for(; ~p && !nxt[p][x]; p = par[p])
		nxt[p][x] = np;
	if(p == -1)
		par[np] = 0;
	else {
		int q = nxt[p][x];
		if(len[q] == len[p] + 1)
			par[np] = q;
		else {
			int nq = newnode(len[p] + 1);
			par[nq] = par[q];
			memcpy(nxt[nq], nxt[q], sizeof(nxt[nq]));
			par[np] = par[q] = nq;
			for(; ~p && nxt[p][x] == q; p = par[p])
				nxt[p][x] = nq;
		}
	}
	last = np;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d %s", &k, s);
		n = strlen(s);
		for(int i = 0; i < n; ++i)
			add(s[i] - 'a');
		for(int i = 0; i <= n; ++i) c[i] = 0;
		for(int i = 0; i < sz; ++i) c[len[i]]++;
		for(int i = 1; i <= n; ++i) c[i] += c[i - 1];
		for(int i = 0; i < sz; ++i) pos[--c[len[i]]] = i;
		memset(mx, 0, sizeof(mx));
		while(k--) {
			scanf("%s", s1);
			m = strlen(s1);
			for(int i = 0, p = 0, l = 0; i < m; ++i) {
				int x = s1[i] - 'a';
				if(nxt[p][x]) p = nxt[p][x], l++;
				else {
					for(; ~p && !nxt[p][x]; p = par[p]);
					if(p == -1)
						p = l = 0;
					else
						l = len[p] + 1, p = nxt[p][x];
				}
				mx[p] = max(mx[p], l);
			}
		}
		for(int i = sz - 1; i; --i) {
			int t = pos[i];
			ans += len[t] - max(mx[t], len[par[t]]);
			if(mx[t] && par[t])
				mx[par[t]] = len[par[t]];
		}
		printf("Case %d: %lld\n", ++cas, ans);
	}
	return 0;
}