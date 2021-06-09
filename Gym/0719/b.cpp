#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL dp[4100][13];
int a[13], mmax = 0, n;

int remain(int a) {
	int c = __builtin_popcount(a);
	return c * mmax + c * (c + 1) / 2;
}

int sum(int c) {
	int res = 0;
	for(int i = 0; i < n; ++i) {
		if((1 << i) & c)
			res += a[i];
	}
	return res;
}

int main() {
	int tot, id = 0;
	scanf("%d %d", &n, &tot);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if(a[i] > mmax) {
			mmax = a[i];
			id = i;
		}
	}
	dp[0][id] = 1;
	for(int i = 0; i < n; ++i)
		if(i != id && tot > (a[id] - a[i]))
			dp[1 << i][i] = 1;
	dp[1 << id][id] = 0;
	for(int p = 1; p < (1 << n); ++p) {
		if(sum(p) > tot)
			continue;
		for(int i = 0; i < n; ++i) {
			if((1 << i) & p)
				continue;
			int c = p | (1 << i);
			if(remain(c) - sum(c) < tot)
				for(int j = 0; j < n; ++j)
					if((1 << j) & p)
						dp[c][i] += dp[p][j];
		}
	}
	LL ans = 0;
	for(int i = 0; i < n; ++i)
		ans += dp[(1 << n) - 1][i];
	printf("%lld\n", ans);
	return 0;
}