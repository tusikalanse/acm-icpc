#include <bits/stdc++.h>
using namespace std;

char s[100010][1010], w[10010];
int nxt[1000010][26], End[1000010], vis[10010];
int L, root, n, cnt;

int newnode() {
	for(int i = 0; i < 26; ++i)
		nxt[L][i] = -1;
	End[L] = -1;
	return L++;
}

bool dfs(int pos) {
	if(pos == -1)
		return true;
	if(vis[pos] != -1)
		return vis[pos];
	int p = root;
	for(int i = pos; i >= 0; --i) {
		int t = w[i] - 'a';
		if(nxt[p][t] == -1)
			break;
		p = nxt[p][t];
		if(End[p] != -1 && dfs(i - 1)) {
			printf("%s ", s[End[p]]);
			return vis[i] = true;
		}
	}
	return vis[pos] = false;
}

int main() {
	L = 0;
	root = newnode();
	memset(vis, -1, sizeof(vis));
	scanf("%d %s %d", &n, w, &cnt);
	for(int i = 0; i < cnt; ++i) {
		int p = root;
		scanf("%s", s[i]);
		for(int j = 0; s[i][j]; ++j) {
			int t = s[i][j] >= 'a' ? s[i][j] - 'a' : s[i][j] - 'A';
			if(nxt[p][t] == -1)
				nxt[p][t] = newnode();
			p = nxt[p][t];
		}
		End[p] = i;
	}
	dfs(n - 1);
	puts("");
	return 0;
}