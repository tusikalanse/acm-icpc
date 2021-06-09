#include <cstdio>
#include <algorithm>
#include <cstring>

int vis[505], match[505];
int head[505];
int nxt[1005], point[1005];
int cnt;
int dfs(int s){
	for(int i = head[s]; ~i; i = nxt[i]){
		int j = point[i];
		if(!vis[j]){
			vis[j] = 1;
			if(match[j]==-1||dfs(match[j])){
				match[j] = s;
				return 1;
			}
		}
	}
	return 0;	
}
void add(int u, int v){
	point[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt++;	
}
int main(){
	int k, m, n, x, y;
	while(~scanf("%d" ,&k) && k && scanf("%d %d", &m, &n)){
		cnt = 0;
		memset(point, 0, sizeof(point));
		memset(nxt, 0, sizeof(nxt));
		memset(match, -1, sizeof(match));
		memset(head, -1, sizeof(head));
		for(int i = 1; i<=k; i++){
			scanf("%d %d", &x, &y);
			add(x, y);			
		}
		int ans = 0;
		for(int i = 1; i<=m; i++){
			memset(vis, 0, sizeof(vis));
			if(dfs(i)) ans++;
		}
		
		printf("%d\n", ans);
	}
	
	
	return 0;
}
