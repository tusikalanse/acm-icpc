#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, a[N], ans[N * 5], t, mx = 0, sum[N];

int check(int left, int limit) {
	int l = left, r = n, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (sum[mid] - sum[left - 1] <= limit) {
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return ans;
}

int gao(int lim) {
	int ans = 0;
	for (int l = 1, r = 0; l <= n; l = r + 1) {
		r = check(l, lim);
		ans++;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i < mx; ++i) ans[i] = -1;
	for (int i = mx; i <= 1000000; ++i) ans[i] = gao(i);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &t);
		if (ans[t] == -1)
			puts("Impossible");
		else
			printf("%d\n", ans[t]);
	}
	return 0;
}