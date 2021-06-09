#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1010], ans, t, cnt[1010], p;

int main() {
	cin >> n >> k;
	t = (n + 1) / 2;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for(int i = 1; i <= k; ++i) {
		if(cnt[i] % 2 == 0) {
			t -= cnt[i] / 2;
			ans += cnt[i];
		}
		else {
			t -= cnt[i] / 2;
			ans += cnt[i] - 1;
			p++;
		}
	}
	ans += min(t, p);
	cout << ans << endl;
	return 0;
}