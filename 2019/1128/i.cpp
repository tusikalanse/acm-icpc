#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, cas, n;
int x[N], y[N];

map<long long, int> vis;
map<long long, vector<int>> xx, yy;

int maxx, maxy, cnty, cnty_1;

bool check() {
	int cnt = 0;
	for (auto &vx: xx) {
		if (vx.second.size() != maxx) continue;
		cnt = 0;
		for (auto vy: vx.second) {
			cnt += yy[vy].size() == maxy;
		}
		if (cnt < cnty) return true;
	}
	return false;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		xx.clear(); yy.clear(); vis.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &x[i], &y[i]);
			xx[x[i]].push_back(y[i]);
			yy[y[i]].push_back(x[i]);
		}
		maxx = 0, maxy = 0, cnty = 0, cnty_1 = 0;
		for (auto &i: xx) maxx = max(maxx, (int)i.second.size());
		for (auto &i: yy) maxy = max(maxy, (int)i.second.size());
		for (auto &i: yy) cnty += maxy == i.second.size();
		for (auto &i: yy) cnty_1 += maxy - 1 == i.second.size();
		printf("Case %d: ", ++cas);
		if (maxx == 1 && maxy == 1) {
			if (n == 1)
				puts("1 1");
			if (n >= 2)
				printf("2 %lld\n", 1LL * n * (n - 1) / 2);
		}
		else if (check()) {
			long long ans = 0;
			for (auto &vx: xx) {
				if (vx.second.size() != maxx) continue;
				int cnt = 0;
				for (auto vy: vx.second) {
					cnt += yy[vy].size() == maxy;
				}
				ans += cnty - cnt;
			}
			printf("%d %lld\n", maxx + maxy, ans);
		}
		else {
			long long ans = 0;
			for (auto &vx: xx) {
				if (vx.second.size() == maxx) {
					ans += cnty;
					int cnt = 0;
					for (auto vy: vx.second) {
						cnt += yy[vy].size() == maxy - 1;
					}
					ans += cnty_1 - cnt;
				}
				else if (vx.second.size() == maxx - 1) {
					int cnt = 0;
					for (auto vy: vx.second) {
						cnt += yy[vy].size() == maxy;
					}
					ans += cnty - cnt;
				}
			}
			printf("%d %lld\n", maxx + maxy - 1, ans);
		}
	}
	return 0;
}