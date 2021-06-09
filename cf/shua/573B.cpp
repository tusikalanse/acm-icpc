#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], r[N], l[N], ans, n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) 
		l[i] = min(a[i], l[i - 1] + 1);
	for(int i = n; i; --i)
		r[i] = min(a[i], r[i + 1] + 1);
	for(int i = 1; i <= n; ++i)
		ans = max(ans, min(l[i], r[i]));
	printf("%d\n", ans);

	return 0;
}