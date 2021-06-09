#include <bits/stdc++.h>
using namespace std;

const int N = 210;
int cnt, head[N], pnt[N << 1], nxt[N << 1];
void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

int n, a, b;
int maxa, maxb;


void dfs(int u, int pre, int l, int ig, int &lm, int &id) {
	for(int i = head[u]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(j == pre || j == ig) continue;
		dfs(j, u, l + 1, ig, lm, id);
	}
	if(l > lm) {
		lm = l;
		id = u;
	}
}


int main() {
	int ans = 0;
	memset(head, -1, sizeof(head));
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	for(int rt = 1; rt <= n; ++rt) {
		for(int i = head[rt]; ~i; i = nxt[i]) if(rt < pnt[i]) {
			int j = pnt[i];
			maxa = maxb = 0;
			a = rt, b = j;
			dfs(rt, 0, 0, j, maxa, a);
			dfs(j, 0, 0, rt, maxb, b);
			maxa = maxb = 0;
			dfs(a, 0, 0, j, maxa, a);
			dfs(b, 0, 0, rt, maxb, b);
			ans = max(ans, maxa * maxb);
		}
	}
	printf("%d\n", ans);
	return 0;
}