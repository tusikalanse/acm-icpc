#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int dp[110][110], a[110];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i + 2 <= n; ++i) {
		dp[i][i + 2] = a[i] * a[i + 1] * a[i + 2]; 
	}
	for(int len = 4; len <= n; ++len) {
		for(int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			dp[i][j] = dp[i + 1][j] + a[i] * a[i+1] * a[j];
			//dp[i][j] = min(dp[i][j], dp[i][j-1] + a[i]*a[j-1]*a[j]);
			for(int k = i + 1; k < j; ++k) {
			 	dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[i]*a[k]*a[j]);
			}
		}
	}
	printf("%d\n", dp[1][n]);
	return 0;
}