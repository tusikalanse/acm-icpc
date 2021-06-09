#include <bits/stdc++.h>
using namespace std;

double a[10010];

int main() {
	int n, T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%lf", &a[i]);
		}
		sort(a, a + n);
		double ans = a[n - 1], mul = 1 - ans, now = ans;
		for(int i = n - 2; i >= 0; --i) {
			now = ans * (1 - a[i]) + a[i] * mul;
			if(now < ans)
				break;
			ans = now;
			mul *= (1 - a[i]);
		} 
		printf("%.15f\n", ans);
	}
	return 0;
}