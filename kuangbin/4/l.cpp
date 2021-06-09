#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
double dis[MAXN], mp[MAXN][MAXN];
int cnt = 2, vis[MAXN];
struct node
{
	double x, y;
}p[MAXN];


double dist(node a, node b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(){
	memset(mp, 0, sizeof(mp));
	memset(vis, 0, sizeof(vis));
	scanf("%lf %lf %lf %lf", &p[0].x, &p[0].y, &p[1].x, &p[1].y);
	double temp;
	bool flag = false;
	while(~scanf("%lf %lf", &p[cnt].x, &p[cnt].y)){
		if(p[cnt].x == -1 && p[cnt].y == -1){
			flag = false;
			continue;
		}
		if(flag){
			temp = dist(p[cnt], p[cnt-1]) * 3.0/2000.0;
			mp[cnt][cnt-1] = mp[cnt-1][cnt] = temp;
		}
		cnt++;
		flag = true;
	}
	for(int i = 0; i<cnt; i++){
		for(int j = 0; j<cnt; j++){
			if(i != j && 0.0 == mp[i][j]){
				mp[i][j] = mp[j][i] = dist(p[i], p[j]) * 3.0/500.0;
			}
		}
	}
	for(int i = 0; i<cnt; i++)
		dis[i] = mp[0][i];
	int u;
	for(int i = 0; i<cnt; i++){
		temp = 1e10;
		for(int j = 0; j<cnt; j++){
			if(!vis[j] && dis[j] < temp){
				u = j;
				temp = dis[j];
			}
		}
		vis[u] = 1;
		for(int j = 0; j<cnt; j++){
			dis[j] = min(dis[j], dis[u] + mp[u][j]);
		}
	}
	printf("%0.0lf\n", dis[1]);
	return 0;
}