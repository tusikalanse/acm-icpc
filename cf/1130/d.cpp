#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

vector<int> f[N];
int n, m, a, b, d[N], ans[N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		f[a - 1].push_back(b - 1);
	}
	for(int i = 0; i < n; ++i) {
		int tmp = n;
		for(auto j: f[i]) {
			tmp = min(tmp, (j - i + n) % n);
		}
		d[i] = ((int)f[i].size() - 1) * n + tmp;
	}
	for(int i = 0; i < n; ++i) {
		ans[i] = 0;
		for(int j = 0; j < n; ++j) {
			ans[i] = max(ans[i], d[(i + j) % n] == 0 ? 0 : d[(i + j) % n] + j);
		}
		printf("%d%c", ans[i], " \n"[i + 1 == n]);
	}
	return 0;
}