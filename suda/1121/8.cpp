#include <bits/stdc++.h>
using namespace std;

int n, k;
double a[10010];

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%lf", &a[i]);
	double l = 0, r = 1e6;
	for(int _ = 0; _ <= 1000; ++_) {
		double mid = (l + r) / 2;
		int cnt = 0;
		for(int i = 1; i <= n; ++i) 
			cnt += (int)(a[i] / mid);
		if(cnt >= k)
			l = mid;
		else
			r = mid;
	}
	printf("%.2f\n", (int)(l * 100) / 100.0);
	return 0;
}

