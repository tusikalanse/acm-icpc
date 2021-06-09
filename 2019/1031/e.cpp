#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, L, R, K;
int a[N], b[N];
long long val[N], mn[N];

int check(int l, int r, int pos) {
	int mid, ans = -1;
	while (l <= r) {
		mid = l + r >> 1;
		if (mid - val[pos] + mn[pos] >= L) {
			r = mid - 1;
			ans = mid;
		}
		else
			l = mid + 1;
	}
	return ans;
}

int main() {
	scanf("%d%d%d%d", &n, &L, &R, &K);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	val[1] = 0;
	for (int i = 2; i <= n; ++i) {
		if (a[i] == a[i - 1])
			val[i] = val[i - 1];
		else if (a[i] > a[i - 1])
			val[i] = val[i - 1] + K;
		else
			val[i] = val[i - 1] - 1;
	}
	mn[n + 1] = 1e18;
	for (int i = n; i; --i)
		mn[i] = min(val[i], mn[i + 1]);
	for (int i = 1; i <= n; ++i) {
		int l = L, r = R;
		if (i != 1) {
			l = max(l, b[i - 1] - K);
			r = min(r, b[i - 1] + K);
			if (a[i] == a[i - 1]) l = r = b[i - 1];
			else if (a[i] > a[i - 1]) l = b[i - 1] + 1;
			else r = b[i - 1] - 1;
		}
		b[i] = check(l, r, i);
	}
	bool flag = 1;
	for (int i = 1; i <= n; ++i) {
		if (b[i] == -1 || b[i] > R || b[i] < L)
			flag = 0;
	}
	if (flag == 0) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", b[i]);
	printf("\n");
	return 0;
}