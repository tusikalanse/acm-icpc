#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct e {
	int x, y, v;
	bool operator<(const e &rhs) const {
		return v < rhs.v;
	}
}edges[N];

int dsu[N], n, m, ans, cnt;

int find(int x) {
	return x == dsu[x] ? x : dsu[x] = find(dsu[x]);
}

bool unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx == fy)
		return false;
	dsu[fx] = fy;
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		dsu[i] = i;
	for(int i = 1; i <= m; ++i) 
		scanf("%d%d%d", &edges[i].x, &edges[i].y, &edges[i].v);
	sort(edges + 1, edges + m + 1);
	int j = 1;
	for(int i = 1; i <= m; ++i) {
		j = i + 1;
		while(j <= m && edges[j].v == edges[i].v) 
			++j;
		cnt = j - i;
		for(int k = i; k < j; ++k) 
			if(find(edges[k].x) == find(edges[k].y))
				--cnt;
		for(int k = i; k < j; ++k)
			cnt -= unite(edges[k].x, edges[k].y);
		ans += cnt;
		i = j - 1;
	}
	printf("%d\n", ans);
	return 0;
}