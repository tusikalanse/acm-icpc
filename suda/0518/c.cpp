#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
	double rm, r, R, vx, vy, x0, y0;
	while(~scanf("%lf%lf%lf%lf%lf%lf%lf", &rm, &R, &r, &x0, &y0, &vx, &vy)) {
		double a, b, c, l, v;
		a = vy, b = vx, c = y0 * vx - x0 * vy;
		rm += r;
		R += r;
		if(x0 * vx + y0 * vy >= 0) {
			l = 0;
		}
		else {
			double d = abs(c)/sqrt(a*a+b*b);
			if(d >= R) {
				l = 0;
			}
			else if(d >= rm) {
				l = 2 * sqrt(R*R-d*d);
			}
			else {
				l = 2 * (sqrt(R*R-d*d) - sqrt(rm*rm-d*d));
			}
		}
		v = sqrt(vx*vx + vy*vy);
		printf("%.10lf\n", l/v);
	}
	return 0;
}