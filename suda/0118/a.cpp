#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int head[10000], vis[10000], dis[10000], tm[10000];
int nxt[10000], point[10000], val[10000];
int cnt;
void add(int u, int v, int vl){
	point[cnt] = v;
	nxt[cnt] = head[u];
	val[cnt] = vl;
	head[u] = cnt++;	
}
int main(){
	int t, n, m, w, x, y, v;
	scanf("%d", &t);
	while(t--){
		memset(vis, 0, sizeof(vis));
		memset(nxt, 0 ,sizeof(nxt));
		memset(point, 0, sizeof(point));
		memset(val, 0, sizeof(val));
		memset(head, -1, sizeof(head));
		memset(tm, 0, sizeof(tm));
		memset(dis, 0x3f, sizeof(dis));
		cnt = 0;
		scanf("%d%d%d", &n, &m, &w);
			for(int i = 1; i<=m; i++){
				scanf("%d%d%d", &x, &y, &v);
				add(x, y, v);
				add(y, x, v);
		}
		for(int k = 1; k<=w; k++){
			scanf("%d %d %d", &x, &y, &v);
			add(x, y, -v);
		}
		int flag = 0;
		queue<int> q;
		vis[1] = 1;
		dis[1] = 0;
		q.push(1);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			vis[u] = 0;
			for(int i = head[u]; ~i; i = nxt[i]){
				int j = point[i];
				if(dis[j]>dis[u]+val[i]){
					dis[j] = dis[u] + val[i];
					if(!vis[j]){
						q.push(j);						
						vis[j] = 1;
					}
					tm[j]++;
					if (tm[j] > n){ flag = 1; goto out;}	
				}
			}
		}
		out:;
		puts(flag?"YES":"NO");	
	}	
	return 0;
}
