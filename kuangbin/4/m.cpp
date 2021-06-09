#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int head[101], vis[101], level[101], dis[101], price[101];
int pnt[10010], nxt[10010], val[10010];
int cnt = 0, m, n, x, t, v;

void add(int x, int y, int v){
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	val[cnt] = v;
	head[x] = cnt++;
}

int dijk(){
	int u, mm;
	for(int i = 1; i<=n; i++){
		dis[i] = price[i];
	}
	for(int i = 0; i<n; i++){
		mm = 0x3f3f3f3f;
		for(int j = 1; j<=n; j++){
			if(!vis[j] && dis[j] < mm){
				u = j;
				mm = dis[j];
			}
		}
		if(mm == 0x3f3f3f3f) break;
		vis[u] = 1;
		for(int j = head[u]; ~j; j = nxt[j]){
			int k = pnt[j];
			if(!vis[k]){
				dis[k] = min(dis[k], dis[u] + val[j]);
			}
		}
	}
	return dis[1];
}

int main(){
	memset(head, -1, sizeof(head));
	scanf("%d %d", &m, &n);
	int maxlevel, ans = 0x3f3f3f3f;
	for(int i = 1; i<=n; i++){
		scanf("%d %d %d", &price[i], &level[i], &x);
		while(x--){
			scanf("%d %d", &t, &v);
			add(t, i, v);
		}
	}
	for(int i = 1; i<=n; i++){
		maxlevel = level[i];
		for(int j = 1; j<=n; j++){
			if(level[j] > maxlevel || level[j] + m < maxlevel)
				vis[j] = 1;
			else
				vis[j] = 0;
		}
		ans = min(ans, dijk());
	}
	printf("%d\n", ans);
	return 0;
}
