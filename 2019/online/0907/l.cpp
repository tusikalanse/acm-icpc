#include <bits/stdc++.h>
using namespace std;
//up, down, left, right, front, back
int ans[1000][1000], vis[1000][1000][6];
int dir[4][2] = {0, -1, 0, 1, 1, 0, -1, 0};

int newsta(int sta, int k) {
	if(sta == 0) {
		if(k == 0)
			return 5;
		if(k == 1)
			return 4;
		if(k == 2)
			return 3;
		if(k == 3)
			return 2;
	}
	if(sta == 1) {
		if(k == 0)
			return 4;
		if(k == 1)
			return 5;
		if(k == 2)
			return 2;
		if(k == 3)
			return 3;
	}
	if(sta == 2) {
		if(k == 0)
			return 2;
		if(k == 1)
			return 2;
		if(k == 2)
			return 0;
		if(k == 3)
			return 1;
	}
	if(sta == 3) {
		if(k == 0)
			return 3;
		if(k == 1)
			return 3;
		if(k == 2)
			return 1;
		if(k == 3)
			return 0;
	}
	if(sta == 4) {
		if(k == 0)
			return 0;
		if(k == 1)
			return 1;
		if(k == 2)
			return 4;
		if(k == 3)
			return 4;
	}
	if(sta == 5) {
		if(k == 0)
			return 1;
		if(k == 1)
			return 0;
		if(k == 2)
			return 5;
		if(k == 3)
			return 5;
	}
}

struct node {
	int x, y, sta, stp;
	node() {
		x = y = sta = stp = 0;
	}
	node(int a, int b, int c, int d) {
		x = a;
		y = b;
		sta = c;
		stp = d;
	}
};

int G[18][18];
long long dp[10 + (1 << 16)];
int x[18], y[18], T, n;

int find(int x, int y) {
	x = abs(x); y = abs(y);
	if(x >= 1000 || y >= 1000) return x + y;
	return ans[x][y];
}

int get(int i, int j) {
	return find(x[j] - x[i], y[j] - y[i]);
}

int main() {
	ans[0][0] = 0;
	queue<node> que;
	que.emplace(0, 0, 0, 0);
	vis[0][0][0] = 1;
	while(!que.empty()) {
		node u = que.front();
		que.pop();
		for(int k = 0; k < 4; ++k) {
			int fx = u.x + dir[k][0], fy = u.y + dir[k][1], fsta = newsta(u.sta, k), fstp = u.stp + 1;
			if(fx >= 0 && fx < 1000 && fy >= 0 && fy < 1000 && !vis[fx][fy][fsta]) {
				vis[fx][fy][fsta] = 1;
				if(fsta == 0)
					ans[fx][fy] = fstp;
				que.emplace(fx, fy, fsta, fstp);
			}
		}
	}
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &x[i], &y[i]);
		}
		for(int i = 0; i < n; ++i) {
			G[i][i] = 0;
			for(int j = i + 1; j < n; ++j) {
				G[i][j] = G[j][i] = get(i, j);
			}
		}
		memset(dp, 0x3f, sizeof(dp));
		for(int i = 0; i < n; ++i)
			dp[1 << i] = find(x[i], y[i]);
		for(int mask = 3; mask < (1 << n); ++mask) {
			for(int i = 0; i < n; ++i) if(mask >> i & 1) {
				for(int j = 0; j < n; ++j) if((mask >> j & 1) && i != j) {
					dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + G[i][j]);
				}
			}
		} 
		printf("%lld\n", dp[(1 << n) - 1]);
	}
	return 0;
}