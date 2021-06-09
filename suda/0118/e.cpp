#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int degree[1005];
int road[1005][1005];
int father[1005];
int root[1005];
int Find(int x){
	int i = x;
	while(father[i]!=i)
		i = father[i];
	father[x] = i;
	return i;
}
void unite(int x, int y){
	int fx = Find(x), fy = Find(y);
	if (fx != fy) father[fx] = fy;
}


int main(){
	int n, m, x, y;
	while(scanf("%d", &n) && n && scanf("%d", &m)){
		memset(degree, 0, sizeof(degree));
		memset(road, 0, sizeof(road));
		memset(root, 0, sizeof(root));
		for(int i = 1; i<=n; i++) father[i] = i;
		for(int i = 1; i<=m; i++){
			scanf("%d %d", &x, &y);
			road[x][y]++;
			unite(x, y);			
		}
		for(int i = 1; i<=n; i++)
			for(int j = 1; j<=n; j++){
				degree[i] += road[i][j];
				degree[j] += road[i][j];
			}
		int flag = 1;
		for(int i = 1; i<=n; i++){
			if((degree[i]&1) == 1)
			{
				flag = 0;
				break;
			}
		}
		int ans = 0;
		for(int i = 1; i<=n; i++) root[Find(i)] = 1;
		for(int i = 1; i<=n; i++) if(root[i]) ans++;
		if(ans != 1) flag = 0;
		printf("%d\n", flag);
	}
	return 0;
}
