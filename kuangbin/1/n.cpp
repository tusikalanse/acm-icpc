#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAXN 205
using namespace std;

struct node
{
	int x, y, step1, step2, vis1, vis2;
	char ch;
	void init(){
		vis1 = vis2 = step1 = step2 = 0;
	}
}mp[MAXN][MAXN], temp;

int dir[4][2] = {1, 0, -1 ,0, 0, 1, 0, -1};
int n, m;

int main(){
	int x1, y1, x2, y2, ans;
	while(~scanf("%d %d", &n, &m)){
		ans = 0x3f3f3f3f;
		getchar();
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				mp[i][j].ch = getchar();
				mp[i][j].init();
				mp[i][j].x = i;
				mp[i][j].y = j;
				if(mp[i][j].ch == '#')
					mp[i][j].vis1 = mp[i][j].vis2 = 1;
				else if(mp[i][j].ch == 'Y'){
					x1 = i;
					y1 = j;
					mp[i][j].vis1 = mp[i][j].vis2 = 1;
				}
				else if(mp[i][j].ch == 'M'){
					x2 = i;
					y2 = j;
					mp[i][j].vis1 = mp[i][j].vis2 = 1;
				}
			}
			getchar();
		}
		queue<node> bfs;
		bfs.push(mp[x1][y1]);
		while(!bfs.empty()){
			temp = bfs.front();
			bfs.pop();
			for (int k = 0; k < 4; ++k){
				int nx = temp.x + dir[k][0], ny = temp.y + dir[k][1];
				if(nx>0 && nx<=n && ny>0 && ny<=m && mp[nx][ny].vis1 == 0){
					mp[nx][ny].vis1 = 1;
					mp[nx][ny].step1 = temp.step1 + 1;
					bfs.push(mp[nx][ny]);
				}
			}
		}
		queue<node> bfs2;
		bfs2.push(mp[x2][y2]);
		while(!bfs2.empty()){
			temp = bfs2.front();
			bfs2.pop();
			for (int k = 0; k < 4; ++k){
				int nx = temp.x + dir[k][0], ny = temp.y + dir[k][1];
				if(nx>0 && nx<=n && ny>0 && ny<=m && mp[nx][ny].vis2 == 0){
					mp[nx][ny].vis2 = 1;
					mp[nx][ny].step2 = temp.step2 + 1;
					bfs2.push(mp[nx][ny]);
				}
			}
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(mp[i][j].ch == '@'){
					if(mp[i][j].step1 && mp[i][j].step2)
						ans = min(ans, mp[i][j].step1 + mp[i][j].step2);
				}
			}
		}
		printf("%d\n", ans*11);
	}
	return 0;
}