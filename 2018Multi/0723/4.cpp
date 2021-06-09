#include <bits/stdc++.h>
using namespace std;

struct node {
	int l, r;
	node() {}
	node(int a, int b) : l(a), r (b) {}
	bool operator<(const node &rhs) const {
		if(l == rhs.l)
			return r < rhs.r;
		return l > rhs.l;
	}
}tmp;

bool vis[100010];

priority_queue<node> pq;

int T, n, m, l, r, ll, rr, t, d, x, tp;
int ans[100010];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &m);
		ll = n, rr = 0;
		memset(vis, 0, sizeof(vis));
		memset(ans, 0, sizeof(ans));
		while(m--) {
			scanf("%d %d", &l, &r);
			pq.push(node(l, r));
			ll = min(ll, l);
			rr = max(rr, r);
		}
		for(int i = 1; i < ll; ++i)
			ans[i] = 1;
		for(int i = rr + 1; i <= n; ++i)
			ans[i] = 1;
		tp = ll;
		while(!pq.empty()) {
			tmp = pq.top();
			pq.pop();
			l = tmp.l;
			r = tmp.r;
			if(r < ll)
				contine;
			for(int i = tp; i < l; ++i)
				vis[ans[i]] = 0;
			t = 1;
			if(ll < l) {
				for(int i = ll; i < l; ++i)
					ans[i] = 1;
				ll = l;
			}
			for(int i = ll; i <= r; ++i) {
				while(vis[t]) 
					t++;
				ans[ll++] = t;
				vis[t++] = 1;
			}
			tp = l;
		}
		for(int i = 1; i <= n; ++i)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}