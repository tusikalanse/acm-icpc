#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, k, ans;
long long a[N];


int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) 
		scanf("%lld", &a[i]);
	for(int i = 2; i <= n; ++i) {
		if(abs(a[i] - a[i - 1]) < k) {
			ans++;
			a[i] = 1e18;
		}
	}
	printf("%d\n", ans);
	return 0;
}