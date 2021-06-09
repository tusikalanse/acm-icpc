#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int nxt[1010];
int pos[102][1010], n, m;
char s[MAXN], w[102][1010];

void getnext(int id) {
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int j = 0, k = -1;
	while(w[id][j]) {
		if(k == -1 || w[id][j] == w[id][k])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

void kmp() {
	memset(pos, -1, sizeof(pos));
	for(int id = 0; id < m; ++id) {
		getnext(id);
		int i = 0, j = 0, len = strlen(w[id]);
		while(s[i]) {
			if(j == -1)
				++i, ++j;
			else if(s[i] == w[id][j]) {
				if(pos[id][j] == -1)
					pos[id][j] = i;
				++i, ++j;
			}
			else {
				j = nxt[j];
			}
			if(j == len)
				break;
		}
	}
}

void solve() {
	int ans = 0;
	reverse(s, s + n);
	for(int i = 0; i < m; ++i)
		reverse(w[i], w[i] + strlen(w[i]));
	for(int id = 0; id < m; ++id) {
		getnext(id);
		int i = 0, j = 0, len = strlen(w[id]);
		bool flag = 0;
		while(s[i]) {
			if(j == -1)
				++i, ++j;
			else if(s[i] == w[id][j]) {
				if(len - 2 - j >= 0) {
					if(~pos[id][len - 2 - j])
						flag |= i + 2 + pos[id][len - 2 - j] <= n;
				}
				++i, ++j;
			}
			else
				j = nxt[j];
			if(j == len)
				j = nxt[j];
		}
		ans += flag;
	}
	printf("%d\n", ans);
}

int main() {
	scanf("%s%d", s, &m);
	n = strlen(s);
	for(int i = 0; i < m; ++i)
		scanf("%s", w[i]);
	kmp();
	solve();
	return 0;
}