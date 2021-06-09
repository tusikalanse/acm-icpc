#include <bits/stdc++.h>
using namespace std;

const int MAXN = 405;
int val[MAXN][MAXN], dis[MAXN], vis[MAXN];
int T, n, m, k, W, w, s, t, op;

struct node {
	int id, d;
	bool operator<(const node &rhs) const {
		return id > rhs.id;
	}
};

vector<pair<int,int>> toerase;
bool hd;

void dfs(int id, int des) {
	if(hd) return;
	if(id == des) {
		hd = 1;
		return;
	}
	for(int i = des; hd == 0 && i > id; --i) {
		if(dis[i] - dis[id] == val[id][i]) {
			toerase.push_back(make_pair(id, i));
			dfs(i, des);
			if(!hd)
				toerase.pop_back();
		}
	}
}

int dijk() {
	memset(dis, -1, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<node> q;
	q.push({0, 0});
	dis[0] = 0;
	vis[0] = 1;
	while(!q.empty()) {
		node u = q.top();
		q.pop();
		vis[u.id] = 1;
		if(dis[u.id] > u.d) continue;
		for(int i = u.id + 1; i <= 2 * n; ++i) if(vis[i] == 0) {
			if(dis[i] < dis[u.id] + val[u.id][i]) {
				dis[i] = dis[u.id] + val[u.id][i];
				q.push({i, dis[i]});
			}
		}
	}
	int mmax = dis[2 * n], id = 2 * n;
	if(mmax < dis[2 * n - 1]) {
		mmax = dis[2 * n - 1];
		id = 2 * n - 1;
	}
	toerase.resize(0);
	hd = 0;
	dfs(0, id);
	for(auto it : toerase) {
		val[it.first][it.second] = 0;
	}
	return mmax;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(val, 0, sizeof(val));
		scanf("%d%d%d%d", &n, &m, &k, &W);
		while(m--) {
			scanf("%d%d%d%d", &s, &t, &w, &op);
			if(op == 0) {
				val[2 * s][2 * t] = w - W;
				val[2 * s - 1][2 * t] = w;
			}
			else {
				val[2 * s - 1][2 * t - 1] = w - W;
				val[2 * s][2 * t - 1] = w;
			}
		}
		int ans = 0;
		while(k--) {
			ans += dijk();
		}
		printf("%d\n", ans);
	}
	return 0;
}