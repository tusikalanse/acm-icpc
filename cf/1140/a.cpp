#include <bits/stdc++.h>
using namespace std;

int ans, n, a, mx;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		mx = max(mx, a);
		ans += i == mx;
	}
	printf("%d\n", ans);
	return 0;
}