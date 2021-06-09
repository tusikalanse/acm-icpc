#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int T, n, b, cas;
long long ans[12][N];

int get(int base, int num) {
	int res = 0;
	while(num) {
		res += num % base;
		num /= base;
	}
	return res;
}

int main() {
	scanf("%d", &T);
	for(int b = 2; b <= 10; ++b) {
		for(int i = 1; i <= 1000000; ++i)
			ans[b][i] = ans[b][i - 1] + get(b, i);
	}
	while(T--) {
		scanf("%d%d", &n, &b);
		printf("Case #%d: %lld\n", ++cas, ans[b][n]);
	}
	return 0;
}