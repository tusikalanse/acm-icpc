#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, m, a[1010], b[1010];
double l, r, mid, ans;

bool check(double fuel) {
	for(int i = 1; i < n; ++i) {
		fuel -= (m + fuel) / a[i];
		if(fuel < 0) return 0;
		fuel -= (m + fuel) / b[i + 1];
		if(fuel < 0) return 0;
	}
	fuel -= (m + fuel) / a[n];
	if(fuel < 0) return 0;
	fuel -= (m + fuel) / b[1];
	if(fuel < 0) return 0;
	return 1;
}


int main() {
	cin >> n >> m;
	bool flag = 0;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	l = 0, r = 1e9 + 1;
	for(int i = 1; i <= 1000; ++i) {
		mid = (l + r) / 2;
		if(check(mid)) {
			flag = 1;
			ans = mid;
			r = mid;
		}
		else
			l = mid;
	}
	if(flag)
		printf("%.10f\n", ans);
	else
		cout << -1 << endl;
	return 0;
}