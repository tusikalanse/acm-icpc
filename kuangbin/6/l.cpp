#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 110;

int mp[MAXN][MAXN], n, x, y, dis[MAXN], l;

int Prim(){
	memset(dis, 0x3f, sizeof(dis));
	int res = 0, now = 1, min_edge, min_node;
	for(int i = 1; i<n; i++){
		dis[now] = 0;
		min_edge = 0x3f3f3f3f;
		for(int j = 1; j<=n; j++){
			if(j != now && dis[j]){
				dis[j] = min(dis[j], mp[now][j]);
				if(dis[j] < min_edge){
					min_edge = dis[j];
					min_node = j;
				}
			}
		}
		res += min_edge;
		now = min_node;
	}
	return res;
}

int main(){
	while(~scanf("%d", &n) && n){
		int nn = n * (n - 1) / 2;
		while(nn--){
			scanf("%d %d %d", &x, &y, &l);
			mp[x][y] = mp[y][x] = l;
		}
		printf("%d\n", Prim());
	}
	return 0;
}