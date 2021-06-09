#include <bits/stdc++.h>
using namespace std;

int T, n;
long long k;

int cnt[30];
vector<int> gao;

long long C(int n, int m) {
	if (n < 0 || m < 0 || m > n) return 0;
	long long res = 1;
	for (int i = 1; i <= m; ++i)
		res = res * (n - i + 1) / i;
	return res;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &k);
		gao.clear();
		for (int i = 2; ; ++i) {
			gao.push_back(k % i);
			k /= i;
			if (k == 0) break;
		}
		memset(cnt, 0, sizeof(cnt));
		n = gao.size();
		for (int i = 0; i < n; ++i)
			cnt[gao[i]]++;
		long long ans = 0;
		for (int last = 1; last <= 28; ++last) {
			if (cnt[last] == 0) continue;
			cnt[last]--;
			long long tmp = 1;
			int used = 1;
			for (int i = 28; ~i; --i) {
				if (cnt[i] == 0) continue;
				tmp *= C(min(n, n - i + 1) - used, cnt[i]);
				used += cnt[i];
			}
			ans += tmp;
			cnt[last]++;
		}
		printf("%lld\n", ans - 1);
	}
	return 0;
}