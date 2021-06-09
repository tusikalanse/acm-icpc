#include <bits/stdc++.h>
using namespace std;

double prob[2010][2010];

int main() {
	int n, t;
	double p, ans = 0;
	memset(prob, 0, sizeof(prob));
	cin >> n >> p >> t;
	prob[0][0] = 1;
	for(int i = 1; i <= t; ++i) {
		prob[i][0] = (1 - p) * prob[i - 1][0];
		for (int j = 1; j < n; ++j) {
			prob[i][j] = (1 - p) * prob[i - 1][j] + p * prob[i - 1][j - 1];
		}
		prob[i][n] = prob[i - 1][n] + p * prob[i - 1][n - 1];
	}
	for(int i = 1; i <= n; ++i)
		ans += i * prob[t][i];
	printf("%.15lf\n", ans);
	return 0;
}