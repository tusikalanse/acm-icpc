#include <bits/stdc++.h>
using namespace std;

int T;
int x[4], y[4];
int xx[4], yy[4], dx, dy;
int vis[10][10];

int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

void bfs(int i, int j) {
	vis[i][j] = 1;
	for(int k = 0; k < 4; ++k) {
		int x = i + dir[k][0], y = j + dir[k][1];
		if(x >= 0 && x <= 8 && y >= 0 && y <= 8 && !vis[x][y])
			bfs(x, y);
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d%d%d%d%d", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]);
		for(int i = 0; i < 4; ++i) {
			xx[i] = x[i];
			yy[i] = y[i];
		}
		sort(xx, xx + 4);
		dx = unique(xx, xx + 4) - xx;
		for(int i = 0; i < 4; ++i) {
			x[i] = (lower_bound(xx, xx + dx, x[i]) - xx + 1) * 2 - 1;
		}
		sort(yy, yy + 4);
		dy = unique(yy, yy + 4) - yy;
		for(int i = 0; i < 4; ++i) {
			y[i] = (lower_bound(yy, yy + dy, y[i]) - yy + 1) * 2 - 1;
		}
		int ans = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = x[0]; i <= x[1]; ++i) 
			vis[i][y[0]] = vis[i][y[1]] = 1;
		for(int i = y[0]; i <= y[1]; ++i)
			vis[x[0]][i] = vis[x[1]][i] = 1;
		for(int i = x[2]; i <= x[3]; ++i) 
			vis[i][y[2]] = vis[i][y[3]] = 1;
		for(int i = y[2]; i <= y[3]; ++i)
			vis[x[2]][i] = vis[x[3]][i] = 1;
		for(int i = 0; i <= 8; ++i) {
			for(int j = 0; j <= 8; ++j) {
				if(!vis[i][j]) {
					bfs(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}