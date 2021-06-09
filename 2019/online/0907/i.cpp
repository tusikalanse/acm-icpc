#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int c[N], a[N], pos[N], l, r;
vector<int> v[N];
vector<pair<int, int>> que[N];
int ans[N], n, m;

void update(int i, int val) {
	for(; i <= n; i += i & -i)
		c[i] += val;
}

int query(int i) {
	int ans = 0;
	for(; i; i -= i & -i)
		ans += c[i];
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		int t = a[i];
		for(int j = t + t; j <= n; j += t) {
			if(pos[j] >= i) 
				v[i].push_back(pos[j]);
			else
				v[pos[j]].push_back(i);
			update(max(i, pos[j]), 1);
		}
	}
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &l, &r);
		que[l].emplace_back(r, i);
	}
	for(int i = 1; i <= n; ++i) {
		for(auto f: que[i]) {
			ans[f.second] = query(f.first);
		}
		for(auto j: v[i]) {
			update(j, -1);
		}
	}
	for(int i = 1; i <= m; ++i) 
		printf("%d\n", ans[i]);
	return 0;
}