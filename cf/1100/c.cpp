#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)


int main() {
	int n;
	double r;
	scanf("%d%lf", &n, &r);
	double c = PI / n, s = sin(c);
	double L = 0, R = 1e100;
	for(int i = 1; i <= 1000; ++i) {
		double mid = (L + R) / 2;
		if(mid / (mid + r) < s)
			L = mid;
		else
			R = mid;
	}
	printf("%.10f\n", L);
	return 0;
}