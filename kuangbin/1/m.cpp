#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAXN 106
using namespace std;

struct node
{
	int a, b, c, vis, step;
	void init(){
		vis = step = 0;
	}
}mp[MAXN][MAXN][MAXN], temp;

int main(){
	int s, n, m, ans, half;
	for(int i = 0; i<MAXN; i++)
		for(int j = 0; j<MAXN; j++)
			for(int k = 0; k<MAXN; k++){
				mp[i][j][k].a = i;
				mp[i][j][k].b = j;
				mp[i][j][k].c = k;
			}
	while(~scanf("%d %d %d", &s, &n, &m) && s){
		if(s&1){
			puts("NO");
			continue;
		}
		half = s >> 1;
		for(int i = 0; i<=s; i++)
			for(int j = 0; j<=n; j++)
				for(int k = 0; k<=m; k++)
					mp[i][j][k].init();
		mp[s][0][0].vis = 1;
		queue<node> bfs;
		bfs.push(mp[s][0][0]);
		while(!bfs.empty()){
			temp = bfs.front();
			if((temp.a == half && temp.b == half) || (temp.a == half && temp.c == half) || (temp.b == half && temp.c == half)){
				printf("%d\n", temp.step);
				goto nxt;
			}
			bfs.pop();
			for(int i = 0; i<6; i++){
				int nx = temp.a, ny = temp.b, nz = temp.c;
				switch(i){
					case 0:
						if(nx + ny > n){
							nx = (nx + ny - n);
							ny = n;
						}
						else{
							ny += nx;
							nx = 0;
						}
						break;
					case 1:
						nx += ny;
						ny = 0;
						break;
					case 2:
						if(nx + nz > m){
							nx = (nx + nz - m);
							nz = m;
						}
						else{
							nz += nx;
							nx = 0;
						}
						break;
					case 3:
						nx += nz;
						nz = 0;
						break;
					case 4:
						if(ny + nz > m){
							ny = (ny + nz - m);
							nz = m;
						}
						else{
							nz += ny;
							ny = 0;
						}
						break;
					case 5:
						if(ny + nz > n){
							nz = (ny + nz - n);
							ny = n;
						}
						else{
							ny += nz;
							nz = 0;
						}
						break;
				}
				if(mp[nx][ny][nz].vis == 0){
					mp[nx][ny][nz].vis = 1;
					mp[nx][ny][nz].step = temp.step + 1;
					bfs.push(mp[nx][ny][nz]);
				}
			}
		}
		puts("NO");
		nxt:;
	}
	return 0;
}