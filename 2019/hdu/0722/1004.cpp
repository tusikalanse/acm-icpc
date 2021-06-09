#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int l[N], s[N], v[N], n;

double le, ri;

bool check(double x) {
	double pos = x * v[n] - l[n] - s[n];
	for(int i = n - 1; ~i; --i) {
		double tmp = x * v[i] - l[i] - s[i];
		pos = min(tmp, pos - l[i]);
	}
	return pos + l[0] > 0;
}

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 0; i <= n; ++i) 
			scanf("%d", &l[i]);
		for(int i = 0; i <= n; ++i) 
			scanf("%d", &s[i]);
		for(int i = 0; i <= n; ++i) 
			scanf("%d", &v[i]);
		le = 0, ri = 1e9;
		for(int i = 0; i <= 100; ++i) {
			double mid = (le + ri) / 2;
			if(check(mid))
				ri = mid;
			else
				le = mid;
		}
		printf("%.15f\n", le);
	}
	return 0;
}