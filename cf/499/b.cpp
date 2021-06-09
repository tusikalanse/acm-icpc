#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, m, t, l, r, mid, ans;
map<int, int> cnt;

bool check(int day) {
	if(day == 0)
		return 1;
	int p = 0;
	for(auto it = cnt.begin(); it != cnt.end(); ++it)
		p += it->second/day;
	return p >= n;
}


int main() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> t;
		cnt[t]++;
	}
	l = ans = 0, r = m / n;
	while(l <= r) {
		mid = l + r >> 1;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else 
			r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}