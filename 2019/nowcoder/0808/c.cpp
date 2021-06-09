#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct GKP {
	int h, c, p, cc;
}a[N];
int n, b[N], m;
long long sum[N];

long long cost[N << 2], cnt[N << 2];

void build(int rt, int l, int r) {
	cost[rt] = cnt[rt] = 0;
	if(l == r) return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int l, int r, int pos, int val, int num) {
	if(l == r) {
		cnt[rt] += num;
		cost[rt] += 1LL * val * num;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid) update(rt << 1, l, mid, pos, val, num);
	else update(rt << 1 | 1, mid + 1, r, pos, val, num);
	cost[rt] = cost[rt << 1] + cost[rt << 1 | 1];
	cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
}

long long query(int rt, int l, int r, long long num) {
	if(num <= 0) return 0;
	if(l == r) 
		return cost[rt] / cnt[rt] * num;
	int mid = l + r >> 1;
	if(cnt[rt << 1] < num) return cost[rt << 1] + query(rt << 1 | 1, mid + 1, r, num - cnt[rt << 1]);
	else return query(rt << 1, l, mid, num);
}

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &a[i].h, &a[i].c, &a[i].p);
			b[i] = a[i].c;
		}
		sort(a + 1, a + n + 1, [&](GKP &i, GKP &j){return i.h < j.h;});
		sum[n + 1] = 0;
		for(int i = n; i; --i) {
			sum[i] = sum[i + 1] + 1LL * a[i].c * a[i].p;
		}
		long long ans = 1e18, cnt = 0, tot = 0;
		sort(b + 1, b + n + 1);
		m = unique(b + 1, b + n + 1) - b - 1;
		stack<GKP> s;
		for(int i = 1; i <= n; ++i)
			a[i].cc = lower_bound(b + 1, b + m + 1, a[i].c) - b;
		build(1, 1, m);
		for(int i = 1; i <= n; ++i) {
			tot += a[i].p;
			if(a[i].h == a[i - 1].h) {
				cnt += a[i].p;
				s.push(a[i]);
			}
			else {
				while(!s.empty()) {
					GKP u = s.top(); s.pop();
					update(1, 1, m, u.cc, u.c, u.p);
				}
				s.push(a[i]);
				cnt = a[i].p;
			}
			ans = min(ans, query(1, 1, m, tot - 2 * cnt + 1) + sum[i + 1]);
		}
		cout << ans << endl;
	}
	return 0;
}