#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int g(int a, int b) {
	int ans = 0;
	for(int i = 1; i <= a; ++i) 
		for(int j = 1; j <= b; ++j) {
			if((i*j)%2016 == 0)
				++ans;
		}
	return ans;
}


int main() {
	int c = g(2016, 2016);
	int x, y;
	long long ans;
	while(~scanf("%d %d", &x, &y)) {
		int a, b;
		a = x/2016;
		b = y/2016;
		ans = 1LL*a*b*c;
		ans += g(x%2016, y%2016);
		ans += 1LL*b*g(x%2016, 2016);
		ans += 1LL*a*g(2016, y%2016);
		printf("%lld\n", ans);
	}


	return 0;
}