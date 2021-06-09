#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int n, T, ans[N][N], Q, l, r;
int sz, last, nxt[N << 1][26], len[N << 1], fail[N << 1];
int tot;
char s[N];


int newnode(int x) {
	len[sz] = x;
	memset(nxt[sz], 0, sizeof(nxt[sz]));
	return sz++;
}

void init() {
	sz = last = 0;
	newnode(0);
	fail[last] = -1;
}

int add(int x) {
	int p = last, np = newnode(len[last] + 1);
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
	return len[np] - len[fail[np]];
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s);
		n = strlen(s);
		for(int i = 0; i < n; ++i) {
			init();
			tot = 0;
			for(int j = i; j < n; ++j) {
				ans[i][j] = (tot += add(s[j] - 'a'));
			}
		}
		scanf("%d", &Q);
		while(Q--) {
			scanf("%d%d", &l, &r);
			printf("%d\n", ans[l - 1][r - 1]);
		}
	}
	return 0;
}