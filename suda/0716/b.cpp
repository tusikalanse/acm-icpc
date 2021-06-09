#include <bits/stdc++.h>
using namespace std;

int f[100010];

int main() {
	int n, ans = 0, a, b, gcd;
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	gcd = __gcd(a, b);
	f[0] = a % 2;
	f[1] = b % 2;
	for(int i = 2; i < n; ++i) {
		scanf("%d", &a);
		gcd = __gcd(gcd, a);
		f[i] = a % 2;
	}
	puts("YES");
	if(gcd > 1) {
		printf("0\n");
		return 0;
	}
	for(int i = 0; i + 1 < n; ++i) {
		if(f[i] == 1 && f[i + 1] == 1) {
			ans++;
			f[i] = f[i + 1] = 0;
		}
	}
	for(int i = 0; i < n; ++i)
		ans += 2 * f[i];
	printf("%d\n", ans);
	return 0;
}