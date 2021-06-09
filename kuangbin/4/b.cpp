#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;


struct Nde
{
	int x, y;
}pnt[210];

double dis[210];
int vis[210];
int n;

double Distance(Nde a, Nde b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void dijkstra(){
	for (int i = 1; i <=n; ++i)
	{
		vis[i] = 0;
		dis[i] = 100000000;
	}
	dis[1] = 0;
	for(int j = 1; j<=n; j++){
		int m = 10000000;
		int u;
		for(int i = 1; i<=n; i++){
			if(!vis[i] && dis[i]<m){
				m = dis[i];
				u = i;
			}
		}
		vis[u] = 1;
		if(u == 2) return;
		for(int i = 1; i<=n; i++){
			if(!vis[i] && dis[i] > max(dis[u], Distance(pnt[i], pnt[u])))
				dis[i] = max(dis[u], Distance(pnt[i], pnt[u]));
		}
	}
	return;
}


int main(){
	int cnt = 1;
	while(scanf("%d", &n) && n){
		for(int i = 1; i<=n; i++)
			scanf("%d %d", &pnt[i].x, &pnt[i].y);
		dijkstra();
		printf("Scenario #%d\nFrog Distance = %.3f\n\n", cnt++, dis[2]);
	}
	return 0;
}
