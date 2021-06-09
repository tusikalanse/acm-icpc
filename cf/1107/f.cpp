#include <bits/stdc++.h>
using namespace std;
const int N = 520;
int n;
long long dp[N][N];

struct off {
	int a, b, k;
	bool operator<(const off &rhs) const {
		return b > rhs.b;
	}
}p[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].k);
	}
	sort(p + 1, p + n + 1);
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			dp[i][j] = dp[i - 1][j] + max(0LL, p[i].a - 1LL * p[i].b * p[i].k);
			if(j)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + p[i].a - 1LL * p[i].b * (j - 1));
		}
	}
	printf("%lld\n", *max_element(dp[n], dp[n] + n + 1));
	return 0;
}