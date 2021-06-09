#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define mst(a, b) memset(a, b, sizeof(a));
using namespace std;
const int MAXN = 800000;
int dis[MAXN], head[MAXN], vis[MAXN], nxt[MAXN];
int pnt[MAXN], val[MAXN], layer[MAXN], vv[MAXN];
int cnt, t, n, m, c, l, l1, x, y, v;

void add(int x, int y, int v){
	nxt[cnt] = head[x];
	pnt[cnt] = y;
	val[cnt] = v;
	head[x] = cnt++;
}

void init(){
	mst(dis, 0x3f);
	mst(head, -1);
	mst(vis, 0);
	mst(nxt, 0);
	mst(pnt, 0);
	mst(val, 0);
	mst(vv, 0);
	mst(layer, 0);
	cnt = 0;
}

void spfa(int s){
	dis[s] = 0;
	vis[s] = 1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[u]; ~i; i = nxt[i]){
			int j = pnt[i];
			if(dis[j] > dis[u] + val[i]){
				dis[j] = dis[u] + val[i];
				if(!vis[j]){
					vis[j] = 1;
					q.push(j);
				}
			}
		}
	}
}

int main(){
	scanf("%d", &t);
	for(int _ = 1; _ <= t; _++){
		init();
		scanf("%d %d %d", &n, &m, &c);
		for(int i = 1; i<=n; i++){
			scanf("%d", &layer[i]);
			vv[layer[i]] = 1;
		}
		for(int i = 1; i<n; i++){
			if(vv[i] && vv[i+1]){
				add(n+i, n+i+1, c);
				add(n+i+1, n+i, c);
			}
		}
		for(int i = 1; i<=n; i++){
			add(n+layer[i], i, 0);
			if(layer[i] > 1)
				add(i, n + layer[i] - 1, c);
			if(layer[i] < n)
				add(i, n + layer[i] + 1, c);
		}
		while(m--){
			scanf("%d %d %d", &x, &y, &v);
			add(x, y, v);
			add(y, x, v);
		}
		spfa(1);
		if(dis[n] == 0x3f3f3f3f)
			dis[n] = -1;
		printf("Case #%d: %d\n", _, dis[n]);
	}
	return 0;
}