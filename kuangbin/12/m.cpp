#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Platform {
	int x1, x2, h;
	bool operator < (const Platform &rhs) const {
		return h < rhs.h;
	}
}plats[1005];

int dp[1005][2];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t, n, x, y, mmax;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d %d", &n, &x, &y, &mmax);
		for(int i = 1; i <= n; i++) {
			scanf("%d %d %d", &plats[i].x1, &plats[i].x2, &plats[i].h);
		}
		plats[0].x1 = -30000;
		plats[0].x2 = 30000;
		plats[0].h = 0;
		plats[n+1].x1 = plats[n+1].x2 = x;
		plats[n+1].h = y;
		memset(dp, 0x3f, sizeof(dp));
		sort(plats, plats + n + 2);
		dp[0][0] = dp[0][1] = 0;
		for(int i = 1; i <= n + 1; i++) {
			int k = i - 1;
			while(k > 0 && plats[i].h - plats[k].h <= mmax) {
				if(plats[i].x1 >= plats[k].x1 && plats[i].x1 <= plats[k].x2) {
					dp[i][0] = plats[i].h - plats[k].h + min(plats[i].x1 - plats[k].x1 + dp[k][0], plats[k].x2 - plats[i].x1 + dp[k][1]);
					goto flag1;
				}
				else 
					k--;
			}
			if(plats[i].h - plats[k].h > mmax)
				dp[i][0] = INF;
			else
				dp[i][0] = plats[i].h;
			flag1:;
			k = i - 1;
			while(k > 0 && plats[i].h - plats[k].h <= mmax) {
				if(plats[i].x2 >= plats[k].x1 && plats[i].x2 <= plats[k].x2) {
					dp[i][1] = plats[i].h - plats[k].h + min(plats[i].x2 - plats[k].x1 + dp[k][0], plats[k].x2 - plats[i].x2 + dp[k][1]);
					goto flag2;
				}
				else 
					k--;
			}
			if(plats[i].h - plats[k].h > mmax)
				dp[i][1] = INF;
			else
				dp[i][1] = plats[i].h;
			flag2:;
			// printf("%d %d\n", dp[i][0], dp[i][1]);
		}
		printf("%d\n", min(dp[n+1][0], dp[n+1][1]));
	}
	return 0;
}