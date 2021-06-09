#include <bits/stdc++.h>
using namespace std;

long long dis[1010][505], ans;

int a[1010], b[1010], n, m, s, t, c, x, y;

struct edge {
	int to, id, cost;
};
vector<edge> G[1010][505];
vector<int> subway[1010];

struct node {
	long long dis;
	int id1, id2;
	bool operator<(const node &rhs) const {
		return dis > rhs.dis;
	}
};

priority_queue<node> pq;

void dijk() {
	if(s == t) {
		ans = 0;
		return;
	}
	for(int i = 0; i < subway[s].size(); ++i) {
		pq.push({a[subway[s][i]], s, subway[s][i]});
	}
	while(!pq.empty()) {
		node u = pq.top();
		pq.pop();
		if(u.dis > dis[u.id1][u.id2]) continue;
		//cout << "processing " << u.id1 << " " << u.id2 << " " << u.dis << endl;
		for(edge e : G[u.id1][u.id2]) {
			//cout << "to " << e.to << " " << e.id << endl;
			if(dis[e.to][e.id] > u.dis + e.cost) {
				dis[e.to][e.id] = u.dis + e.cost;
				pq.push({dis[e.to][e.id], e.to, e.id});
			}
		}
	}
	for(int i = 0; i < subway[t].size(); ++i) {
		ans = min(ans, dis[t][subway[t][i]]);
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	memset(dis, 0x3f, sizeof(dis));
	ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c);
		scanf("%d", &y);
		subway[y].push_back(i);
		for(int _ = 2; _ <= c; ++_) {
			scanf("%d", &x);
			subway[x].push_back(i);
			G[x][i].push_back({y, i, b[i]});
			G[y][i].push_back({x, i, b[i]});
			y = x;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int x = 0; x < subway[i].size(); ++x) {
			for(int y = x + 1; y < subway[i].size(); ++y) {
				G[i][subway[i][x]].push_back({i, subway[i][y], a[subway[i][y]]});
				G[i][subway[i][y]].push_back({i, subway[i][x], a[subway[i][x]]});
			}
		}
	}
	dijk();
	printf("%lld\n", ans == 0x3f3f3f3f3f3f3f3f ? -1 : ans);
	return 0;
}