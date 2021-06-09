#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int vis[25], mp[25][5], ans[25];
int cas = 1;


void dfs(int m, int s, int t){
	vis[m] = 1;
	ans[s] = m;
	for(int i = 0; i<3; i++){
		int a = mp[m][i];
		if(s == 19 && a == t){
			printf("%d:  ", cas++);
			for(int j = 0; j<20; j++)
				printf("%d ", ans[j]);
			printf("%d\n", t);
		}
		if(!vis[a])
			dfs(a, s+1, t);
	}
	vis[m] = 0;
	return;
}

int main(){
	for(int i = 1; i<=20; i++){
		scanf("%d%d%d", &mp[i][0], &mp[i][1], &mp[i][2]);
		sort(mp[i], mp[i]+3);
	}
	int m;
	while(~scanf("%d", &m) && m){
		cas = 1;
		memset(vis, 0, sizeof(vis));
		dfs(m, 0, m);
	}
	return 0;
}