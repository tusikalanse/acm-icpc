#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, q, x, a, b, c;
using LL = long long;

LL sum[N], nsum[N];
int lis[N];


int lowbit(int i) {
	return i & -i;
} 

LL query(LL a[], int pos) {
	LL ans = 0;
	for(int i = pos; i > 0; i -= lowbit(i))
		ans += a[i];
	return ans;
}

void update(LL a[], int pos, LL val) {
	for(int i = pos; i < n; i += lowbit(i))
		a[i] += val;
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		lis[i] = x;
		update(sum, i, x);
		update(nsum, i, 1LL * x * (n + 1 - i));
	}
	while(q--) {
		scanf("%d%d%d", &a, &b, &c);
		if(a == 1) {
			int l = b, r = c;
			printf("%lld\n", query(nsum, r) - query(nsum, l - 1) - (query(sum, r) - query(sum, l - 1)) * (n - r));
		}
		else {
			update(sum, b, c - lis[b]);
			update(nsum, b, 1LL * (c - lis[b]) * (n + 1 - b));
			lis[b] = c;
		}

	}

	return 0;
}