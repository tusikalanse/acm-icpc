#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[10005], p[10005], w[10005];

int main() {
	int t, n, e, f, wei;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &e, &f, &n);
		for(int i = 0; i < n; i++) 
			scanf("%d %d", &p[i], &w[i]);
		memset(dp, 0x3f, sizeof(dp));
		wei = f - e;
		dp[0] = 0;
		for(int i = 0; i < n; i++) {
			for(int j = w[i]; j <= wei; j++) {
				dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
			}
		}
		if(dp[wei] == 0x3f3f3f3f) 
			puts("This is impossible.");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[wei]);
	}
	return 0;
}