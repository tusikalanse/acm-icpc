#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

long long aa, bb, ans;

int T, n, a[N], b[N];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		ans = aa = bb = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d%d", &a[i], &b[i]);
		}
		int i = 1, j = n;
		while(i < j) {
			long long tmp = 0;
			while(i < j && a[i]) {
				if(b[j] >= a[i]) {
					b[j] -= a[i];
					tmp += a[i];
					a[i] = 0;
				}
				else {
					a[i] -= b[j];
					tmp += b[j];
					b[j] = 0;
					j--;
				}
			}
			ans += tmp;
			if(i == j) break;
			i++;
		}
		// cout << i << " " << j << endl;
		// cout << ans << endl;
		for(int k = 1; k < i; ++k) bb += b[k];
		for(int k = i + 1; k <= n; ++k) aa += a[k];
		long long tmp = min(bb, a[i] * 1LL);
		a[i] -= tmp; bb -= tmp; ans += tmp;
		tmp = min(aa, 1LL * b[i]);
		b[i] -= tmp; aa -= tmp; ans += tmp;
		ans += min(aa, bb);
		printf("%lld\n", ans);
	}
	return 0;
}