#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+10;

int vis[MAXN], a[MAXN], pre[MAXN];

int Find(int x) {
	return x == pre[x] ? x : pre[x] = Find(pre[x]);
}

void Unite(int x, int y) {
	int fx = Find(x), fy = Find(y);
	if(fx != fy) {
		pre[fx] = fy;
	}
}

priority_queue<int> ans[MAXN];

int main() {
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		pre[i] = i;
		scanf("%d", &a[i]);
	}
	while(m--) {
		scanf("%d %d", &x, &y);
		Unite(x, y);
	}
	for(int i = 1; i <= n; i++) {
		ans[Find(i)].push(a[i]);
	}
	for(int i = 1; i <= n; i++) {
		printf("%d ", ans[Find(i)].top());
		ans[Find(i)].pop();
	}
	puts("");
	return 0;
}