#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int dp[105][105], d[105], n, s[105];
int main(){
	scanf("%d", &n);
	memset(dp, 0x3f, sizeof(dp));
	memset(s, 0, sizeof(s));
	for(int i = 1; i<=n; i++){
		scanf("%d", &d[i]);
		s[i] = s[i-1] + d[i];
		dp[i][i] = 0;
	}
	for(int l = 1; l<=n; l++)
		for(int i = 1; i+l<=n; i++){
			for(int k = i; k+1<=i+l; k++){
			//	printf("%d %d\n", dp[i][i+l], dp[i][k] + dp[k][i+l] + s[i+l] - s[i-1]);
				dp[i][i+l] = min(dp[i][i+l], dp[i][k] + dp[k+1][i+l] + s[i+l] - s[i-1]);
			}
		}
	printf("%d\n", dp[1][n]);
	return 0;
}