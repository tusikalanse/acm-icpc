#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

struct node
{
	int vis;
	int s, x, y;
	pair<int, int> fa;
}mp[5][5], temp;
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int ans[30][2];

int main(){
	int step, x, y, x1, y1;
	for(int i = 0; i<5; i++)
		for(int j = 0; j<5; j++){
			scanf("%d", &mp[i][j].vis);
			mp[i][j].x = i;
			mp[i][j].y = j;
		}
	mp[0][0].s = 0;
	memset(ans, 0, sizeof(ans));
	queue<node> bfs;
	bfs.push(mp[0][0]);
	while(!bfs.empty()){
		temp = bfs.front();
		bfs.pop();
		for(int k = 0; k<4; k++){
			int nx = temp.x + dir[k][0], ny = temp.y + dir[k][1];
			if(nx>=0 && nx<5 && ny>=0 && ny<5 && mp[nx][ny].vis == 0){
				mp[nx][ny].vis = 1;
				mp[nx][ny].s = temp.s + 1;
				mp[nx][ny].fa.first = temp.x;
				mp[nx][ny].fa.second = temp.y;
				bfs.push(mp[nx][ny]);
			}
		}
	}
	step = mp[4][4].s;
	x = mp[4][4].x;
	y = mp[4][4].y;
	while(x || y){
		x1 = x;
		y1 = y;
		ans[step][0] = mp[x][y].x;
		ans[step][1] = mp[x][y].y;
		step--;
		x = mp[x1][y1].fa.first;
		y = mp[x1][y1].fa.second;
	}
	for(int i = 0; i<=mp[4][4].s; i++)
		printf("(%d, %d)\n", ans[i][0], ans[i][1]);
	return 0;
}