#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define mst(a, b) memset(a, b, sizeof(a))
using namespace std;

int head[205], crd[205], vis[205], dis[205], tm[205], r[205];
int pnt[20010], nxt[20010];
int t, n, m, q, x, y, p, temp, cnt;

int add(int x, int y){
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void init(){
	mst(head, -1);
	mst(dis, 0x3f);
	mst(vis, 0);
	mst(tm, 0);
	mst(r, 0);
	mst(pnt, 0);
	mst(nxt, 0);
	cnt = 0;
}

void dfs(int x){
	r[x] = 1;
	for(int i = head[x]; ~i; i = nxt[i]){
		int j = pnt[i];
		if(!r[j])
			dfs(j);
	}
}

void spfa(){
	queue<int> s;
	vis[1] = 1;
	dis[1] = 0;
	s.push(1);
	while(!s.empty()){
		int u = s.front();
		s.pop();
		vis[u] = 0;
		for(int i = head[u]; ~i; i = nxt[i]){
			int j = pnt[i];
			if(!r[j]){
				temp = (crd[j] - crd[u]) * (crd[j] - crd[u]) * (crd[j] - crd[u]);
				if(dis[j] > dis[u] + temp){
					dis[j] = dis[u] + temp;
					if(!vis[j]){
						vis[j] = 1;
						s.push(j);
					}
					tm[j]++;
					if(tm[j] >= n){
						dfs(j);
					}
				}
			}
		}
	}
}

int main(){
	scanf("%d", &t);
	for(int _ = 1; _ <= t; _++){
		init();
		scanf("%d", &n);
		for(int i = 1; i<=n; i++){
			scanf("%d", &crd[i]);
		}
		scanf("%d", &m);
		while(m--){
			scanf("%d %d", &x, &y);
			add(x, y);
		}
		spfa();
		printf("Case %d:\n", _);
		scanf("%d", &q);
		while(q--){
			scanf("%d", &p);
			if(r[p] || dis[p] == 0x3f3f3f3f || dis[p] < 3)
				puts("?");
			else
				printf("%d\n", dis[p]);
		}
	}
	return 0;
}