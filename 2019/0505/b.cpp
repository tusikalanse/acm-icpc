#include <bits/stdc++.h>
using namespace std;

int n, a;

long long get(int x, int num) {
	if(num >= 2 * x)
		return num;
	long long t = 0;
	t += num - x;
	t += num - x;
	x = 2 * x - num;
	t += 1LL * a * (1LL * (x / a) * (1 + x / a) / 2) + 1LL * (x - 1LL * x / a * a) * ((x - 1) / a + 1);
	return t;
}

bool check(int x) {
	if(a == 0) {
		return (n) / 2 >= x;
	}
	int l = x, r = 2 * x;
	long long ans = 2 * x;
	while(l <= r) {
		int cl = l + (r - l) / 3, cr = r - (r - l) / 3;
		long long tl = get(x, cl), tr = get(x, cr);
		if(tl <= tr) {
			ans = min(ans, tl);
			r = cr - 1;
		}
		else {
			ans = min(ans, tr);
			l = cl + 1;
		}
	}
	return ans <= n;
}

int main() {
	while(~scanf("%d%d", &n, &a)) {
		int l = 0, r = n, ans = 0;
		while(l <= r) {
			int mid = l + r >> 1;
			if(check(mid)) {
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}