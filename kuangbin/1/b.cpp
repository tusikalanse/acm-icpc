#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int L, R, C;
char mp[35][35][35]; 
int vis[35][35][35];
struct node
{
	int x, y, z, s;
}start, end, temp, t;
queue<node> bfs;
int dir[6][3] = {0, 0, 1, 0, 0, -1, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0};

int check(int x, int y, int z){
	if(x < 1 || x > L || y < 1 || y > R || z < 1 || z > C)
		return 0;
	return 1;
}


int main(int argc, char const *argv[])
{
	while(~scanf("%d %d %d", &L, &R, &C) && L){
		getchar();
		int ans = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i<=L; i++){
			for(int j = 1; j<=R; j++){
				for(int k = 1; k<=C; k++){
					mp[i][j][k] = getchar();
					switch(mp[i][j][k]){
						case '#':
							vis[i][j][k] = 1;
							break;
						case 'S':
							start.x = i;
							start.y = j;
							start.z = k;
							break;
						case 'E':
							end.x = i;
							end.y = j;
							end.z = k;
							vis[i][j][k] = 2;
							break;
						case '.':
							break;
					}
				}
				getchar();
			}
			getchar();
		}
		start.s = 0;
		bfs.push(start);
		while(!bfs.empty()){
			temp = bfs.front();
			bfs.pop();
			for(int u = 0; u<6; u++){
				int nx = temp.x + dir[u][0], ny = temp.y + dir[u][1], nz = temp.z + dir[u][2];
				if(check(nx, ny, nz) && vis[nx][ny][nz] != 1){
					t.x = nx;
					t.y = ny;
					t.z = nz;
					t.s = temp.s+1;
					if(vis[nx][ny][nz] == 2){
						ans = t.s;
						goto nxt;
					}
					else {
						vis[nx][ny][nz] = 1;
						bfs.push(t);
					}
				}		
			}
		}
		nxt:;
		while(!bfs.empty()) bfs.pop();
		if(ans == 0)
			puts("Trapped!");
		else
			printf("Escaped in %d minute(s).\n", ans);
	}
	return 0;
}