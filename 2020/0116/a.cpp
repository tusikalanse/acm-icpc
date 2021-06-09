#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10, K = 26;

int nxt[N][K], root, tot, cnt[N];

int new_node() {
	memset(nxt[tot], 0, sizeof(nxt[tot]));
	cnt[tot] = 0;
	return tot++;
}

void init() {
	tot = 0;
	root = new_node();
}

void insert(char s[]) {
	int p = root;
	for (int i = 0; s[i]; ++i) {
		int x = s[i] - 'a';
		if (nxt[p][x] == 0)
			nxt[p][x] = new_node();
		p = nxt[p][x];
		cnt[p]++;
	}
}

int query(char s[]) {
	int p = root;
	for (int i = 0; s[i]; ++i) {
		int x = s[i] - 'a';
		if (nxt[p][x] == 0)
			return 0;
		p = nxt[p][x];
	}
	return cnt[p];
}

char s[N];

int main() {
	init();
	while (gets(s), strcmp(s, "")) insert(s);
	while (gets(s)) printf("%d\n", query(s));
	return 0;
}
