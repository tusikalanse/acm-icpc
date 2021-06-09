#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long gcd(long long x, long long y) {
	return y ? gcd(y, x % y): x;
}

int a[7];
long long sum[160];

int main() {
	int n;
	while(~scanf("%d", &n) && n) {
		memset(a, 0, sizeof(a));
		memset(sum, 0, sizeof(sum));
		int tot = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i = n; i > 0; i--) {
			for(int j = 1; j <= a[i]; j++) {
				tot++;
				for(int k = i + 1; k <= n; k++) 
					sum[tot] += (a[k] >= j);
				sum[tot] += a[i] - j + 1;
			}
		}
		long long x = 1, y = 1;
		for(int i = 1; i <= tot; i++) {
			x *= i;
			y *= sum[i];
			long long g = gcd(x, y);
			x /= g;
			y /= g;
		}
		printf("%lld\n", x/y);
	}
	return 0;
}