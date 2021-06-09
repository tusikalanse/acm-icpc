#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 2005;

int mp[MAXN][MAXN], n, dis[MAXN];
char truck[MAXN][10];

int Prim(){
	int ans = 0, now, min_node, min_edge;
	memset(dis, 0x3f, sizeof(dis));
	now = 1;
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
		ans += min_edge;
		now = min_node;
	}
	return ans;
}

int main(){
	while(~scanf("%d", &n) && n){
		for(int i = 1; i<=n; i++){
			scanf("%s", truck[i]);
			for(int j = 1; j<i; j++){
				int dif = 0;
				for(int k = 0; k<7; k++){
					if(truck[i][k] != truck[j][k])
						dif++;
				}
				mp[i][j] = mp[j][i] = dif;
			}
		}
		printf("The highest possible quality is 1/%d.\n", Prim());
	}
	return 0;
}
