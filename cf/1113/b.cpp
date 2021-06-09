#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
vector<int> fac[110];
int n, a[N], cnt[110], ans, tmp, tot;


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		ans += a[i];
		tot += a[i];
		for(int j = 2; j <= 100; ++j) {
			if(a[i] % j == 0)
				fac[j].push_back(a[i]);
		}
	}
	for(int i = 2; i <= 100; ++i) {
		sort(fac[i].begin(), fac[i].end());
	}
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= 100; ++i) {
		tmp = tot;
		if(!fac[i].empty()) {
			tmp = tmp - *fac[i].rbegin() + *fac[i].rbegin() / i;
			if(*fac[i].rbegin() == a[1] && cnt[a[1]] == 1) {
				tmp = tmp - a[2] + i * a[2];
			}
			else
				tmp = tmp - a[1] + i * a[1];
		}
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}