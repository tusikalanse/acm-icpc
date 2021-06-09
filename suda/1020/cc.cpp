#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

vector< pair<int, int> > in[N];

long long sum[N << 2], cnt[N << 2];

void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
}

void update(int rt, int l, int r, int pos, int num) {
	if(l == r) {
		cnt[rt] += num;
		sum[rt] += 1LL * num * pos;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos, num);
	else
		update(rt << 1 | 1, mid + 1, r, pos, num);
	pushup(rt);
}

long long query(int rt, int l, int r, int k) {
	if(cnt[rt] <= k)
		return sum[rt];
	if(l == r)
		return 1LL * k * l;
	int mid = l + r >> 1;
	if(cnt[rt << 1] >= k)
		return query(rt << 1, l, mid, k);
	else
		return sum[rt << 1] + query(rt << 1 | 1, mid + 1, r, k - cnt[rt << 1]);
}

int n, m, k;
int l, r, p, c;
long long ans;

int main() {
	memset(sum, 0, sizeof(sum));
	memset(cnt, 0, sizeof(cnt));
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d%d%d", &l, &r, &c, &p);
		in[l].push_back(make_pair(c, p));
		in[r + 1].push_back(make_pair(-c, p));
	}
	for(int i = 1; i <= n; ++i) {
		for(auto &it: in[i]) {
			update(1, 1, 1000000, it.second, it.first);
		}
		ans += query(1, 1, 1000000, k);
	}
	printf("%lld\n", ans);
	return 0;
}