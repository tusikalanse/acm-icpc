#include <bits/stdc++.h>
using namespace std;

const int N = 6010;
int T, n, a[N], id1, id2, cnt[12], mx, last;
unsigned long long ans, pre[100];

int foo(int x) {
	int len = 0;
	while(x) {
		len++;
		x /= 10;
	}
	return len;
}

int main() {
	int cas = 0;
	pre[0] = 1;
	for(int i = 1; i <= 10; ++i)
		pre[i] = 10 * pre[i - 1];
	scanf("%d", &T);
	while(T--) {
		printf("Case #%d: ", ++cas);
		scanf("%d", &n);
		ans = 0;
		for(int i = 1; i <= n; ++i) 
			scanf("%d", &a[i]);
		for(int i = 1; i < n; ++i) 
			for(int j = i + 1; j <= n; ++j) {
				unsigned long long tmp = 1ULL* a[i] * pre[foo(a[j])] + a[j];
				ans = max(ans, tmp);
			}
		printf("%llu\n", ans);
	}
	return 0;
}
