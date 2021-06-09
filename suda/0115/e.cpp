#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[100006][12];


int main(){
	int n;
	int loc, t;
	while(~scanf("%d", &n) && n){
		int m = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i<=n; i++){
			scanf("%d %d", &loc, &t);
			dp[t][loc]++;
			m = max(m, t);			
		}
		for(int i = m - 1; i>=0; i--){
			dp[i][0] = max(dp[i+1][0], dp[i+1][1]) + dp[i][0];
			for(int j = 1; j < 10; j++)
			dp[i][j] = max(max(dp[i+1][j-1], dp[i+1][j]), dp[i+1][j+1]) + dp[i][j];
			dp[i][10] = max(dp[i+1][10], dp[i+1][9]) + dp[i][10];
		}
		printf("%d\n", dp[0][5]);
	}	
	return 0;
}
