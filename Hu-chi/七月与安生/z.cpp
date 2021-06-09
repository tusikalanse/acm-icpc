#include <bits/stdc++.h>
using namespace std;

double dp[105][100005]; //dp[i][j] : considering contest 1~i, the expectation of the number of person who's sum rank equals j
double sum[105][100005]; // sum[i][j] = sigma(dp[i][0] ~ dp[i][j - 1])
int a[105], n, m, tot = 0;

int main() {
	cin >> n >> m;
	if(m == 1)
		return 0 * puts("1");
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		tot += a[i];
	}
	dp[0][0] = m - 1;
	for(int i = 1; i <= n * m; ++i)
		sum[0][i] = m - 1;
	for(int i = 1; i <= n; ++i) {
        sum[i][0]=0;
        sum[i][1]=0;
        for(int j = 1; j <= n * m; ++j) {
            int r = j, l = max(0, j - m);
            dp[i][j] += (sum[i - 1][r] - sum[i - 1][l]) * 1.0 / (m - 1);
            if(j - a[i] >= 0)
                dp[i][j] -= dp[i - 1][j - a[i]] / (m - 1);
                sum[i][j + 1] = sum[i][j] + dp[i][j];
            }
        }
    printf("%.12f\n", 1 + sum[n][tot]);
	return 0;
}