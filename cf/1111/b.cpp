#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, k, a[N], num;
long long sum;
double ans, tmp;

int main() {
	scanf("%d%d%d", &n, &k, &m);
	num = n;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	ans = (sum + min(1LL * m, 1LL * k * n)) / (double)num;
	for(int i = 1; i < n; ++i) {
		num--;
		m--;
		sum -= a[i];
		ans = max(ans, (sum + min(1LL * m, 1LL * k * num)) / (double)num);
		if(m == 0)
			break;
	}
	printf("%.10f\n", ans);
	return 0;
}