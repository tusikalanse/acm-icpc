#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int a[N], T, n;
long long ans;

int main() {
	scanf("%d", &T);
	while(T--) {
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) 
			scanf("%d", &a[i]);
		for(int i = 1; i <= n; ++i) {
			int l = i, r = i;
			long long sum = 0;
			while(l > 1 && sum + a[l - 1] < a[i]) l--, sum += a[l];
			while(r < n && sum + a[r + 1] < a[i]) r++, sum += a[r];
			ans += r - i + 1;
			for(int j = l; j < i; ++j) {
				sum -= a[j];
				while(r < n && sum + a[r + 1] < a[i]) r++, sum += a[r];
				ans += r - i + 1;
			} 
		}
		printf("%lld\n", 1LL * n * (n + 1) / 2- ans);
	}
	return 0;
}