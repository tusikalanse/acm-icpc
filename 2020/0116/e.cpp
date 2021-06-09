#include <bits/stdc++.h>
using namespace std;

const int N = 32e5 + 10, K = 2;

int nxt[N][K], root, tot;

int new_node() {
	memset(nxt[tot], 0, sizeof(nxt[tot]));
	return tot++;
}

void init() {
	tot = 0;
	root = new_node();
}

void insert(unsigned num) {
	int p = root;
	for (int i = 31; i >= 0; --i) {
		int x = (num >> i) & 1;
		if (nxt[p][x] == 0)
			nxt[p][x] = new_node();
		p = nxt[p][x];
	}
}

unsigned query(unsigned num) {
	int p = root;
	unsigned ans = 0;
	for (int i = 31; i >= 0; --i) {
		int x = (num >> i) & 1;
		if (nxt[p][x ^ 1] != 0) {
			x ^= 1;			
		}
		ans += (unsigned)x << i;
		p = nxt[p][x];
	}
	return ans;
}

int T, n, m, cas;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		init();
		printf("Case #%d:\n", ++cas);
		for (int i = 1; i <= n; ++i) {
			unsigned x;
			scanf("%u", &x);
			insert(x);
		}
		for (int i = 1; i <= m; ++i) {
			unsigned x;
			scanf("%u", &x);
			printf("%u\n", query(x));
		}
	}
	return 0;
}
