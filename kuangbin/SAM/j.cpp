#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 2012;

char s[N];
int n, totn;
int sz, last, nxt[N << 1][10], fail[N << 1], len[N << 1], c[N], pos[N << 1], sum[N << 1], cnt[N << 1];

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
	int p = last, np = newnode(len[p] + 1);
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
	last = nq;
}

void topo() {
	for(int i = 0; i <= totn; ++i) c[i] = 0;
	for(int i = 0; i < sz; ++i) c[len[i]]++;
	for(int i = 1; i <= totn; ++i) c[i] += c[i - 1];
	for(int i = sz - 1; ~i; --i) pos[--c[len[i]]] = i;
}

int calc() {
	for(int i = 0; i < sz; ++i) {
		int t = pos[i];
		for(int j = 0; j < 10; ++j) {
			if(t == 0 && j == 0) continue;
			sum[i] += 
		}
	}
}


int main() {



	return 0;
}