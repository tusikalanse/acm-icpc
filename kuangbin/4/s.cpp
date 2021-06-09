#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int dis[1005], head[1005], nxt[21005], pnt[21005], val[21005], vis[1005], c[1005];
int cnt = 0, n, ml, md, x, y, v;

void add(int x, int y, int v){
	nxt[cnt] = head[x];
	pnt[cnt] = y;
	val[cnt] = v;
	head[x] = cnt++;
}

int spfa(){
	memset(c, 0, sizeof(c));
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(1);
	c[1] = 1;
	vis[1] = 1;
	dis[1] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[u]; ~i; i = nxt[i]){
			int j = pnt[i];
			if(dis[j] > dis[u] + val[i]){
				dis[j] = dis[u] + val[i];
				if(!vis[j]){
					if(++c[j] > n)
						return -1;
					vis[j] = 1;
					q.push(j);;
				}
			}
		}
	}
	if(dis[n] == 0x3f3f3f3f) return -2;
	return dis[n];
}


int main(){
	scanf("%d %d %d", &n, &ml, &md);
	memset(head, -1, sizeof(head));
	for(int i = 2; i<=n; i++)
		add(i, i-1, 0);
	while(ml--){
		scanf("%d %d %d", &x, &y, &v);
		add(x, y, v);
	}
	while(md--){
		scanf("%d %d %d", &x, &y, &v);
		add(y, x, -v);
	}
	printf("%d\n", spfa());
	return 0;
}