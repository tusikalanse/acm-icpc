#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int nxt[N << 1][26], len[N << 1], par[N << 1];
int sz, last;
char s[N];
int n, p, q;
long long dp[N];

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

void add(int x) {
	int p = last, np = newnode(len[last] + 1);
	for(; ~p && !nxt[p][x]; p = par[p]) nxt[p][x] = np;
	if(p == -1) {
		par[np] = 0;
	}
	else {
		int q = nxt[p][x];
		if(len[q] == len[p] + 1) {
			par[np] = q;
		}
		else {
			int nq = newnode(len[p] + 1);
			memcpy(nxt[nq], nxt[q], sizeof(nxt[nq]));
			par[nq] = par[q];
			par[q] = par[np] = nq;
			for(; ~p && nxt[p][x] == q; p = par[p])
				nxt[p][x] = nq;
		}
	}
	last = np;
}


int main() {
	while(~scanf("%s%d%d", s + 1, &p, &q)) {
		init();
		n = strlen(s + 1);
		int cur = 1, now = 1, pos = 0;
		while(cur <= n) {
			int x = s[cur] - 'a';
			if(nxt[pos][x]) {
				pos = nxt[pos][x];
				dp[cur] = min(dp[cur - 1] + p, dp[now - 1] + q);
				cur++;
			}
			else if(cur == now) {
				add(x);
				dp[cur] = dp[cur - 1] + p;
				cur++;
				now++;
			}
			else {
				add(s[now++] - 'a');
				int tlen = cur - now;
				while(~pos && ~par[pos] && len[par[pos]] >= tlen)
					pos = par[pos];
			}
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}

