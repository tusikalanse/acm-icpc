#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, cnt = 0, flag = 0;
	scanf("%d %d", &n, &k);
	clock_t st = clock();
	srand(time(NULL));
	int dp[5][105], dp2[5][105];
	for(int i = 1; i <= n; ++i) {
		dp[1][i] = dp2[4][i] = 1;
	}
	for(int i = 1; i <= 4; ++i)
		dp[i][1] = dp2[i][1] = 1;
	vector<int> fuck;
	fuck.resize((n-2)*2);
	for(int i = 0; i < k; ++i)
		fuck[i] = 1;
	for(int i = k; i < fuck.size(); ++i)
		fuck[i] = 0;
	random_shuffle(fuck.begin(), fuck.end());
	while((double)(clock() - st)/CLOCKS_PER_SEC < 0.9) {
		random_shuffle(fuck.begin(), fuck.end());
		for(int i = 1; i <= n; ++i) {
			dp[1][i] = dp2[4][i] = 1;
		}
		for(int i = 1; i <= 4; ++i)
			dp[i][1] = dp2[i][1] = 1;
		for(int i = 2; i <= 4; ++i)
			for(int j = 1; j <= n; ++j) {
				if(i != 4 && fuck[j-2] == 1)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		for(int i = 3; i >= 1; --i)
			for(int j = 1; j <= n; ++j) {
				if(i != 1 && fuck[n+j-2] == 1)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i+1][j] + dp[i][j-1];
			}
		if(dp[4][n] != dp2[1][n])
			continue;
		else {
			puts("YES");
			for(int i = 0; i < n; i++)
				putchar('.');
			puts("");
			for(int i = 0; i < n; i++) {
				if(fuck[i] == 1)
					putchar('#');
				else
					putchar('.');
			}
			puts("");
			for(int i = 0; i < n; i++) {
				if(fuck[n+i] == 1)
					putchar('#');
				else
					putchar('.');
			}
			puts("");
			for(int i = 0; i < n; i++)
				putchar('.');
			puts("");
		}
		return 0;
	}
	puts("NO");
	return 0;
}