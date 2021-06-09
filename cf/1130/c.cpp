#include <bits/stdc++.h>
using namespace std;

int vis[55][55], mp[55][55], n, X1, Y1, X2, Y2;
vector<pair<int, int>> s, e;
queue<pair<int, int>> bfs;
int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

int main() {
	scanf("%d%d%d%d%d", &n, &X1, &Y1, &X2, &Y2);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j)
			scanf("%1d", &mp[i][j]);
	}
	vis[X1][Y1] = 1;
	s.emplace_back(X1, Y1);
	bfs.push(make_pair(X1, Y1));
	while(!bfs.empty()) {
		pair<int, int> u = bfs.front();
		bfs.pop();
		for(int k = 0; k < 4; ++k) {
			int fx = u.first + dir[k][0], fy = u.second + dir[k][1];
			if(fx == 0 || fx == n + 1 || fy == 0 || fy == n + 1 || vis[fx][fy] || mp[fx][fy]) continue;
			s.emplace_back(fx, fy);
			bfs.push(make_pair(fx, fy));
			vis[fx][fy] = 1;
		}
	}
	if(vis[X2][Y2]) {
		puts("0");
		return 0;
	}
	vis[X2][Y2] = 1;
	e.emplace_back(X2, Y2);
	bfs.push(make_pair(X2, Y2));
	while(!bfs.empty()) {
		pair<int, int> u = bfs.front();
		bfs.pop();
		for(int k = 0; k < 4; ++k) {
			int fx = u.first + dir[k][0], fy = u.second + dir[k][1];
			if(fx == 0 || fx == n + 1 || fy == 0 || fy == n + 1 || vis[fx][fy] || mp[fx][fy]) continue;
			e.emplace_back(fx, fy);
			bfs.push(make_pair(fx, fy));
			vis[fx][fy] = 1;
		}
	}
	int ans = 1e9;
	for(auto &u: s) {
		for(auto &v: e)
			ans = min(ans, (u.first - v.first) * (u.first - v.first) + (u.second - v.second) * (u.second - v.second));
	}
	printf("%d\n", ans);
	return 0;
}