#include <bits/stdc++.h>
using namespace std;
double eps = 1e-6;

int main(){
	double r, x1, y1, x2, y2;
	scanf("%lf %lf %lf %lf %lf", &r, &x1, &y1, &x2, &y2);
	double d = hypot(abs(x1-x2), abs(y1-y2));
	if(d >= r){
		printf("%lf %lf %lf\n", x1, y1, r);
	}
	else{
		double R = (d+r)/2;
		if(x1-x2){
			double k = (y2-y1)/(x2-x1);
			double dx = R/sqrt(1 + k*k);
			double dy = k*dx;
			double x3 = x2 - dx, y3 = y2 - dy, x4 = x2 + dx, y4 = y2 + dy;
			double r3 = hypot(abs(x3-x1), abs(y3-y1)), r4 = hypot(abs(x4-x1), abs(y4-y1));
			if(r3 < r4)
				printf("%lf %lf %lf\n", x3, y3, R);
			else
				printf("%lf %lf %lf\n", x4, y4, R);
		}
		else {
			double y;
			if(y1 > y2){
				y = y2 + R;
			}
			else y = y2 - R;
		printf("%lf %lf %lf\n", x1, y, R);
		}
	}	
	return 0;
}