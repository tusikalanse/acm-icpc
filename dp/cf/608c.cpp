#include <bits/stdc++.h>
using namespace std;

struct node {
	int pos, str;
	bool operator < (const node &rhs) const {
		return pos < rhs.pos;
	}
}Tower[100005];
int dp[100005];


int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &Tower[i].pos, &Tower[i].str);
	}
	sort(Tower + 1, Tower + n + 1);
	dp[0] = 0;
	int mmax = 0;
	for(int i = 1; i <= n; i++) {
		int l = 0, r = i, ans = 0, k = Tower[i].pos - Tower[i].str;
		while(l <= r) {
			int mid = l + r >> 1;
			if(Tower[mid].pos < k) {
				ans = mid;
				l = mid + 1;
			}
			else 
				r = mid - 1;
			
		}
		dp[i] = dp[ans] + 1;
		mmax = max(mmax, dp[i]);
	}
	printf("%d\n", n - mmax);
	return 0;
};