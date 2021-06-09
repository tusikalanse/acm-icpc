#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int fa[N], n, m, cnt;

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy)
		fa[fx] = fy;
}

int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		scanf("%d", &m);
		for (int i = 1; i <= n; ++i)
			fa[i] = i;
		cnt = 0;
		while (m--) {
			int a, b;
			scanf("%d%d", &a, &b);
			unite(a, b);
		}
		for (int i = 1; i <= n; ++i)
			cnt += fa[i] == i;
		printf("%d\n", cnt - 1);
	}
	return 0;
}