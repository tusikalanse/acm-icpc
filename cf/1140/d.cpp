#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
int main() {
	scanf("%d", &n);
	for(int i = 2; i + 1 <= n; ++i)
		ans += i * (i + 1);
	printf("%lld\n", ans);
	return 0;
}