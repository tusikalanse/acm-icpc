#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;


const int MAXN = 102;
int vis[MAXN][MAXN];
char mat[MAXN][MAXN];
int dir[8][2] = {1, 1, 0, 1, 0, -1, 1, -1, 1, 0, -1, 1, -1, 0, -1, -1};

struct coor{int x, y;}a[MAXN*MAXN], t;
int main(){
	int m, n, ans;
	while(scanf("%d %d", &m, &n) && m){
		ans = 0;
		getchar();
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i<=m; i++){
			for(int j = 1; j<=n; j++){
				mat[i][j] = getchar();
				if(mat[i][j] == '*') vis[i][j] = 1;
			}
			getchar();
		}
		queue<coor> bfs;
		for(int i = 1; i<=m; i++)
			for(int j = 1; j<=n; j++)
				{
					if(vis[i][j] == 0){
						a[i*MAXN+j].x = i;
						a[i*MAXN+j].y = j;
						bfs.push(a[i*MAXN+j]);
						ans++;
						vis[i][j] = 1;
						while(!bfs.empty()){
								t = bfs.front();
								bfs.pop();
								for(int u = 0; u<8; u++){
									int nx = t.x + dir[u][0], ny = t.y + dir[u][1];
									if(nx>0 && nx <= m && ny>0 && ny<=n && vis[nx][ny] == 0){
										a[nx*MAXN+ny].x = nx;
										a[nx*MAXN+ny].y = ny;
										bfs.push(a[nx*MAXN+ny]);
										vis[nx][ny] = 1;
									}						
							}
					}
				}
			}
	printf("%d\n", ans);
	}
		return 0;
}
		
	
