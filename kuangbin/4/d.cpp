#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;

int mp[1005][1005], dis[1005], dis2[1005], vis[1005];

void dijk(int s, int t){
	memset(dis, 0x3f, sizeof(dis));
	memset(dis2, 0x3f, sizeof(dis2));
	int v, mi;
	dis[s] = dis2[s] = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i<=t; i++){
		mi = INF;
		for(int j = 1; j<=t; j++){
			if(!vis[j] && mi>dis[j]){
				mi = dis[j];
				v = j;
			}
		}
		vis[v] = 1;
		for(int j = 1; j<=t; j++){
			if(!vis[j] && mp[v][j])
				dis[j] = min(dis[j], dis[v] + mp[v][j]);
		}
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i<=t; i++){
		mi = INF;
		for(int j = 1; j<=t; j++){
			if(!vis[j] && mi>dis2[j]){
				mi = dis2[j];
				v = j;
			}
		}
		vis[v] = 1;
		for(int j = 1; j<=t; j++){
			if(!vis[j] && mp[j][v])
				dis2[j] = min(dis2[j], dis2[v] + mp[j][v]);
		}
	}
	mi = 0;
	for(int i = 1; i<=t; i++)
		mi = max(mi, dis[i] + dis2[i]);
	printf("%d\n", mi);
}

int main(){
	int n, m, x, a, b, v;
	scanf("%d %d %d", &n, &m, &x);
	memset(mp, 0, sizeof(mp));
	while(m--){
		scanf("%d %d %d", &a, &b, &v);
		mp[a][b] = v;
	}
	dijk(x, n);
	return 0;
}