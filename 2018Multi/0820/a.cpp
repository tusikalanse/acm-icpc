#include <bits/stdc++.h>
using namespace std;

int T, n, m, ans, mod;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &mod);
		ans = 1;
		for(int i = 1; i <= n; ++i)
			ans = 1LL * ans * i % mod;
		for(int i = 1; i <= m; ++i) 
			ans = 1LL * ans * i % mod;
		for(int i = n + m; i <= n * m; ++i) 
			ans = 1LL * ans * i % mod;
		printf("%d\n", ans);
	}
	return 0;
}