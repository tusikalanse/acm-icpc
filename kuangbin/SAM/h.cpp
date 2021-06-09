#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

char s[N];
int n;
int sz, last, nxt[N << 1][26], len[N << 1], fail[N << 1], siz[N << 1], l[N << 1], r[N << 1], c[N], pos[N << 1];
long long ans;

int newnode(int x) {
	len[sz] = x;
	siz[sz] = 0;
	memset(nxt[sz], 0, sizeof(nxt[sz]));
	return sz++;
}

void init() {
	ans = sz = 0;
	last = newnode(0);
	fail[last] = -1;
}

void add(int x) {
	int p = last, np = newnode(len[last] + 1);
	siz[np] = 1;
	l[np] = r[np] = len[np];
	for(; ~p && !nxt[p][x]; p = fail[p])
		nxt[p][x] = np;
	if(p == -1) 
		fail[np] = 0;
	else {
		int q = nxt[p][x];
		if(len[q] == len[p] + 1) 
			fail[np] = q;
		else {
			int nq = newnode(len[p] + 1);
			fail[nq] = fail[q];
			fail[q] = fail[np] = nq;
			l[nq] = r[nq] = l[q];
			memcpy(nxt[nq], nxt[q], sizeof(nxt[nq]));
			for(; ~p && nxt[p][x] == q; p = fail[p])
				nxt[p][x] = nq;
		}
	}
	last = np;
}

void topo() {
	for(int i = 0; i <= n; ++i) c[i] = 0;
	for(int i = 0; i < sz; ++i) c[len[i]]++;
	for(int i = 1; i <= n; ++i) c[i] += c[i - 1];
	for(int i = sz - 1; ~i; --i) pos[--c[len[i]]] = i;
}

int main() {
	while(~scanf("%s", s) && s[0] != '#') {
		n = strlen(s);
		init();
		for(int i = 0; i < n; ++i)
			add(s[i] - 'a');
		topo();
		for(int i = sz - 1; ~i; --i) {
			int t = pos[i];
			if(siz[t] >= 2) {
				ans += max(0, min(r[t] - l[t], len[t]) - len[fail[t]]);
			}
			if(fail[t]) {
				siz[fail[t]] += siz[t];
				r[fail[t]] = max(r[fail[t]], r[t]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}