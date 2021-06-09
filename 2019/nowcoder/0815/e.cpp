#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, x, y;
int fa[N], size[N];
long long sz;
unsigned long long ans;

int find(int x) {
	return fa[x] == x ? x : find(fa[x]);
}

void unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx != fy) {
		if(size[fx] < size[fy])
			swap(fx, fy);
		fa[fy] = fx;
		size[fx] += size[fy];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	if(n <= 3) {
		for(int i = 0; i <= m; ++i)
			puts("0");
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		fa[i] = i;
		size[i] = 1;
	}
	ans = 1ULL * n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
	printf("%llu\n", ans);
	sz = n;
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		if(find(x) == find(y)) {
			printf("%llu\n", ans);
			continue;
		}
		int sx = size[find(x)], sy = size[find(y)];
		ans -= 1ULL * sx * sy * (1ULL * (n - sx - sy) * (n - sx - sy) - (sz - 1LL * sx * sx - 1LL * sy * sy)) / 2;
		sz -= 1LL * sx * sx;
		sz -= 1LL * sy * sy;
		sz += 1LL * (sx + sy) * (sx + sy);
		printf("%llu\n", ans);
		unite(find(x), find(y));
	}
	return 0;
}