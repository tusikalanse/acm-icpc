#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int vis[12][12][4] = {0};
char mp[12][12];
int dir[4][2] = {2, -2, 2, 2, -2, 2, -2, -2};

int dfs(int x, int y){
	int res = 0, tmp = 0;
	for(int k = 0; k<4; k++){
		int fx = x + dir[k][0], fy = y + dir[k][1];
		if(fx > 0 && fx <= 10 && fy > 0 && fy <= 10 && !vis[fx][fy][k] && mp[x+dir[k][0]/2][y+dir[k][1]/2] == 'B' && mp[fx][fy] == '#'){
			vis[fx][fy][k] = 1;
			mp[x+dir[k][0]/2][y+dir[k][1]/2] = '#';
			tmp = 1 + dfs(fx, fy);
			res = max(tmp, res);
			vis[fx][fy][k] = 0;
			mp[x+dir[k][0]/2][y+dir[k][1]/2] = 'B';
		}
	}	
	return res;
}

int main(){
	int t;
	scanf("%d", &t);
	char ch;
	while((ch = getchar()) != '\n');
	while(t--){
		while((ch = getchar()) != '\n');
		for(int i = 1; i<=10; i++){
			for(int j = 1; j<=10; j++){
				mp[i][j] = getchar();
			}
			while((ch = getchar()) != '\n');
		}
		int ans = 0;
		for(int i = 1; i<=10; i++){
			for(int j = 1; j<=10; j++){
				if(mp[i][j] == 'W'){
					memset(vis, 0, sizeof(vis));
					mp[i][j] = '#';
					ans = max(ans, dfs(i, j));
					mp[i][j] = 'W';
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}