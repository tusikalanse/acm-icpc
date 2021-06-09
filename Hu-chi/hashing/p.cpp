#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int seed = 13331;
LL pw[1000010];
LL all[2000010], a[1000010];
int n, m, cnt, x, y;

int calc(LL x) {
	return upper_bound(all, all + cnt, x) - lower_bound(all, all + cnt, x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	pw[0] = 1;
	for(int i = 1; i < n; ++i)
		pw[i] = pw[i - 1] * seed;
	for(int i = 0; i < m; ++i) {
		cin >> x >> y;
		--x, --y;
		a[x] += pw[y];
		a[y] += pw[x];
	}
	cnt = 0;
	for(int i = 0; i < n; ++i) {
		all[cnt++] = a[i];
		all[cnt++] = a[i] + pw[i];
	}
	sort(all, all + cnt);
	LL ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += calc(a[i]) - 1;
		ans += calc(a[i] + pw[i]) - 1;
	}
	cout << ans / 2 << endl;
	return 0;
}
