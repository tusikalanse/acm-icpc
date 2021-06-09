#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define mst(a, b) memset(a, b, sizeof(a))
using namespace std;

int head[1005], cnt, dis[1005], dis1[1005], dis2[1005], vis[1005];
int t, n, m, a[100005], b[100005], c[100005], pre[1005], A, B, nxt[1005];

struct node
{
	int nxt, pnt, val;
}edge[200006];

void add(int x, int y, int v){
	edge[cnt].nxt = head[x];
	edge[cnt].pnt = y;
	edge[cnt].val = v;
	head[x] = cnt++;
}

void spfa(int src){
	mst(vis, 0);
	mst(dis, 0x3f);
	queue<int> q;
	vis[src] = 1;
	dis[src] = 0;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[u]; ~i; i = edge[i].nxt){
			int j = edge[i].pnt;
			if(dis[j] > dis[u] + edge[i].val){
				dis[j] = dis[u] + edge[i].val;
				if(!vis[j]){
					vis[j] = 1;
					q.push(j);
				}
			}
		}
	}
}

int bfs(int src, int des){
	mst(dis, -1);
	dis[src] = 0;
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u]; ~i; i = edge[i].nxt){
			int j = edge[i].pnt;
			if(-1 == dis[j] && edge[i].val > 0){
				dis[j] = dis[u] + 1;
				q.push(j);
			}
		}
	}
	return dis[des] != -1;
}

int dfs(int src, int des, int f){
	vis[src] = 1;
	if(src == des) return f;
	int tmp;
	for(int &i = nxt[src]; ~i; i = edge[i].nxt){
		int j = edge[i].pnt;
		if(!vis[j] && dis[j] == dis[src] + 1 && edge[i].val > 0){
			if(tmp = dfs(j, des, min(f, edge[i].val)) > 0){
				edge[i].val -= tmp;
				edge[i^1].val += tmp;
				return tmp;
			}
		}
	}
	return 0;
}

int dinic(int src, int des){
	int ans = 0, f;
	while(bfs(src, des)){
		memcpy(nxt, head, sizeof(nxt));
		while(true){
			mst(vis, 0);
			f = dfs(src, des, 0x3f3f3f3f);
			if(f) ans += f;
			else break;
		}
	}
	return ans;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		cnt = 0;
		mst(head, -1);
		for(int i = 1; i<=m; i++){
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
			add(a[i], b[i], c[i]);
		}
		scanf("%d %d", &A, &B);
		spfa(A);
		cnt = 0;
		memcpy(dis1, dis, sizeof(dis));
		mst(head, -1);
		for(int i = 1; i<=m; i++)
			add(b[i], a[i], c[i]);
		spfa(B);
		memcpy(dis2, dis, sizeof(dis));
		mst(head, -1);
		cnt = 0;
		for(int i = 1; i<=m; i++){
			if(a[i] != b[i] && dis1[a[i]] + dis2[b[i]] + c[i] == dis1[B]){
				add(a[i], b[i], 1);
				add(b[i], a[i], 0);
			}
		}
		printf("%d\n", dinic(A, B));
	}
	return 0;
}