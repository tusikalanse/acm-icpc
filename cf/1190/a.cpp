#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

long long n, a[N];
int m, ans, page = 0;
long long p1, p2, cnt, k;

int main() {
	scanf("%lld%d%lld", &n, &m, &k);
	for(int i = 1; i <= m; ++i) {
		scanf("%lld", &a[i]);
	}
	p2 = k;
	ans = a[1] <= 1LL * k;
	cnt = 0;
	for(int i = 1; i <= m; ++i) {
		//cout << "p2 = " << p2 << endl;
		if(a[i] <= p2) {
			cnt++;
			continue;
		}
		p2 += cnt;
		cnt = 0;
		if(i == m) {
			ans++;
			break;
		}
		long long nxt = a[i];
		--i;
		if(p2 >= nxt) {
			ans++;
			continue;
		}
		long long d = 1 + (nxt - p2 - 1) / k;
		p2 = p2 + 1LL * d * k;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}