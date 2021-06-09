#include <bits/stdc++.h>
using namespace std;

unsigned seed = 13331;
const int MAXN = 2e5 + 10;
unsigned long long hs1, hs2, hs[27][MAXN], f[MAXN], vis[27];
int nxt[27][MAXN], ans[MAXN], cnt = 0, n, m;
char s1[MAXN], s2[MAXN];

int main() {
	scanf("%d%d%s%s", &n, &m, s1 + 1, s2 + 1);
	f[0] = 1;
	for(int i = 1; i <= n; ++i)
		f[i] = f[i - 1] * seed;
	for(int i = 1; i <= m; ++i) 
		hs2 = hs2 * seed + s2[i] - 'a' + 1;
	for(int i = 'a'; i <= 'z'; ++i) 
		for(int j = 1; j <= n; ++j)
			hs[i - 'a' + 1][j] = hs[i - 'a' + 1][j - 1] * seed + (s1[j] == i);
	for(int i = 1; i <= 26; ++i)
		nxt[i][n + 1] = n + 1;
	for(int i = 1; i <= 26; ++i)
		for(int j = n; j > 0; --j) {
			nxt[i][j] = s1[j] == 'a' + i - 1 ? j : nxt[i][j + 1];
		}
	for(int i = 1; i <= n - m + 1; ++i) {
		hs1 = 0; 
		memset(vis, 0, sizeof(vis));
		for(int j = 1; j <= 26; ++j) if(nxt[j][i] <= i + m - 1) {
			unsigned p = s2[nxt[j][i] - i + 1] - 'a' + 1;
			if(!vis[p] && !vis[j])
				vis[p] = j, vis[j] = p;
			hs1 += vis[j] * (hs[j][i + m - 1] - hs[j][i - 1] * f[m]);
		}
		if(hs1 == hs2)
			ans[++cnt] = i;
	}
	printf("%d\n", cnt);
	for(int i = 1; i <= cnt; ++i)
		printf("%d%c", ans[i], " \n"[i == cnt]);
	return 0;
}