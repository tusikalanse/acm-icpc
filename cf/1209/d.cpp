#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, k, a, b, ans;
int fa[N];

int find(int i) {
	return i == fa[i] ? i : fa[i] = find(fa[i]);
}

bool unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx == fy) return true;
	fa[fx] = fy;
	return false;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= k; ++i) {
		scanf("%d%d", &a, &b);
		ans += unite(a, b);
	}
	printf("%d\n", ans);
	return 0;
}