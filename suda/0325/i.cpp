#include <bits/stdc++.h>
using namespace std;

char mp[1005][1005];
int door[1005][1005][4], vis[1005][1005][4];
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

struct point
{
	int x, y, s, stat;
}temp;

int f(int direct, int stat) {
	if(stat == 0)
		return direct;
	if(stat == 2)
		return direct^1;
	if(stat == 3) {
		if(direct == 0)
			return 2;
		if(direct == 1)
			return 3;
		if(direct == 2)
			return 1;
		if(direct == 3)
			return 0;
	}
	if(stat == 1){
		if(direct == 0)
			return 3;
		if(direct == 1)
			return 2;
		if(direct == 2)
			return 0;
		if(direct == 3)
			return 1;
	}
	return 0;
}


int main() {
	int n, m, xt, yt, xm, ym;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%s", &mp[i][1]);
	}
	scanf("%d %d %d %d", &xt, &yt, &xm, &ym);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			switch(mp[i][j]) {
				case '+':
					door[i][j][0] = door[i][j][1] = door[i][j][2] = door[i][j][3] = 1;
					break;
				case '-':
					door[i][j][2] = door[i][j][3] = 1;
					break;
				case '|':
					door[i][j][0] = door[i][j][1] = 1;
					break;
				case '^':
					door[i][j][0] = 1;
					break;
				case 'v':
					door[i][j][1] = 1;
					break;
				case '<':
					door[i][j][2] = 1;
					break;
				case '>':
					door[i][j][3] = 1;
					break;
				case 'L':
					door[i][j][0] = door[i][j][1] = door[i][j][3] = 1;
					break;
				case 'R':
					door[i][j][0] = door[i][j][1] = door[i][j][2] = 1;
					break;
				case 'U':
					door[i][j][1] = door[i][j][2] = door[i][j][3] = 1;
					break;
				case 'D':
					door[i][j][0] = door[i][j][2] = door[i][j][3] = 1;
					break;
				default:
					;
			}
		}
	}
	temp.x = xt;
	temp.y = yt;
	temp.s = 0;
	temp.stat = 0;
	vis[xt][yt][0] = 1;
	queue<point> bfs;
	bfs.push(temp);
	while(!bfs.empty()) {
		point u = bfs.front();
		bfs.pop();
		if(u.x == xm && u.y == ym) {
			//printf("%d\n", u.stat);
			printf("%d\n", u.s);
			return 0;
		}
		for(int i = 0; i < 4; i++) {
			int fx = u.x + dir[i][0], fy = u.y + dir[i][1];
			if(door[u.x][u.y][f(i, u.stat)] && fx > 0 && fx <= n && fy > 0 && fy <= m && !vis[fx][fy][u.stat] && door[fx][fy][f(i, u.stat)^1]) {
				temp.x = fx;
				temp.y = fy;
				temp.s = u.s + 1;
				temp.stat = u.stat;
				vis[temp.x][temp.y][temp.stat] = 1;
				bfs.push(temp);
			}
		}
		if(!vis[u.x][u.y][(u.stat+3)%4]) {
			temp.x = u.x;
			temp.y = u.y;
			temp.s = u.s + 1;
			temp.stat = (u.stat+3)%4;
			vis[temp.x][temp.y][temp.stat] = 1;
			bfs.push(temp);
		}
	}
	printf("-1\n");
	return 0;
}