#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

int mp[102][102], dis[102], vis[102];
int n, a, b, k, v;

void dijk(){
	dis[a] = 0;
	memset(vis, 0, sizeof(vis));
	int u, mm;
	for(int i = 0; i<n; i++){
		mm = INF;
		for(int j = 1; j<=n; j++){
			if(!vis[j] && dis[j] < mm){
				u = j;
				mm = dis[j];
			}
		}
		vis[u] = 1;
		for(int j = 1; j<=n; j++){
			if(!vis[j] && ~mp[u][j])
				dis[j] = min(dis[j], dis[u] + mp[u][j]);
		}
	}
}

int main(){
	memset(mp, -1, sizeof(mp));
	memset(dis, 0x3f, sizeof(dis));
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 1; i<=n; i++){
		scanf("%d", &k);
		for(int j = 1; j<=k; j++){
			scanf("%d", &v);
			if(j == 1)
				mp[i][v] = 0;
			else
				mp[i][v] = 1;
		}
	}
	dijk();
	if(dis[b] == 0x3f3f3f3f) puts("-1");
	else printf("%d\n", dis[b]);
	return 0;
}