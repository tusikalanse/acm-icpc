#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int vis[8][8];
char mp[8][8];
int N, M, T;
inline int abs(int x){return x>0?x:-x;}


int valid(int x, int y){
	if (x < 1) return 0;
	if (x > N) return 0;
	if (y < 1) return 0;
	if (y > M) return 0;
	return 1;
}
int dfs(int x, int y, int s){
	vis[x][y] = 1;
	for(int k = 0; k<4; k++){
		int nx = x + dir[k][0];
		int ny = y + dir[k][1];
		if(valid(nx, ny) && 0 == vis[nx][ny]){
			if (mp[nx][ny] == 'D') {
				if (s == T) return 1;
				continue;
			}
			if (s<T && dfs(nx, ny, s+1)) return 1;
		}
	}
		vis[x][y] = 0;
		return 0;	
}

int main(){
	while(~scanf("%d %d %d", &N, &M, &T) && (N||M||T)){
		int sx, sy, dx, dy;
		getchar();
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				mp[i][j] = getchar();
				if (mp[i][j] == 'S') {sx = i; sy = j;}
				else if (mp[i][j] == 'D') {dx = i; dy = j;}
				else if (mp[i][j] == 'X') vis[i][j] = 1;
			}
			getchar();
		}
		int k = abs(sx - dx) + abs(sy - dy);	
		if ( (k&1) != (T&1) || T<k){puts("NO"); continue;}
		puts(dfs(sx, sy, 1)?"YES":"NO");
		
	}
	
	
	return 0;
}
