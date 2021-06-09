#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int p, q, r, s, t, u;
double check(double x) {
	return p * exp(0 - x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u; 
}


int main() {
	while(~scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u)) {
		double l = 0, r = 1, mid;
		if(check(0) < 0 || check(1) > 0) {
			puts("No solution");
			continue;
		}
		for(int i = 0; i < 1000; ++i) {
			mid = (l + r) / 2;
			if(check(mid) > 0) 
				l = mid;
			else 
				r = mid;
		}
		printf("%.4f\n", mid);
	}
	return 0;
}