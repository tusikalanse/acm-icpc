#include <bits/stdc++.h>
using namespace std;

double a, b, c, ha, hb, hc, p, s, ans, ya, yb, yc;
double x1, x2, x3, y1, y2, y3, w, xa, xb, xc;
int T;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &w);
		a = hypot(abs(x1 - x2), abs(y1 - y2));
		b = hypot(abs(x1 - x3), abs(y1 - y3));
		c = hypot(abs(x3 - x2), abs(y3 - y2));
		p = (a + b + c) / 2;
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		if(a <= w) 
			ha = 2 * w / a;
		else {
			

			if(xa >= 0 && xa <= w)
				ha = ya;
			else 
				ha = -1;
		}
		if(b <= w)
			hb = 2 * w / b;
		else {

			if(xb >= 0 && xb <= w)
				hb = yb;
			else
				hb = -1;
		}
		if(c <= w)
			hc = 2 * w / c;
		else {

			if(xc >= 0 && xc <= w)
				hc = yc;
			else 
				hc = -1;
		}
		ans = ha;
		if(hb != -1 && hb < ans)
			ans = hb;
		if(hc != -1 && hc < ans)
			ans = hc;
		if(ans == -1)
			puts("IMPOSSIBLE");
		else
			printf("%.10f\n", ans);
	}

	return 0;
}