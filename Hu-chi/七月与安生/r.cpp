#include <bits/stdc++.h>
#define LL long long
using namespace std;

double ans, sum;
int n, m, r, k;

struct node {
	int x, y;
	bool operator< (const node &rhs) const {
		return v() < rhs.v();
	}
	LL v() const {
		return 1LL * min(min(r, n + 1 - r), min(x, n + 1 - x)) * min(min(r, m + 1 - r), min(y, m + 1 - y));
	}
};

map<int, bool> vis[100010];
priority_queue<node> q;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void bfs() {
	vis[(n + 1) >> 1][(m + 1) >> 1] = 1;
	q.push({(n + 1) >> 1, (m + 1) >> 1});
	while(!q.empty()) {
		node u = q.top();
		q.pop();
		k--;
		ans += u.v() / sum;
		if(k == 0)
			return;
		for(int i = 0; i < 4; ++i) {
			int nx = u.x + dir[i][0], ny = u.y + dir[i][1];
			if(nx < 1 || ny < 1 || nx > n || ny > m)
				continue;
			if(vis[nx][ny]) {
				continue;
			}
			vis[nx][ny] = 1;
			q.push({nx, ny});
        }
	}
}

int main() {
	cin >> n >> m >> r >> k;
	sum = 1LL * (n + 1 - r) * (m + 1 - r);
	bfs();
	printf("%.12f\n", ans);
	return 0;
}