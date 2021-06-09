#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
	LL n, m;
	cin >> n >> m;
	LL dx = 0, x, sum = 0, t;
	LL mmax = n * (n - 1) / 2, mmin = 0;
	for(int i = 1; i <= n; ++i)
		mmin += abs((n+1)/2 - i);
	while(m--) {
		cin >> x >> t;
		dx += x;
		if(t > 0)
			sum += t * mmax;
		if(t < 0)
			sum += t * mmin;
	}
	printf("%.15lf\n", dx + (double)sum/n);
	return 0;
}