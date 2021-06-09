#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
	int vis, step, fa[2], x, y, com;
	void init(){
		memset(fa, 0, sizeof(fa));
		vis = 0;
	}
}mp[105][105], temp;
int a, b, c, nx, ny;


void print(node t){
	if(t.step == 0)
		return;
	nx = t.fa[0];
	ny = t.fa[1];
	print(mp[nx][ny]);
	switch(t.com){
		case 0:
			puts("FILL(1)");
			break;
		case 1:
			puts("FILL(2)");
			break;
		case 2:
			puts("DROP(1)");
			break;
		case 3:
			puts("DROP(2)");
			break;
		case 4:
			puts("POUR(1,2)");
			break;
		case 5:
			puts("POUR(2,1)");
			break;
	}
	return;
}


int main(){
	scanf("%d %d %d", &a, &b, &c);
	for(int i = 0; i<=a; i++)
		for(int j = 0; j<=b; j++)
			mp[i][j].init();
	mp[0][0].vis = 1;
	mp[0][0].step = mp[0][0].x = mp[0][0].y = 0;
	queue<node> bfs;
	bfs.push(mp[0][0]);
	while(!bfs.empty()){
		temp = bfs.front();
		//printf("%d %d %d %d\n", temp.x, temp.y, temp.step, temp.com);
		if(temp.x == c || temp.y == c){
			printf("%d\n", temp.step);
			print(temp);
			return 0;
		}
		bfs.pop();
		for(int i = 0; i<6; i++){
			nx = temp.x;
			ny = temp.y;
			switch(i){
				case 0:
					nx = a;
					break;
				case 1:
					ny = b;
					break;
				case 2:
					nx = 0;
					break;
				case 3:
					ny = 0;
					break;
				case 4:
					if(nx + ny <= b){
						ny += nx;
						nx = 0;
					}
					else{
						nx = (nx+ny-b);
						ny = b;
					}
					break;
				case 5:
					if(nx + ny <= a){
						nx += ny;
						ny = 0;
					}
					else{
						ny = (nx+ny-a);
						nx = a;
					}
					break;
			}
			if(mp[nx][ny].vis == 0){
				mp[nx][ny].vis = 1;
				mp[nx][ny].x = nx;
				mp[nx][ny].y = ny;
				mp[nx][ny].fa[0] = temp.x;
				mp[nx][ny].fa[1] = temp.y;
				mp[nx][ny].step = temp.step + 1;
				mp[nx][ny].com = i;
				bfs.push(mp[nx][ny]);
			}
		}
	}
	puts("impossible");
	return 0;
}