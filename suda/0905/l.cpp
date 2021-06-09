#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int size[N], dep[N], T, n, k, head[N], nxt[N << 1], pnt[N << 1], cnt, root, ans;

void init() {
	memset(head, -1, sizeof(head));
	cnt = 0;
	ans = 0;
	root = -1;
}

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void dfssize(int rt, int pre, int d) {
	size[rt] = 1;
	dep[rt] = d;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(j == pre) continue;
		dfssize(j, rt, d + 1);
		size[rt] += size[j];
	}
	if(size[rt] >= k)
		if(root == -1 || dep[root] < dep[rt])
			root = rt;
}

void dfsans(int rt, int pre, int d) {
	size[rt] = 1;
	dep[rt] = d;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(j == pre) continue;
		dfsans(j, rt, d + 1);
		size[rt] += size[j];
	}
	if(size[rt] >= k)
		ans++;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		int u, v;
		init();
		for(int i = 1; i < n; ++i) {
			scanf("%d%d", &u, &v);
			add(u, v); add(v, u);
		}
		dfssize(1, 0, 0);
		if(root != -1)
			dfsans(root, 0, 0);
		if(ans)
			ans--;
		printf("%d\n", ans);
	}
	return 0;
}