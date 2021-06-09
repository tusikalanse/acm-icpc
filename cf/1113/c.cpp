#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int cnt[2][1 << 20];
int a[N], now, n;
long long ans;


int main() {
	cnt[0][0] = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		now ^= a[i];
		ans += cnt[i & 1][now];
		cnt[i & 1][now]++;
	}
	printf("%lld\n", ans);
	return 0;
}