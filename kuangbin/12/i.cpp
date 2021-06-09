#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[30001], a[30001];

int main() {
	int n;
	while(~scanf("%d", &n)) {
		int mmax = 1;
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++)
			dp[i] = 1;
		for(int i = 2; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				if(a[i] > a[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			mmax = max(mmax, dp[i]);
		}
		printf("%d\n", mmax);
	}
	return 0;
}