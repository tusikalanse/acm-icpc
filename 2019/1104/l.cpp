#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int T, n, q;

int pre[N], a[N], vis[N];
vector<int> G[N];
int m;

int main() {
	a[0] = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (a[i] == a[i - 1])
				pre[i] = pre[i - 1];
			else
				pre[i] = i - 1;
		}
		for (int i = 1; i <= n; ++i) {
			G[i].clear();
			G[i].push_back(a[i]);
			vis[a[i]] = 1;
			int p = pre[i];
			while (p) {
				while (p && vis[a[p]]) p = pre[p];
				if (p) {
					vis[a[p]] = 1;
					G[i].push_back(a[p]);
					p = pre[p];
				}
			}
			for (auto x: G[i])
				vis[x] = 0;
		}
		sort(G + 1, G + n + 1);
		while (q--) {
			scanf("%d", &m);
			vector<int> que;
			int c = m;
			que.resize(m);
			for (int i = 0; i < m; ++i) {
				scanf("%d", &que[i]);
				if (que[i] == 0 && c == m) c = i;
			}
			que.resize(c);
			auto p = lower_bound(G + 1, G + n + 1, que);
			int flag = 1;
			if (p == G + n + 1 || p->size() < que.size()) {
				flag = 0;
			}
			else {
				for (int i = 0; i < c; ++i) {
					if ((*p)[i] != que[i])
						flag = 0;
				}
			}
			puts(flag ? "Yes" : "No");
		}
	}
	return 0;
}