#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

pair<double, int> a[N], t[N], b[N];
int n, x[N], y[N], a1, a2, b1, b2, t1, t2;
double ans, tmp;

int main() {
	scanf("%d%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &t1, &t2, &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		double dis = sqrt(1.0 * (t1 - x[i]) * (t1 - x[i]) + 1.0 * (t2 - y[i]) * (t2 - y[i]));
		t[i] = make_pair(2 * dis, i);
		a[i] = make_pair(sqrt(1.0 * (a1 - x[i]) * (a1 - x[i]) + 1.0 * (a2 - y[i]) * (a2 - y[i])) - dis, i);
		b[i] = make_pair(sqrt(1.0 * (b1 - x[i]) * (b1 - x[i]) + 1.0 * (b2 - y[i]) * (b2 - y[i])) - dis, i);
		ans += t[i].first;
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	tmp = min(a[1].first, b[1].first);
	if(a[1].second != b[1].second)
		tmp = min(tmp, a[1].first + b[1].first);
	else {
		tmp = min(tmp, min(a[1].first + b[2].first, a[2].first + b[1].first));
	}
 	printf("%.15f\n", ans + tmp);
	return 0;
}