#include <bits/stdc++.h>
using namespace std;

const int N = 15e4 + 10;
int a[N], nxt[N];
int T, n, cas = 0;
int vis[N], ans[N];

struct node {
	int val, pos, stp;
	bool operator<(const node &rhs) const {
		if(stp != rhs.stp)
			return stp > rhs.stp;
		return val < rhs.val;
	}
};

int main() {
	scanf("%d", &T);
	while(T--) {
		int mx = 0;
		priority_queue<node> pq;
		scanf("%d", &n);
		getchar();
		memset(vis, -1, sizeof(vis));
		memset(ans, -1, sizeof(ans));
		for(int i = 0; i < n; ++i) {
			a[i] = getchar() - '0';
			mx = max(mx, a[i]);
			nxt[i] = (1LL * i * i + 1) % n;
		}
		for(int i = 0; i < n; ++i) 
			if(mx == a[i])
				pq.push({a[i], i, 0});
		while(!pq.empty()) {
			node t = pq.top(); 
			pq.pop();
			if(ans[t.stp] == -1) ans[t.stp] = t.val;
			if(ans[t.stp] > t.val) continue;
			if(vis[t.pos] == t.stp) continue;
			vis[t.pos] = t.stp;
			if(t.stp != n - 1)
				pq.push({a[nxt[t.pos]], nxt[t.pos], t.stp + 1});
		}
		printf("Case #%d: ", ++cas);
		for(int i = 0; i < n; ++i)
			printf("%d", ans[i]);
		putchar('\n');
	}
	return 0;
}