#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 210;
int cnt, head[N], pnt[N << 1], nxt[N << 1];
void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

int T, n, a, b;
int maxa, ans;

void dfs(int u, int pre, int l, int &lm, int &id) {
	for(int i = head[u]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(j == pre) continue;
		dfs(j, u, l + 1, lm, id);
	}
	if(l > lm) {
		lm = l;
		id = u;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		memset(head, -1, sizeof(head));
		cnt = 0;
		scanf("%d", &n);
		for(int i = 1; i < n; ++i) {
			scanf("%d%d", &a, &b);
			add(a, b);
			add(b, a);
		}
		a = 1;
		maxa = 0;
		dfs(1, 0, 0, maxa, a);
		maxa = 0;
		dfs(a, 0, 0, maxa, a);
		ans += maxa;
	}
	printf("%d\n", ans);
	return 0;
}