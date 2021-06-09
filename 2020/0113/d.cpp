#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int d[N], a, b, n;

int main() {
	while (scanf("%d", &n) && n) {
		for (int i = 1; i <= n; ++i)
			d[i] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &a, &b);
			d[a]++;
			d[b + 1]--;
		}
		int pre = 0;
		for (int i = 1; i <= n; ++i) {
			pre += d[i];
			printf("%d%c", pre, i == n ? '\n' : ' ');
		}
	}
	return 0;
}