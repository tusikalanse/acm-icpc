#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL cnt[10], W;
LL S[10];
set<LL> ans[10];

void dfs(int stp, LL val) {
	if(val < W - 1000 && val < S[stp] - 1000) 
		return;
	if(ans[stp].find(val) != ans[stp].end())
		return;
	ans[stp].insert(val);
	if(stp == 8) 
		return;
	LL mx = min(W, S[stp + 1]);
	LL num = min(cnt[stp + 1], (mx - val) / (stp + 1));
	for(LL i = num; i >= 0 && i + 100 > num; --i) {
		dfs(stp + 1, val + i * (stp + 1));
	}
}

int main() {
	cin >> W;
	for(int i = 1; i <= 8; ++i) {
		cin >> cnt[i];
		S[i] = S[i - 1] + i * cnt[i];
	}
	dfs(0, 0);
	printf("%lld\n", *ans[8].rbegin());
	return 0;
}