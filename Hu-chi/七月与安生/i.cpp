#include <bits/stdc++.h>
using namespace std;

int n, m, h, sum = 0;
int a[1010];

double comp(int n, int m) {
	double ans = 1;
	for(int i = 0; i < m; ++i) {
		ans *= n - i;
		ans /= i + 1;
	}
	return ans;
}


int main() {
	double ans = 1;
	cin >> n >> m >> h;
	h--;
	for(int i = 0; i < m; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	if(sum < n)
		return 0 * printf("-1\n");
	if(a[h] == 1)
		return 0 * printf("0\n");
	if(sum - a[h] < n - 1)
		return 0 * printf("1\n");
	ans = comp(sum - a[h], n - 1) / comp(sum - 1, n - 1);
	ans = 1 - ans;
	printf("%.10f\n", ans);
	return 0;
}