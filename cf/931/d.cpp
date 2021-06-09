#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;

vector<int> to[MAXN];
int dp[MAXN];

void dfs(int u, int s){
	dp[s]++;
	for(int i : to[u]){
		dfs(i, s + 1);
	}
}



int main(){
	int n, t, ans = 0;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		scanf("%d", &t);
		to[t].push_back(i);
	}
	dfs(1, 1);
	for(int i = 1; i<=n; i++)
		ans += dp[i] & 1;
	printf("%d\n", ans);
	return 0;
}