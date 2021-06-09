#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, a[N];
long long ans;
vector<int> pos[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i < N; ++i) pos[i].push_back(0);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pos[a[i]].push_back(i);
	}
	for(int i = 1; i < N; ++i) {
		for(int j = 1; j < pos[i].size(); ++j) {
			ans += 1LL * (pos[i][j] - pos[i][j - 1]) * (n - pos[i][j] + 1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}