#include <bits/stdc++.h>
using namespace std;

char f[1 << 26];
int g[26], n, m, x, y, ans;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		g[x] |= 1 << y;
		g[y] |= 1 << x;
	}
	f[0] = 0;
	for(int i = 1; i < (1 << n); ++i) {
		int x = __builtin_ffs(i) - 1;
		f[i] = max((int)f[i ^ (1 << x)], 1 + f[(i ^ (1 << x)) - (i & g[x])]);
		ans += f[i];
	}
	printf("%d\n", ans);
	return 0;
}