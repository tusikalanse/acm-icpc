#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int mx[2][N], mn[2][N], f[N], n;

struct p {
	int x, y;
	bool operator<(const p &rhs) const {
		return x < rhs.x;
	}
}points[N];

bool check(long long mid) {
	if(points[1].x == 0 && points[1].y > mid)
		return 0;
	int v1 = 0, v2 = 0;
	for(int i = 1; i <= n; ++i) {
		if(points[i].y <= mid)
			v1 = i;
		else
			break;
	}
	if(v1 >= n - 1)
		return 1;
	v2 = v1 + 1;
	mx[0][v2] = mn[0][v2] = points[v2].y;
	mx[1][n] = mn[1][n] = points[n].y;
	for(int i = v2 + 1; i <= n; ++i) {
		mx[0][i] = max(mx[0][i - 1], points[i].y);
		mn[0][i] = min(mn[0][i - 1], points[i].y);
	}
	for(int i = n - 1; i >= v2; --i) {
		mx[1][i] = max(mx[1][i + 1], points[i].y);
		mn[1][i] = min(mn[1][i + 1], points[i].y);
	}
	for(int i = v1 + 1; i < n; ++i) {
		if(mx[0][i] - 2 * mid > mn[0][i]) continue;
		if(mx[1][i + 1] - 2 * mid > mn[1][i + 1]) continue;
		if(mx[0][i] - mid > mid + mn[1][i + 1]) continue;
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &points[i].x, &points[i].y);
		points[i].y *= 2;
	}
	sort(points + 1, points + n + 1);
	long long l = 0, r = 2000000000, ans = 2000000000;
	while(l <= r) {
		long long mid = (l + r) >> 1;
		if(check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	printf("%.1f\n", ans / 2.0);
	return 0;
}