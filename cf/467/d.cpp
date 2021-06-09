#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;

int n, m, s;
vector<int> to[MAXN];
vector<int> from[MAXN];
vector<int> ans;
int vis[MAXN][2], judge[MAXN];

void dfs(int v, int p){
	if(vis[v][p]) return;
	vis[v][p] = 1;
	ans.push_back(v);
	if(v == s && p){
		puts("Win");
		while(!ans.empty()){
			printf("%d ", ans.back());
			ans.pop_back();
		}
		puts("");
		exit(0);
	}
	for(int i : from[v])
		dfs(i, p^1);
	ans.pop_back();
}

void dfs2(int v){
	if(judge[v] == 2) return;
	if(judge[v] == 1) {puts("Draw"); exit(0);}
	judge[v] = 1;
	for(int i : to[v])
		dfs2(i);
	judge[v] = 2;
}


int main(){
	int x, y;
	scanf("%d %d", &n, &m);
	for(int i = 1; i<=n; i++){
		scanf("%d", &x);
		while(x--){
			scanf("%d", &y);
			to[i].push_back(y);
			from[y].push_back(i);
		}
	}
	scanf("%d", &s);
	for(int i= 1; i<=n; i++)
		if(to[i].empty())
			dfs(i, 0);
	dfs2(s);
	puts("Lose");
	return 0;
}