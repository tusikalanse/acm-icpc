#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], mx, n, ans, l;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	for(int i = 1; i <= n; ++i) {
		if(mx == a[i]) {
			l++;
		}
		else 
			l = 0;
		ans = max(ans, l);
	}
	printf("%d\n", ans);
	return 0;
}