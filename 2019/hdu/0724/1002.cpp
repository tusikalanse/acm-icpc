#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, a[N];

struct Seg_Tree {
	int mx[N << 2];
	void init(int rt = 1, int l = 1, int r = n + 2) {
		mx[rt] = 0;
		if(l == r) return;
		int mid = l + r >> 1;
		init(rt << 1, l, mid);
		init(rt << 1 | 1, mid + 1, r);
	}
	void pushup(int rt) {
		mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
	}
	void update(int rt, int l, int r, int pos, int val) {
		if(l == r) {
			mx[rt] = max(mx[rt], val);
			return;
		}
		int mid = l + r >> 1;
		if(pos <= mid)
			update(rt << 1, l, mid, pos, val);
		else
			update(rt << 1 | 1, mid + 1, r, pos, val);
		pushup(rt);
	}
	int query(int rt, int l, int r, int L, int R) {
		if(L <= l && r <= R)
			return mx[rt];
		int mid = l + r >> 1, ans = 0;
		if(L <= mid)
			ans = max(ans, query(rt << 1, l, mid, L, R));
		if(R > mid)
			ans = max(ans, query(rt << 1 | 1, mid + 1, r, L, R));
		return ans;
	}
}zero, one;

int dp[2][N][2], len;
vector<int> ans[2], all, up[N], down[N];

void init() {
	len = 0;
	zero.init();
	one.init();
	all.clear();
	ans[0].clear();
	ans[1].clear();
	for(int i = 0; i <= n + 1; ++i)
		up[i].clear(), down[i].clear();
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			all.push_back(a[i]);
		}
		all.push_back(0);
		all.push_back(0x3f3f3f3f);
		sort(all.begin(), all.end());
		all.erase(unique(all.begin(), all.end()), all.end());
		for(int i = 1; i <= n; ++i) {
			a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
		}
		for(int i = 1; i <= n; ++i) {
			dp[0][i][0] = zero.query(1, 1, n + 2, 1, a[i] - 1) + 1;
			dp[0][i][1] = max(one.query(1, 1, n + 2, a[i] + 1, n + 2) + 1, dp[0][i][0]);
			zero.update(1, 1, n + 2, a[i], dp[0][i][0]);
			one.update(1, 1, n + 2, a[i], dp[0][i][1]);
		}
		zero.init(); one.init();
		for(int i = n; i; --i) {
			dp[1][i][0] = zero.query(1, 1, n + 2, 1, a[i] - 1) + 1;
			dp[1][i][1] = max(one.query(1, 1, n + 2, a[i] + 1, n + 2) + 1, dp[1][i][0]);
			zero.update(1, 1, n + 2, a[i], dp[1][i][0]);
			one.update(1, 1, n + 2, a[i], dp[1][i][1]);
		}
		for(int i = 1; i <= n; ++i) {
			len = max(len, dp[0][i][0] + dp[1][i][1] - 1);
		}
		for(int i = 1; i <= n; ++i) {
			assert(len >= dp[0][i][1] + dp[1][i][0] - 1);
		}
		for(int i = 1; i <= n; ++i) {
			if(dp[0][i][0] + dp[1][i][1] - 1 == len) {
				up[dp[0][i][0]].push_back(i);
			}
			if(dp[0][i][1] + dp[1][i][0] - 1 == len) {
				down[dp[1][i][0]].push_back(i);
			}
		}
		int cur = 0, flag = 0;
		for(int i = 1; i <= len; ++i) {
			if(!flag) {
				vector<int> &v = up[i];
				int p = upper_bound(v.begin(), v.end(), cur) - v.begin();
				if(p == v.size() || a[v[p]] <= a[cur]) {
					flag = 1;
				}
				else {
					vector<int> &vv = down[len - i + 1];
					int pp = upper_bound(v.begin(), v.end(), cur) - v.begin();
					if(pp != vv.size() && a[vv[pp]] < a[cur] && vv[pp] < v[p]) {
						flag = 1;
					}
					else {
						cur = v[p];
						ans[0].push_back(v[p]);
					}
				}
			}
			if(flag) {
				vector<int> &v = down[len - i + 1];
				int p = upper_bound(v.begin(), v.end(), cur) - v.begin();
				assert(a[v[p]] < a[cur]);
				assert(p < v.size());
				cur = v[p];
				ans[0].push_back(v[p]);
			}
		}
		cur = flag = 0;
		for(int i = 1; i <= len; ++i) {
			if(!flag) {
				vector<int> &v = up[i];
				int p = lower_bound(v.begin(), v.end(), cur, [&](int i, int j){return a[i] > a[j];}) - v.begin() - 1;
				if(p < 0 || a[v[p]] <= a[cur]) {
					flag = 1;
				}
				else {
					cur = v[p];
					ans[1].push_back(v[p]);
				}
			}
			if(flag) {
				vector<int> &v = down[len - i + 1];
				int p = lower_bound(v.begin(), v.end(), cur, [&](int i, int j){return a[i] < a[j];}) - v.begin() - 1;
				assert(p >= 0);
				assert(a[v[p]] < a[cur]);
				cur = v[p];
				ans[1].push_back(v[p]);
			}
		}
		for(int _ = 0; _ < 2; ++_) {
			for(int i = 0; i < len; ++i)
				printf("%d%c", ans[_][i], " \n"[i + 1 == len]);
		}
	}
	return 0;
}