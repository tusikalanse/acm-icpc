#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N], l[N], r[N], n, ans;

int main() {
	scanf("%d%*d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(l[a[i]] == 0)
			l[a[i]] = i;
		r[a[i]] = i;
	}
	for(int le = 1, ri = 1; le <= n; le = ri + 1) {
		int i = le; ri = le;
		map<int, int> cnt;
		while(i <= ri) {
			cnt[a[i]]++;
			ri = max(ri, r[a[i]]);
			i++;
		}
		int m = 0;
		for(auto f: cnt)
			m = max(m, f.second);
		ans += (ri - le + 1) - m;
	}
	printf("%d\n", ans);
	return 0;
}
