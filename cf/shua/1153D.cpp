#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int dp[N], a[N], n, k, f;
vector<int> v[N];

void dfs(int rt) {
	if(v[rt].empty()) {
		dp[rt] = 1;
		k++;
		return;
	}
	for(int i: v[rt]) {
		dfs(i);
		if(a[rt] == 1) 
			dp[rt] = min(dp[rt], dp[i]);
		else
			dp[rt] += dp[i];
	}
}


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(a[i] == 1) dp[i] = 1e6;
		else dp[i] = 0;
	}
	for(int i = 2; i <= n; ++i) {
		scanf("%d", &f);
		v[f].push_back(i);
	}
	dfs(1);
	printf("%d\n", k - dp[1] + 1);
	return 0;
}