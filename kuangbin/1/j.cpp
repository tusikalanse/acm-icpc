#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define INF 1000000009
#define MAXN 1006

struct node
{
	int x, y, time, vis, step;
	char ch;
	void init(){
		time = INF;
		vis = step = 0;
		return;
	}
}mp[MAXN][MAXN], temp;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int main(){
	int T, n, m, ans;
	int sx, sy;
	scanf("%d", &T);
	while(T--){
		ans = 0;
		scanf("%d %d", &n, &m);
		getchar();
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				mp[i][j].ch = getchar();
				mp[i][j].x = i;
				mp[i][j].y = j;
				mp[i][j].init();
				if(mp[i][j].ch == 'J'){
					sx = i;
					sy = j;
					mp[i][j].vis = 1;
				}
				else if(mp[i][j].ch == 'F'){
					mp[i][j].time = 0;
				}
			}
			getchar();
		}
		queue<node> bfs;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(mp[i][j].ch == 'F')
					bfs.push(mp[i][j]);
			}
		}
		while(!bfs.empty()){
			temp = bfs.front();
			bfs.pop();
			for(int k = 0; k<4; k++){
				int nx = temp.x + dir[k][0], ny = temp.y + dir[k][1];
				if(nx>0 && nx<=n && ny>0 && ny<=m && mp[nx][ny].ch != '#' && mp[nx][ny].time == INF){
					mp[nx][ny].time = temp.time + 1;
					bfs.push(mp[nx][ny]);
				}
			}
		}
		bfs.push(mp[sx][sy]);
		while(!bfs.empty()){
			temp = bfs.front();
			if(temp.x == 1 || temp.x == n || temp.y == 1 || temp.y == m){
				ans = temp.step + 1;
				break;
			}
			bfs.pop();
			for(int k = 0; k<4; k++){
				int nx = temp.x + dir[k][0], ny = temp.y + dir[k][1];
				if(nx>0 && nx<=n && ny>0 && ny<=m && mp[nx][ny].ch != '#' && mp[nx][ny].vis == 0 && temp.step < mp[nx][ny].time - 1){
					mp[nx][ny].vis = 1;
					mp[nx][ny].step = temp.step + 1;
					bfs.push(mp[nx][ny]);
				}
			}
		}
		if(ans == 0) puts("IMPOSSIBLE");
		else
			printf("%d\n", ans);
	}
	return 0;
}