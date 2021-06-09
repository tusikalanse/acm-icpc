#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

namespace SAM {
	int len[N], nxt[N][26], par[N], pos[N], c[N];
	int sz, last;
	int n;
	char s[N];

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

	void topo() {
		for(int i = 0; i <= n; ++i) c[i] = 0;
		for(int i = 0; i < sz; ++i) c[len[i]]++;
		for(int i = 1; i <= n; ++i) c[i] += c[i - 1];
		for(int i = sz - 1; ~i; --i) pos[--c[len[i]]] = i;
	}
	
	void print() {
		for (int i = 0; i < sz; ++i) {
			cout << "node: " << i << endl;
			cout << "len, par = " << len[i] << " " << par[i] << endl;
			for (int ch = 0; ch < 26; ++ch) {
				if (nxt[i][ch])
					cout << (char)('a' + ch) << " : " << nxt[i][ch] << " ";
			}
			cout << endl;
		}
	}
} using namespace SAM;

int T;

int main() {
	scanf("%d", &T);
	init();
	while (T--) {
		last = 0;
		scanf("%s", s);
		n = strlen(s);
		for (int i = 0; i < n; ++i)
			add(s[i] - 'a');
	}
	print();
	return 0;
}