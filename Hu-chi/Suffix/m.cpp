#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int dp[N][N];

int n, k;
char s[N];

struct Trie {
	int L, root, cnt;
	int nxt[N * N][2], num[N * N], fa[N * N];
	bool has;
	void init() {
		L = 0;
		root = newnode();
		fa[root] = 0;
	}
	int newnode() {
		nxt[L][0] = nxt[L][1] = -1;
		num[L] = 0;
		return L++;
	}
	void insert(int st) {
		int p = root;
		for(int i = st; s[i]; ++i) {
			if(nxt[p][s[i] - 'a'] == -1) {
				nxt[p][s[i] - 'a'] = newnode();
				fa[nxt[p][s[i] - 'a']] = p;
			}
			p = nxt[p][s[i] - 'a'];
			if(dp[st][i])
				num[p]++;
		}
	}
	void find(int p) {
		if(has)
			return;
		if(num[p] < k) { 
			k -= num[p];
			for(int i = 0; i < 2; ++i) 
				if(nxt[p][i] != -1)
					find(nxt[p][i]);
		}
		else {
			print(p);
			puts("");
			exit(0);
		}
	}
	void print(int p) {
		if(fa[p] != root)
			print(fa[p]);
		putchar('a' + (nxt[fa[p]][1] == p));
	}
}AC;

int main() {
	scanf("%s%d", s, &k);
	AC.init();
	n = strlen(s);
	for(int i = 0; i < n; ++i) {
		dp[i][i] = 1;
		if(i + 1 < n && s[i] == s[i + 1]) dp[i][i + 1] = 1;
		if(i + 2 < n && s[i] == s[i + 2]) dp[i][i + 2] = 1;
		if(i + 3 < n && s[i] == s[i + 3]) dp[i][i + 3] = 1;
	}
	for(int len = 5; len <= n; ++len) {
		int j;
		for(int i = 0; (j = i + len - 1) < n; ++i) {
			if(s[i] == s[j] && dp[i + 2][j - 2])
				dp[i][j] = 1;
		}
	}
	for(int i = 0; i < n; ++i) 
		AC.insert(i);
	AC.find(0);
	return 0;
}