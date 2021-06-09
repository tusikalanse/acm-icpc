#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1000006], f[1000006], a[1000006];

int main(){
	int n, m;
	while(~scanf("%d %d", &m, &n)){
		memset(dp, 0, sizeof(dp));
		memset(f, 0, sizeof(f));
		for(int i = 1; i<=n; i++)
			scanf("%d", &a[i]);
		int now = 0;
		for(int j = 1; j<=m; j++){
			now = -1e9;
			for(int i = j; i<=n; i++){
				dp[i] = max(dp[i-1], f[i-1]) + a[i];
				f[i-1] = now;
				now = max(now, dp[i]);
			}
		}
		printf("%d\n", now);
	}
	return 0;
}
