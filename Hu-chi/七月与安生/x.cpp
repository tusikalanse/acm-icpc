#include <bits/stdc++.h>
#define LL long long 
using namespace std;

vector<LL> num;


void dfs(int x) {
	num.push_back(x);
	if(x < 1e8) {
		dfs(x * 10 + 4);
		dfs(x * 10 + 7);
	}
}

int main() {
	dfs(0);
	num.push_back(1e9 + 1);
	sort(num.begin(), num.end());
	LL pl, pr, vl, vr, k, l, r;
	LL ans = 0;
	cin >> pl >> pr >> vl >> vr >> k;
	for(int i = 1; i + k < num.size(); ++i) {
		if(pl <= num[i] && num[i + k - 1] <= vr) {
			if(num[i - 1] <= pr && num[i + k] >= vl) {
				l = max(pl, num[i - 1] + 1);
				r = min(vr, num[i + k] - 1);
				ans += min(pr - l + 1, num[i] - l + 1) * min(r - vl + 1, r - num[i + k - 1] + 1);
			}
		}
		if(vl <= num[i] && num[i + k - 1] <= pr) {
			if(num[i - 1] <= vr && num[i + k] >= pl) {
				l = max(vl, num[i - 1] + 1);
				r = min(pr, num[i + k] - 1);
				ans += min(vr - l + 1, num[i] - l + 1) * min(r - pl + 1, r - num[i + k - 1] + 1);
			}
		}
	}
	if(k == 1)
		for(int i = 1; i < num.size(); ++i)
			if(num[i] >= pl && num[i] <= pr && num[i] >= vl && num[i] <= vr)
				ans--;
	printf("%.12lf\n",(double)ans/(pr-pl+1)/(vr-vl+1));
	return 0;
}

