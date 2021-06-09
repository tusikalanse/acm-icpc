#include <bits/stdc++.h>
using namespace std;

int n, h;
int a[1010], b[1010], l, r, ans;

bool check(int n) {
	memcpy(b, a, sizeof(b));
	sort(b + 1, b + n + 1, [](int i, int j) {return i > j;});
	long long cnt = 0;
	for(int i = 1; i <= n; i += 2)
		cnt += b[i];
	return cnt <= h;
}

int main() {
	scanf("%d%d", &n, &h);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	l = 0, r = n;
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
	return 0;
}