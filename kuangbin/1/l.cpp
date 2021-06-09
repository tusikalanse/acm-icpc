#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
	
struct node
{
	int x, y, vis;
	char ch;
}mp[105][105], temp;

int dir[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};

int main(){
	int m, n, ans;
	while(~scanf("%d %d", &m, &n) && m){
		getchar();
		ans = 0;
		for(int i = 0; i<m; i++){
			for(int j = 0; j<n; j++){
				mp[i][j].x = i;
				mp[i][j].y = j;
				mp[i][j].ch = getchar();
				if(mp[i][j].ch == '*')
					mp[i][j].vis = 1;
				else 
					mp[i][j].vis = 0;
			}
			getchar();
		}
		queue<node> bfs;
		for(int i = 0; i<m; i++){
			for(int j = 0; j<n; j++){
				if(mp[i][j].vis == 0){
					bfs.push(mp[i][j]);
					mp[i][j].vis = 1;
					ans++;
					while(!bfs.empty()){
						temp = bfs.front();
						bfs.pop();
						for(int k = 0; k<8; k++){
							int nx = temp.x + dir[k][0], ny = temp.y + dir[k][1];
							if(nx>=0 && nx<m && ny>=0 && ny<n && mp[nx][ny].vis == 0){
								mp[nx][ny].vis = 1;
								bfs.push(mp[nx][ny]);
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}