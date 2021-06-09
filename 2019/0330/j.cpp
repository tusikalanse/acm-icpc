#include <bits/stdc++.h>
using namespace std;

typedef long double db;
int low, high;
const db eps = 1e-15;

db sqrt3(db x) {
	db l = 1, r = x, mid;
	for(int i = 1; i <= 100; ++i) {
		mid = (l + r) / 2;
		if(mid * mid * mid > x)
			r = mid;
		else
			l = mid;
	}
	return l;
}

db calc(db x) {
	return sqrt3(x + eps) - sqrt3(x);
}

int main() {
	while(~scanf("%d%d", &low, &high) && low) {
		db ans = 0;
		for(int i = low; i <= high; ++i) {
			ans += calc(i);
		}
		printf("%.5E\n", (double)ans);
	}
	return 0;
}