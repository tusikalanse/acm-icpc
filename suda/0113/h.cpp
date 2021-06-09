#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 205;
int vis[MAXN][MAXN], step[MAXN][MAXN];
char mat[MAXN][MAXN];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
struct coor{int x, y, s;}a[MAXN*MAXN], t;
int main(){
	int n, m, ans, temp, x1, y1, x2, y2;
	while(~scanf("%d %d", &n, &m)){
		getchar();
		memset(step, 0, sizeof(step));
		ans = 0X3f3f3f3f;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				mat[i][j] = getchar();
				switch (mat[i][j]){
					case '#':
						vis[i][j] = 1;
						break;
					case '@':
						vis[i][j] = 2;
						break;
					case 'Y':
						x1 = i, y1 = j;
						vis[i][j] = 1;
						break;
					case 'M':
						x2 = i, y2 = j;
						vis[i][j] = 1;
						break;
					default :
						vis[i][j] = 0;	
				}
			}
			getchar();
		}
		queue<coor> bfs;
		a[x1*MAXN+y1].x = x1;
		a[x1*MAXN+y1].y = y1;
		a[x1*MAXN+y1].s = 0;
		bfs.push(a[x1*MAXN+y1]);
		while(!bfs.empty()){
			t = bfs.front();
			bfs.pop();
			for(int u = 0; u<4; u++){
				int nx = t.x + dir[u][0], ny = t.y + dir[u][1];
				if(nx>0 && nx <= n && ny>0 && ny<=m && vis[nx][ny] != 1){
					a[nx*MAXN+ny].x = nx;
					a[nx*MAXN+ny].y = ny;
					a[nx*MAXN+ny].s = t.s+1;
					if(mat[nx][ny] == '@') step[nx][ny] += a[nx*MAXN+ny].s;
					bfs.push(a[nx*MAXN+ny]);
					vis[nx][ny] = 1;
				}						
			}
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				switch (mat[i][j]){
					case '#':
						vis[i][j] = 1;
						break;
					case '@':
						vis[i][j] = 2;
						break;
					case 'Y':
						x1 = i, y1 = j;
						vis[i][j] = 1;
						break;
					case 'M':
						x2 = i, y2 = j;
						vis[i][j] = 1;
						break;
					default :
						vis[i][j] = 0;	
				}
			}
		}
		a[x2*MAXN+y2].x = x2;
		a[x2*MAXN+y2].y = y2;
		a[x2*MAXN+y2].s = 0;
		bfs.push(a[x2*MAXN+y2]);
		while(!bfs.empty()){
			t = bfs.front();
			bfs.pop();
			for(int u = 0; u<4; u++){
				int nx = t.x + dir[u][0], ny = t.y + dir[u][1];
				if(nx>0 && nx <= n && ny>0 && ny<=m && vis[nx][ny] != 1){
					a[nx*MAXN+ny].x = nx;
					a[nx*MAXN+ny].y = ny;
					a[nx*MAXN+ny].s = t.s+1;
					if(mat[nx][ny] == '@') step[nx][ny] += a[nx*MAXN+ny].s;
					bfs.push(a[nx*MAXN+ny]);
					vis[nx][ny] = 1;
				}						
			}
		}
		for(int i = 1; i<=n; i++)
			for(int j = 1; j<=m; j++)
				if(step[i][j])
					ans = min(ans, step[i][j]);
		printf("%d\n", ans*11);
	}
	return 0;
}