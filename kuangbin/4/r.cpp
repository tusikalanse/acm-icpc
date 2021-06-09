#include <bits/stdc++.h>
using namespace std;

int vis[305], g[305][305], dis[305];
int t, n, m;

void spfa(int src){
	queue<int> q;
	for(int i = 1; i<=n; ++i){
		if(i != src){
			dis[i] = g[src][i];
			vis[i] = 1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = 1; i<=n; ++i){
			if(i == u) continue;
			if(dis[i] > dis[u] + g[u][i]){
				dis[i] = dis[u] + g[u][i];
				if(!vis[i]){
					vis[i] = 1;
					 q.push(i);
				}
			}
		}
	}
}


int main(){
	while(~scanf("%d", &n)){
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i<=n; ++i){
			for(int j = 1; j<=n; ++j){
				scanf("%d", &g[i][j]);
			}
		}
		int ans, c1, c2;
		spfa(1);
		ans = dis[n];
		c1 = dis[1];
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		spfa(n);
		c2 = dis[n];
		printf("%d\n", min(ans, c1 + c2));
	}

	return 0;
}