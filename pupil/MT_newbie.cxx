#include <bits/stdc++.h>
using namespace std;

int n, tot, mp[8][8];
int dir[8][2] = {1, 2, 2, 1, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1};

struct node {
	int x, y;
} a[65];

bool check(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return 0;
	if (mp[x][y]) return 0;
	return 1;
}

void dfs(int x, int y, int step) {
	if (step == n * n) {
		for (int i = 0; i < n * n; ++i)
			printf("(%d, %d) ", a[i].x, a[i].y);
		puts("");
		tot++;
		return;
	} 
	for (int i = 0; i < 8; ++i) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (check(nx, ny)) {
			a[step].x = nx, a[step].y = ny;
			mp[nx][ny] = 1;
			dfs(nx, ny, step + 1);
			mp[nx][ny] = 0;
		}
	}
}

int main() {
	scanf("%d", &n); 
	int x, y;
	scanf("%d%d", &x, &y);
	mp[x][y] = 1;
	a[0].x = x, a[0].y = y;
	dfs(x, y, 1);
	printf("%d\n", tot);
	return 0;
}
