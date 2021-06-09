#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define LL long long

const int MAXN = 105;
char mp[MAXN][MAXN];
bool vis[2][2][MAXN][MAXN], seen[MAXN][MAXN][2];
int n, m, t, T;
int sx, sy, ex, ey, dx, dy;
int dir[4][2] = {0, -1, 0, 1, 1, 0, -1, 0};
struct node {
	node() {}
	node(int _one, int _two, int _x, int _y, int _s) : one(_one), two(_two), x(_x), y(_y), s(_s) {}
	int one, two;
	int x, y, s;
}tmp;

queue<node> Q;

bool judge(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}

void init() {
	memset(seen, 0, sizeof(seen));
	seen[dx][dy][0] = 1;
	seen[ex][ey][1] = 1;
	for(int x = dx - 1, y = dy; x > 0 && mp[x][y] != 'X' && mp[x][y] != 'E'; x--)
		seen[x][y][0] = 1;
	for(int x = dx + 1, y = dy; x <= n && mp[x][y] != 'X' && mp[x][y] != 'E'; x++)
		seen[x][y][0] = 1;
	for(int x = dx, y = dy - 1; y > 0 && mp[x][y] != 'X' && mp[x][y] != 'E'; y--)
		seen[x][y][0] = 1;
	for(int x = dx, y = dy + 1; y <= m && mp[x][y] != 'X' && mp[x][y] != 'E'; y++)
		seen[x][y][0] = 1;
	for(int x = ex - 1, y = ey; x > 0 && mp[x][y] != 'X' && mp[x][y] != 'D'; x--)
		seen[x][y][1] = 1;
	for(int x = ex + 1, y = ey; x <= n && mp[x][y] != 'X' && mp[x][y] != 'D'; x++)
		seen[x][y][1] = 1;
	for(int x = ex, y = ey - 1; y > 0 && mp[x][y] != 'X' && mp[x][y] != 'D'; y--)
		seen[x][y][1] = 1;
	for(int x = ex, y = ey + 1; y <= m && mp[x][y] != 'X' && mp[x][y] != 'D'; y++)
		seen[x][y][1] = 1;
}

int bfs() {
	memset(vis, 0, sizeof(vis));
	while(!Q.empty())
		Q.pop();
	if(seen[sx][sy][0] && seen[sx][sy][1])
		tmp = node(1, 1, sx, sy, 0);
	else if(seen[sx][sy][0])
		tmp = node(1, 0, sx, sy, 0);
	else if(seen[sx][sy][1])
		tmp = node(0, 1, sx, sy, 0);
	else
		tmp = node(0, 0, sx, sy, 0);
	Q.push(tmp);
	vis[tmp.one][tmp.two][tmp.x][tmp.y] = 1;
	while(!Q.empty()) {
		tmp = Q.front();
		Q.pop();
		if(tmp.s > t)
			return -1;
		if(tmp.one == 1 && tmp.two == 1)
			return tmp.s;
		for(int k = 0; k < 4; ++k) {
			int fx = tmp.x + dir[k][0], fy = tmp.y + dir[k][1], fs = tmp.s + 1, fone = tmp.one | seen[fx][fy][0], ftwo = tmp.two | seen[fx][fy][1];
			if(judge(fx, fy) && mp[fx][fy] == '.' && !vis[fone][ftwo][fx][fy]) {
				vis[fone][ftwo][fx][fy] = 1;
				Q.push(node(fone, ftwo, fx, fy, fs));
			}
		}
	}
	return -1;
}

void input() {
	cin >> n >> m >> t;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cin >> mp[i][j];
			if(mp[i][j] == 'D')
				dx = i, dy = j;
			else if(mp[i][j] == 'E')
				ex = i, ey = j;
			else if(mp[i][j] == 'S') {
				sx = i, sy = j; 
				mp[i][j] = '.';
			}
		}
	}
}

int main() {
	cin >> T;
	for(int i = 1; i <= T; ++i) {
		input();
		init();
		cout << "Case " << i << ":" << endl;
		cout << bfs() << endl;
	}
	return 0;
}