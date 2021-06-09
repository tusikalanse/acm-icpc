#include <bits/stdc++.h>
using namespace std;

long double comp(int n, int m) {
	if(m == 0)
		return 1;
	long double ans = 1;
	for(int i = 0; i < m; ++i) {
		ans *= n - i;
		ans /= i + 1;
	}
	return ans;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	long double div = comp(n * m, n) * n;
	long double ans = 0;
	if(m == 1) {
		ans = 1;
	}
	else {
		for(int i = 1; i <= min(n, m); ++i)
			ans += comp(m, i) * comp(n * m - m, n - i) * i * i;
	}
	ans /= div;
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}