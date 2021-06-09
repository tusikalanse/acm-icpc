#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

char s[N];
int n, k, T;
long long ans, x, y;

long long calc(long long x, long long y) {
	return abs(x) + abs(y);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		scanf("%s", s);
		x = y = ans = 0;
		for(int i = 0; i < n; ++i) {
			if(s[i] == 'L')
				x--;
			else if(s[i] == 'R')
				x++;
			else if(s[i] == 'D')
				y--;
			else if(s[i] == 'U')
				y++;
			ans = max(ans, calc(x, y));
		}
		x = x * (k - 1);
		y = y * (k - 1);
		ans = max(ans, calc(x, y));
		for(int i = 0; i < n; ++i) {
			if(s[i] == 'L')
				x--;
			else if(s[i] == 'R')
				x++;
			else if(s[i] == 'D')
				y--;
			else if(s[i] == 'U')
				y++;
			ans = max(ans, calc(x, y));
		}
		printf("%lld\n", ans);
	}
	return 0;
}