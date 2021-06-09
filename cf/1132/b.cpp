#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int a[N], n, m, q;
long long sum;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a + 1, a + n + 1, [](int i, int j) {return i > j;});
	scanf("%d", &m);
	while(m--) {
		scanf("%d", &q);
		printf("%lld\n", sum - a[q]);
	}
	return 0;
}