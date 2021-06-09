#include <bits/stdc++.h>
using namespace std;

double prob[100010];

int main() {
	int n, p, l, r;
	cin >> n >> p;
	for(int i = 1; i <= n; ++i) {
		cin >> l >> r;
		prob[i] = (double)(r/p - (l - 1)/p) / (r - l + 1);
	}
	double ans = 0;
	for(int i = 1; i < n; ++i)
		ans += 1 - (1 - prob[i]) * (1 - prob[i + 1]);
	ans += 1 - (1 - prob[1]) * (1 - prob[n]);
	ans *= 2000;
	printf("%.10lf\n", ans);

	return 0;
}