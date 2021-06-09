#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 105, INF = 100000;

int mp[MAXN][MAXN], dis[MAXN], vis[MAXN];
int n, ans;

int dijkstra(){
	for(int i = 0; i < n; i++){
		int mm = INF, v;
		for(int j = 1; j <= n; j++){
			if(!vis[j] && dis[j] < mm){
				mm = dis[j];
				v = j;
			}
		}
		vis[v] = 1;
		for(int j = 1; j <= n; j++){
			if(dis[j] > dis[v] + mp[v][j]){
				dis[j] = dis[v] + mp[v][j];
			}
		}
	}
	int res = 0;
	for(int i = 2; i <= n; i++){
		res = max(res, dis[i]);
	}
	return res;
}

int main(){
	scanf("%d", &n);
	char s[10];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j)
				mp[i][j] = 0;
			else mp[i][j] = INF;
		}
	}
	memset(dis, 0x3f,sizeof(dis));
	memset(vis, 0, sizeof(vis));
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
			scanf("%s", s);
			if(s[0] != 'x')
				mp[i][j] = mp[j][i] = atoi(s);
		}
	}
	dis[1] = 0;
	ans = dijkstra();
	printf("%d\n", ans);
	return 0;
}