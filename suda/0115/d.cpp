#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[20000];
int w[3500], v[3500];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i<=n; i++) scanf("%d %d", w+i, v+i);
		for (int i = 1; i<=n; i++){
			for(int j = m; j>=w[i]; j--){
				dp[j] = max(dp[j-w[i]] + v[i], dp[j]);
				//printf("%d\n", dp[c^1][j]);
				}			
		}
		int out = 0;
		for(int i = 0; i<=m; i++) out = max(out, dp[i]);
		printf("%d\n", out);		
	return 0;
}
