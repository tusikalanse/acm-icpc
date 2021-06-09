#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int vis[N][N];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int T, n, m, q, x, y, ans, _;

bool check(int x, int y, int k) {
	int fx = x + dir[k][0], fy = y + dir[k][1];
	if(fx < 1 || fx > n || fy < 1 || fy > m) return 0;
	return vis[fx][fy] == _;
}

bool check(int x, int y) {
	return (check(x, y, 0) + check(x, y, 1) >= 1) && (check(x, y, 2) + check(x, y, 3) >= 1); 
}

int main() {
	scanf("%d", &T);
	for(_ = 1; _ <= T; ++_) {
		scanf("%d%d%d", &n, &m, &q);
		while(q--) {
			scanf("%d%d", &x, &y);
			ans = 0;
			if(vis[x][y] != _) {
				ans++;
				queue<pair<int, int>> que;
				que.push({x, y});
				vis[x][y] = _;
				while(!que.empty()) {
					pair<int, int> now = que.front();
					que.pop();
					for(int k = 0; k < 4; ++k) {
						int fx = now.first + dir[k][0], fy = now.second + dir[k][1];
						if(vis[fx][fy] == _) continue;
						if(fx < 1 || fx > n || fy < 1 || fy > m) continue;
						if(check(fx, fy)) {
							vis[fx][fy] = _;
							que.push({fx, fy});
							ans++;
						}
					}
				}
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}