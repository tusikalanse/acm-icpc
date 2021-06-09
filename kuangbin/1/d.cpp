#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;


int n, m, enu[20];
int vis[20][20], mp[20][20], answer[20][20], mat[20][20];

bool valid(int x, int y){
	if(x < 0 || x >= m || y < 0 || y >= n)
		return false;
	return true;
}

int dir[5][2] = {-1, 0, 0, -1, 0, 0, 0, 1, 1, 0};

void search(int x){
	memset(enu, 0, sizeof(enu));
	int t = x;
	for(int i = 0; i<n; i++){
		enu[i] = (x >> (n-i-1)) & 1;
	}
	return;
}


int main(){
	int flag = 0, temp = 0, ans = 300;
	while(~scanf("%d %d", &m, &n)){
		flag = temp = 0;
		ans = 300;
		memset(vis, 0, sizeof(vis));
		memset(mp, 0, sizeof(mp));
		memset(answer, 0, sizeof(answer));
		memset(mat, 0, sizeof(mat));
		for(int i = 0; i<m; i++){
			for(int j = 0; j<n; j++){
				scanf("%d", &vis[i][j]);
				mat[i][j] = vis[i][j];
			}
		}
		for(int _ = 0; _ < (1 << n); _++)
		{
			search(_);
			memset(mp, 0, sizeof(mp));
			temp = flag = 0;
			for(int i = 0; i<m; i++){
				for(int j = 0; j<n; j++){
					vis[i][j] = mat[i][j];
				}
			}
			for(int i = 0; i<n; i++){
				if(enu[i]){
					temp++;
					mp[0][i] = 1;
					for(int k = 0; k<5; k++){
						if(valid(dir[k][0], i + dir[k][1]))
							vis[dir[k][0]][i + dir[k][1]] ^= 1;
					}
				}
			}
			for(int i = 0; i<m-1; i++){
				for(int j = 0; j<n; j++){
					if(vis[i][j] == 1){
						temp++;
						mp[i+1][j] = 1;
						for(int k = 0; k<5; k++){
							if(valid(i + 1 + dir[k][0], j + dir[k][1]))
								vis[i + 1 + dir[k][0]][j + dir[k][1]] ^= 1;
						}
					}
				}
			}
			for(int j = 0; j<n; j++)
				if(vis[m-1][j] == 1){
					flag = 1;
					break;
				}
			if(flag == 0 && temp<ans){
				ans = temp;
				for(int i = 0; i<m; i++){
					for(int j = 0; j<n; j++){
						answer[i][j] = mp[i][j];
					}
				}
			}
		}
		if(ans == 300) puts("IMPOSSIBLE");
		else 
			for(int i = 0; i<m; i++){
				for(int j = 0; j<n; j++){
					if(j) printf(" %d", answer[i][j]);
					else printf("%d", answer[i][j]);
				}
				puts("");
			}
	}
	return 0;
}