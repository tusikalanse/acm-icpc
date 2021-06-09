#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e5 + 10;

int cnt[N << 2];
LL sum[N << 2];
int n, m, x, y, a[N], b[N], val[N], num, tmp, ele;
vector<int> c[N], iter[N];
map<int, int> mp;

void pushup(int rt) {
	cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	cnt[rt] = sum[rt] = 0;
	if(l == r) 
		return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) {
		val > 0 ? cnt[rt]++ : cnt[rt]--;
		sum[rt] += val;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos, val);
	else
		update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

LL query(int rt, int l, int r, int k) {
	if(l == r) {
		return sum[rt] / cnt[rt] * k;
	}
	int mid = l + r >> 1;
	if(cnt[rt << 1] >= k)
		return query(rt << 1, l, mid, k);
	return sum[rt << 1] + query(rt << 1 | 1, mid + 1, r, k - cnt[rt << 1]);
}


int main() {
	LL ans = 0x3f3f3f3f3f3f3f3f, t = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		c[y].push_back(x);
		b[i] = a[i] = x;
	}
	sort(a + 1, a + m + 1);
	num = unique(a + 1, a + m + 1) - a - 1;
	build(1, 1, num);
	for(int i = 1; i <= m; ++i) {
		tmp = b[i];
		b[i] = lower_bound(a + 1, a + num + 1, b[i]) - a;
		update(1, 1, num, b[i], tmp);
		mp[tmp] = b[i];
	}
	for(int i = 1; i <= n; ++i) {
		sort(c[i].begin(), c[i].end(), greater<int>());
		for(int j = 0; j < c[i].size(); ++j)
			iter[j + 1].push_back(c[i][j]);
	}
	for(int i = m; i; --i) {
		for(auto &it: iter[i]) {
			t += it;
			update(1, 1, num, mp[it], -it);
			ele++;
		}
		if(ele < i && cnt[1] + ele >= i) 
			ans = min(ans, t + query(1, 1, num, i - ele));
		if(ele >= i)
			ans = min(ans, t);
	}
	printf("%lld\n", ans);
	return 0;
}