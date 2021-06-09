#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

const int BIT = 20;
const int MAXN = (1 << BIT) + 10;

int dp[MAXN][2], n, T, x;
long long ans;

int main() {
	scanf("%d", &T);
	while(T--) {
		ans = 0;
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &x);
			if(dp[x][0]) 
				dp[x][1] = x;
			else 
				dp[x][0] = x;
		}
		for(int i = 0; i < BIT; ++i) {
			for(int j = 0; j < (1 << BIT); ++j) {
				if(!((1 << i) & j)) {
					dp[j][1] = max(dp[j][1], dp[j ^ (1 << i)][1]);
					if(dp[j][1] > dp[j][0])
						swap(dp[j][1], dp[j][0]);
					dp[j][1] = max(dp[j][1], dp[j ^ (1 << i)][0]);
					if(dp[j][1] > dp[j][0])
						swap(dp[j][1], dp[j][0]);
				}
			}
		}
		for(int i = 0; i < MAXN; ++i)
			ans = max(ans, 1LL * dp[i][0] * dp[i][1] * i);
		printf("%lld\n", ans);
	}


	return 0;
}