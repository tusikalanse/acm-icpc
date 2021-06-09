#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
struct node
{
	int x, y, z, s, vis;
	char ch;
	void init(){
		x = y = z = s = vis = 0;
	}
}mp[2][12][12], temp;

int main(){
	int T, n, m, Time, flag = 1;
	scanf("%d", &T);
	while(T--){
		flag = 1;
		scanf("%d %d %d", &n, &m, &Time);
		getchar();
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				mp[0][i][j].init();
				mp[0][i][j].ch = getchar();
				if(mp[0][i][j].ch == '*')
					mp[0][i][j].vis = 1;
				mp[0][i][j].x = 0;
				mp[0][i][j].y = i;
				mp[0][i][j].z = j;
			}
			getchar();
		}
		getchar();
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				mp[1][i][j].init();
				mp[1][i][j].ch = getchar();
				if(mp[1][i][j].ch == '*')
					mp[1][i][j].vis = 1;
				mp[1][i][j].x = 1;
				mp[1][i][j].y = i;
				mp[1][i][j].z = j;
			}
			getchar();
		}
		queue<node> bfs;
		mp[0][0][0].vis = 1;
		bfs.push(mp[0][0][0]);
		while(!bfs.empty()){
			temp = bfs.front();
			bfs.pop();
			if(temp.s > Time){
				puts("NO");
				flag = 0;
				goto nxt;
			}
			if(temp.ch == 'P'){
				puts("YES");
				flag = 0;
				goto nxt;
			}
			for(int k = 0; k<4; k++){
				int nx = temp.x, ny = temp.y + dir[k][0], nz = temp.z + dir[k][1];
				if(ny>=0 && ny<n && nz>=0 && nz<m){
					if(mp[nx][ny][nz].ch == '#'){
						nx ^= 1;
						if(mp[nx][ny][nz].ch == '#')
							continue;
					}
					if(!mp[nx][ny][nz].vis){
						mp[nx][ny][nz].vis = 1;
						mp[nx][ny][nz].s = temp.s+1;
						bfs.push(mp[nx][ny][nz]);
					}
				}
			}
		}
		nxt:;
		if(flag)
			puts("NO");
	}
	return 0;
}