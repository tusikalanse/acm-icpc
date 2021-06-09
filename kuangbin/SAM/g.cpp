#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int n, m, k;
char s[N], t[N];
int sz, last, len[N << 1], fail[N << 1], nxt[N << 1][52], pos[N << 1], c[N], siz[N << 1], cnt[N << 1];
long long ans;

inline int convert(char x) {
	if(x >= 'a' && x <= 'z')
		return x - 'a';
	return 26 + x - 'A';
}

int newnode(int x) {
	len[sz] = x;
	cnt[sz] = 0;
	siz[sz] = 0;
	memset(nxt[sz], 0, sizeof(nxt[sz]));
	return sz++;
}

void init() {
	ans = sz = last = 0;
	last = newnode(0);
	fail[last] = -1;
}

void add(int x) {
	int p = last, np = newnode(len[last] + 1);
	siz[np] = 1;
	for(; ~p && !nxt[p][x]; p = fail[p])
		nxt[p][x] = np;
	if(p == -1)
		fail[np] = 0;
	else {
		int q = nxt[p][x];
		if(len[q] == len[p] + 1) {
			fail[np] = q;
		}
		else {
			int nq = newnode(len[p] + 1);
			memcpy(nxt[nq], nxt[q], sizeof(nxt[nq]));
			fail[nq] = fail[q];
			fail[q] = fail[np] = nq;
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
	for(int i = sz - 1; ~i; --i) {
		int t = pos[i];
		if(fail[t])
			siz[fail[t]] += siz[t];
	}
}


int main() {
	while(~scanf("%d", &k) && k) {
		scanf("%s%s", s, t);
		init();
		n = strlen(s);
		m = strlen(t);
		for(int i = 0; i < n; ++i) 
			add(convert(s[i]));
		topo();
		int p = 0, l = 0;
		for(int i = 0; i < m; ++i) {
			int x = convert(t[i]);
			if(nxt[p][x] != 0) {
				p = nxt[p][x];
				l++;
			}
			else {
				for(; ~p && !nxt[p][x]; p = fail[p]);
				if(p == -1)
					l = p = 0;
				else
					l = len[p] + 1, p = nxt[p][x];
			}
			if(l >= k) {
				ans += 1LL * siz[p] * (l - max(len[fail[p]] + 1, k) + 1);
				cnt[fail[p]]++;
			}
		}
		for(int i = sz - 1; ~i; --i) {
			int t = pos[i];
			if(len[t] >= k) {
				ans += 1LL * siz[t] * cnt[t] * (len[t] - max(len[fail[t]] + 1, k) + 1);
				if(fail[t])
					cnt[fail[t]] += cnt[t];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}