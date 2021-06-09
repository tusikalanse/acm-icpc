#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
	int x, y, vis, step;
	char ch;
	void init(){
		vis = step = 0;
		return;
	}
}mp[12][12], temp;
int n, m;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int main(){
	int T, ans, flag;
	scanf("%d", &T);
	for(int iiiii = 1; iiiii<=T; iiiii++){
		printf("Case %d: ", iiiii);
		ans = 10000;
		scanf("%d %d", &n, &m);
		getchar();
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				mp[i][j].x = i;
				mp[i][j].y = j;
				mp[i][j].ch = getchar();
				mp[i][j].init();
			}
			getchar();
		}
		queue<node> bfs;
		for(int i1 = 1; i1<=n; i1++){
			for(int j1 = 1; j1<=m; j1++){
				if(mp[i1][j1].ch == '#'){
					for(int i2 = 1; i2<=n; i2++){
						for(int j2 = 1; j2<=m; j2++){
							if(mp[i2][j2].ch == '#'){
								for(int u = 1; u<=n; u++) for(int v = 1; v<=m; v++) mp[u][v].vis = 0;
								mp[i1][j1].vis = 1;
								mp[i1][j1].step = 0;
								mp[i2][j2].vis = 1;
								mp[i2][j2].step = 0;
								bfs.push(mp[i1][j1]);
								bfs.push(mp[i2][j2]);
								flag = 0;
								while(!bfs.empty()){
									temp = bfs.front();
									bfs.pop();
									for(int k = 0; k<4; k++){
										int nx = temp.x + dir[k][0], ny = temp.y + dir[k][1];
										if(nx > 0 && nx <= n && ny > 0 && ny <=m && mp[nx][ny].ch == '#' && mp[nx][ny].vis == 0){
											mp[nx][ny].vis = 1;
											mp[nx][ny].step = temp.step + 1;
											bfs.push(mp[nx][ny]);
										}
									}
								}
								for(int i = 1; i<=n; i++){
									for(int j = 1; j<=m; j++){
										if(mp[i][j].ch == '#' && mp[i][j].vis == 0)
											flag = 1;
										mp[i][j].init();
									}
								}
								if(flag == 0)
									ans = min(ans, temp.step);
							}
						}
					}
				}
			}
		}
		if(ans == 10000) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}