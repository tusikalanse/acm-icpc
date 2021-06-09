#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 10010;
const double eps = 1e-6;

int n;
struct point {
	double x, y;
}pt[MAXN];

double GetHeight(double r) {
	double h = 0;
	for(int i = 1; i <= n; ++i) {
		h = max(h, r * pt[i].y / (r - pt[i].x));
	}
	return h;
}


int main() {
	double x, y, z, l = 0, r = 1e9;
	while(~scanf("%d", &n)) {
		l = 0, r = 1e9;
		for(int i = 1; i <= n; ++i) {
			scanf("%lf %lf %lf", &x, &y, &z);
			pt[i].x = sqrt(x * x + y * y);
			pt[i].y = z;
			l = max(l, pt[i].x);
		}
		for(int i = 1; i < 100; ++i) {
			double r1 = l + (r - l) / 3;
			double r2 = r - (r - l) / 3;
			double h1 = GetHeight(r1);
			double h2 = GetHeight(r2);
			if(r1 * r1 * h1 < r2 * r2 * h2) 
				r = r2;
			else
				l = r1;
		}
		printf("%.3lf %.3lf\n", GetHeight(r), r);
	}
	return 0;
}

