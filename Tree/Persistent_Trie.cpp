#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 10;

int n, m, l, r, x, s[N];
char op[3];

struct PersistentTrie {
	int nxt[N * 27][2], cnt[N * 27], root[N], sz;
	void init() {
		root[0] = 0; 
		nxt[0][0] = nxt[0][1] = cnt[0] = 0;
		sz = 1;
	}
	void insert(int x, int &y, int val) {
		y = sz++;
		memcpy(nxt[y], nxt[x], sizeof(nxt[y]));
		cnt[y] = cnt[x] + 1;
		int p = y;
		for(int i = 25; ~i; --i) {
			int c = (val >> i) & 1;
			nxt[p][c] = sz++;
			p = nxt[p][c]; x = nxt[x][c];
			memcpy(nxt[p], nxt[x], sizeof(nxt[p]));
			cnt[p] = cnt[x] + 1;
		}
	}
	int query(int l, int r, int x) {
		int p = root[l - 1], q = root[r];
		for(int i = 25; ~i; --i) {
			int c = (x >> i) & 1;
			if(cnt[nxt[p][c ^ 1]] < cnt[nxt[q][c ^ 1]]) {
				x ^= (c ^ 1) << i;
				p = nxt[p][c ^ 1]; q = nxt[q][c ^ 1];
			}
			else {
				x ^= c << i;
				p = nxt[p][c]; q = nxt[q][c];
			}
		}
		return x;
	}
}Trie;

int main() {
	scanf("%d%d", &n, &m);
	n++;
	Trie.init();
	Trie.insert(Trie.root[0], Trie.root[1], 0);
	for(int i = 2; i <= n; ++i) {
		scanf("%d", &x);
		s[i] = s[i - 1] ^ x;
		Trie.insert(Trie.root[i - 1], Trie.root[i], s[i]);
	}
	for(int i = 1; i <= m; ++i) {
		scanf("%s", op);
		if(op[0] == 'A') {
			scanf("%d", &x);
			n++;
			s[n] = s[n - 1] ^ x;
			Trie.insert(Trie.root[n - 1], Trie.root[n], s[n]);
		}
		else {
			scanf("%d%d%d", &l, &r, &x);
			x ^= s[n];
			printf("%d\n", Trie.query(l, r, x));
		}
	}
	return 0;
}