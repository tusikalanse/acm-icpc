#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 5e5 + 10, mod = 1e9;
int a[MAXN], sum[35][MAXN];


int main() {
	int T, n, m, p;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= 32; ++i) {
			for(int j = 1; j <= n; ++j)
				sum[i][j] = (sum[i][j - 1] + a[j]/i) % mod;
		}
		long long res = 0, ans;
		int st, ed;
		for(int t = 1; t <= m; ++t) {
			ans = 0;
			scanf("%d", &p);
			for(int i = 1; i; ++i) {
				st = upper_bound(a + 1, a + n + 1, pow(p, 0LL + i - 1)) - a;
				if(st > n)
					break;
				ed = upper_bound(a + 1, a + n + 1, pow(p, 0LL + i)) - a;
				ans = (ans + sum[i][ed-1] - sum[i][st-1]) % mod;
			}
			res = (res + ans * t) % mod;
		}
		printf("%lld\n", (res + mod) % mod);
	}
	return 0;
}