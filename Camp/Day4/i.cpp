#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct node {
	int a, b;
}f[N];

int n;
long long ans, temp, tot;

long long check(int card) {
	long long res = 0;
	nth_element(f + 1, f + card, f + n + 1, [card](node i, node j) {return 1LL * i.b * card - i.a < 1LL * j.b * card - j.a;});
	for(int i = 1; i <= card; ++i) {
		res += f[i].a;
	}
	for(int i = card + 1; i <= n; ++i) {
		res += 1LL * f[i].b * card;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d", &f[i].a, &f[i].b);
	}
	int l = 1, r = n;
	while(l <= r) {
		int ll = l + (r - l) / 3, rr = r - (r - l) / 3;
		long long lll = check(ll), rrr = check(rr);
		if(lll < rrr) {
			l = ll + 1;
			ans = max(ans, rrr);
		}
		else {
			r = rr - 1;
			ans = max(ans, lll);
		}
	}
	printf("%lld\n", ans);
	return 0;
}