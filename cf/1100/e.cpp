#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<pair<pair<int, int>, int>> G[N];
int n, m, deg[N], val[N], ans, l, r, x, y, v, id[N];

bool check(int k) {
	int cnt = 0;
	memset(deg, 0, sizeof(deg));
	for(int i = 1; i <= n; ++i) {
		for(auto &it: G[i]) {
			if(it.first.second > k)
				deg[it.first.first]++;
		}
	}
	queue<int> topo;
	for(int i = 1; i <= n; ++i) {
		if(deg[i] == 0)
			topo.push(i);
	}
	while(!topo.empty()) {
		int u = topo.front();
		topo.pop();
		cnt++;
		for(auto &it: G[u]) {
			if(it.first.second > k) {
				if(--deg[it.first.first] == 0)
					topo.push(it.first.first);
			}
		}
	}
	return cnt == n;
}

void get_ans(int k) {
	int cnt = 0, ans = 0;
	vector<int> res;
	memset(deg, 0, sizeof(deg));
	for(int i = 1; i <= n; ++i) {
		for(auto &it: G[i]) {
			if(it.first.second > k)
				deg[it.first.first]++;
		}
	}
	queue<int> topo;
	for(int i = 1; i <= n; ++i) {
		if(deg[i] == 0)
			topo.push(i);
	}
	while(!topo.empty()) {
		int u = topo.front();
		topo.pop();
		id[u] = ++cnt;
		cnt++;
		for(auto &it: G[u]) {
			if(it.first.second > k) {
				if(--deg[it.first.first] == 0)
					topo.push(it.first.first);
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(auto &it: G[i]) {
			if(it.first.second <= k) {
				if(id[i] > id[it.first.first]) {
					ans++;
					res.push_back(it.second);
				}
			}
		}
	}
	printf("%d\n", ans);
	for(int i = 0; i < res.size(); ++i) {
		printf("%d%c", res[i], " \n"[i == res.size() - 1]);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &x, &y, &v);
		G[x].push_back(make_pair(make_pair(y, v), i));
		val[i] = v;
	}
	sort(val + 1, val + m + 1);
	l = 0, r = m, ans = val[m];
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(val[mid])) {
			ans = val[mid];
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	printf("%d ", ans);
	get_ans(ans);
	return 0;
}