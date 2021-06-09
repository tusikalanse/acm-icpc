#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e5 + 10;

int T, n, l, r;
LL a[N], ans[N], tmp;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		a[1] = 0;
		for (int i = 2; i <= n; ++i) {
			scanf("%lld", &a[i]);
			a[i] += a[i - 1];
		}
		ans[1] = 0;
		ans[2] = a[n] - a[1];
		l = 1, r = n;
		tmp = ans[2];
		for (int i = 3; i <= n; i += 2) {
			l++, r--;
			ans[i] = tmp + ans[i - 1];
			if (i + 1 <= n) 
				ans[i + 1] = ans[i] + a[r] - a[l] + tmp;
			tmp += a[r] - a[l];
		}
		for (int i = 1; i <= n; ++i)
			printf("%lld%c", ans[i], " \n"[i == n]);
	}
	return 0;
}