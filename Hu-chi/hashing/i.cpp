#include <bits/stdc++.h>
using namespace std;

const int mod1 = 1e9 + 7, mod2 = 1e9 + 9, seed = 257;
int hsf[5000010], hsg[5000010], n;
int rev_hsf[5000010], rev_hsg[5000010];
int f[5000010], g[5000010];
char s[5000010], rev_s[5000010];
int vis[5000010];
int res[5000010];

void init() {
	f[0] = g[0] = 1;
	for(register int i = 1; i <= n; ++i) {
		f[i] = 1LL * f[i - 1] * seed % mod1;
		g[i] = 1LL * g[i - 1] * seed % mod2;
	}
}

void pre() {
	hsf[0] = hsg[0] = rev_hsf[n + 1] = rev_hsg[n + 1] = 0;
	for(register int i = 1; i <= n; ++i) {
		hsf[i] = (1LL * hsf[i - 1] * seed + s[i]) % mod1;
		hsg[i] = (1LL * hsg[i - 1] * seed + s[i]) % mod2;
	}
	for(register int i = n; i > 0; --i) {
		rev_hsf[i] = (1LL * rev_hsf[i + 1] * seed + s[i]) % mod1;
		rev_hsg[i] = (1LL * rev_hsg[i + 1] * seed + s[i]) % mod2;
	}
}

bool check(int i) {
	if(vis[i] != -1) {
		return vis[i];
	}
	int f1 = hsf[i], g1 = hsg[i];
	int f2 = ((rev_hsf[1] - 1LL * rev_hsf[1 + i] * f[i]) % mod1 + mod1) % mod1;
	int g2 = ((rev_hsg[1] - 1LL * rev_hsg[1 + i] * g[i]) % mod2 + mod2) % mod2;
	return vis[i] = f1 == f2 && g1 == g2;
}

int main() {
	long long ans = 0;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	init();
	pre();
	memset(vis, -1, (n + 2) * sizeof(int));
	for(register int i = 1; i <= n; ++i) {
		if(check(i)) {
			res[i] = res[i >> 1] + 1;
			ans += res[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}