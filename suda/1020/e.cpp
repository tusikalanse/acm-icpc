#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T, n, m, d, ans;
long long t, tot;
int a[N];
long long sum[N];
int check(long long lim) {
	int cnt = 0;
	long long tot = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] > lim)
			continue;
		if(tot + a[i] > t)
			break;
		cnt++;
		tot += a[i];
		if(i % m == 0)
			tot += sum[i] - sum[i - m];
	}
	return cnt;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%lld", &n, &m, &t);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		d = 1;
		ans = 0;
		long long l = 1, r = t, lm, rm;
		while(l <= r) {
			lm = l + (r - l) / 3;
			rm = r - (r - l) / 3;
			int clm = check(lm), crm = check(rm);
			if(clm < crm) {
				l = lm + 1;
				if(ans < crm)
					ans = crm, d = rm;
			}
			else {
				r = rm - 1;
				if(ans < clm)
					ans = clm, d = lm;
			}
		}
		printf("%d %d\n", ans, d);
	}

	return 0;
}