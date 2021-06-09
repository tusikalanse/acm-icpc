#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int cnt, head[N], nxt[N << 1], pnt[N << 1];
int size[N], ans[N], fa[N];

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void dfs(int rt, int pre) {
	int id = 0;
	ans[rt] = rt;
	fa[rt] = pre;
	size[rt] = 1;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(j == pre) continue;
		dfs(j, rt);
		size[rt] += size[j];
		if(size[j] > size[id])
			id = j;
	}
	if((size[id] << 1) > size[rt]) {
		int t = ans[id];
		while((size[rt] - size[t] << 1) > size[rt]) t = fa[t];
		ans[rt] = t;
	}
}

int n, m, p;

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n; ++i) {
		scanf("%d", &p);
		add(i, p);
		add(p, i);
	}
	dfs(1, 0);
	while(m--) {
		scanf("%d", &p);
		printf("%d\n", ans[p]);
	}
	return 0;
}