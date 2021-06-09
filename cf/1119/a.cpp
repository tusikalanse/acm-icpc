#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int n, c[N], ans;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	for(int i = n; i > 1; --i) {
		if(c[i] != c[1]) {
			ans = max(ans, i - 1);
			break;
		}
	}
	for(int i = 1; i < n; ++i) {
		if(c[i] != c[n]) {
			ans = max(ans, n - i);
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}