#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int col[40005 << 2];
int T, n, a, b, cnt, m, t, M, ans, p;
int lst[20005], tmp[40005], vis[40005];

void pushdown(int rt) {
	if(col[rt] != -1) {
		col[rt << 1] = col[rt << 1 | 1] = col[rt];
		col[rt] = -1;
	}
}

void update(int rt, int l, int r, int L, int R, int c) {
	if(l >= L && r <= R) {
		col[rt] = c;
		return;
	}
	pushdown(rt);
	int m = l + r >> 1;
	if(m >= L)
		update(rt << 1, l, m, L, R, c);
	if(m < R)
		update(rt << 1 | 1, m + 1, r, L, R, c);
}

void query(int rt, int l, int r, int L, int R) {
	if(col[rt] != -1) {
		ans += vis[col[rt]] ^ 1;
		vis[col[rt]] = 1;
		col[rt] = -1;
		return;
	}
	if(l == r)
		return;
	pushdown(rt);
	int m = l + r >> 1;
	if(m >= L)
		query(rt << 1, l, m, L, R);
	if(m < R)
		query(rt << 1 | 1, m + 1, r, L, R);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		t = 2 * n;
		memset(lst, 0, sizeof(lst));
		memset(tmp, 0, sizeof(tmp));
		memset(col, -1, sizeof(col));
		memset(vis, 0, sizeof(vis));
		ans = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d %d", &lst[2 * i - 1], &lst[2 * i]);
		}
		memcpy(tmp + 1, lst + 1, sizeof(int) * 2 * n);
		sort(tmp + 1, tmp + 2 * n + 1);
		m = 2 * n;
		for(int i = 1; i + 1 <= t; ++i) {
			if(tmp[i+1] == tmp[i])
				continue;
			if(tmp[i+1] - tmp[i] > 1)
				tmp[++m] = tmp[i] + 1;
		}
		sort(tmp + 1, tmp + m + 1);
		p = unique(tmp + 1, tmp + m + 1) - (tmp + 1);
		for(int i = 1; i <= t; ++i) {
			lst[i] = lower_bound(tmp + 1, tmp + p + 1, lst[i]) - tmp;
		}
		for(int i = 1; i <= n; ++i) {
			update(1, 1, m, lst[2 * i - 1], lst[2 * i], i);
		}
		query(1, 1, m, 1, m);
		printf("%d\n", ans);
	}
	return 0;
}