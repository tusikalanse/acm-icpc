#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
long long X1, Y1, x2, y2, x, y, n, d, dis, T;
long long l, r, ans;
char s[N];

bool check(long long mid) {
	T = mid / n;
	if(T != 0)
		T--;
	long long xx = X1 + (x - X1) * T, yy = Y1 + (y - Y1) * T;
	dis = abs(xx - x2) + abs(yy - y2);
	if(dis <= T * n)
		return true;
	for(long long i = T * n; i < mid; ++i) {
		if(s[i % n] == 'R')
			xx++;
		else if(s[i % n] == 'L')
			xx--;
		else if(s[i % n] == 'U')
			yy++;
		else
			yy--;
		dis = abs(xx - x2) + abs(yy - y2);
		if(dis <= i + 1)
			return true; 
	}
	return false;
}


int main() {
	scanf("%lld%lld%lld%lld%lld%s", &X1, &Y1, &x2, &y2, &n, s);
	l = 1, r = 1e18, ans = -1;
	x = X1, y = Y1;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'R')
			x++;
		else if(s[i] == 'L')
			x--;
		else if(s[i] == 'U')
			y++;
		else
			y--;
	}
	while(l <= r) {
		long long mid = l + r >> 1;
		if(check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
} 