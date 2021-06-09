#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 10;
 
int T, d[N], n, dp[10][2], id, vis[N], mx;
 
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		mx = 0;
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(int) * (n + 4));
		bool flag = false;
		id = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%1d", &d[i]);
			if(dp[d[i]][0] == 0)
				dp[d[i]][0] = i;
			for(int j = d[i] + 1; j < 10; ++j) {
				if(dp[j][0]) {
					dp[d[i]][1] = i;
					if(id == 0)
						id = dp[j][0];
				}
				if(dp[j][1]) {
					flag = true;
					break;
				}
			}
		}
		if(flag) {
			puts("-");
			continue;
		}
		if(id == 0) {
			for(int i = 1; i <= n; ++i)
				printf("1");
			puts("");
			continue;
		}
		for(int i = 1; i <= n; ++i) {
			if(i < id) {
				vis[i] = 1;
			}
			else {
				if(d[i] < d[id])
					vis[i] = 1;
				else if(d[i] > d[id]) {
					mx = max(mx, d[i]);
					vis[i] = 2;
				}
				else {
					if(mx <= d[i]) {
						mx = max(mx, d[i]);
						vis[i] = 2;
					}
					else
						vis[i] = 1;
				}
			}
		}
		id = 0;
		for(int i = 1; i <= n; ++i) {
			if(vis[i] == 1) {
				if(id == 0) {
					id = d[i];
					continue;
				}
				if(d[i] < id) {
					flag = true;
					break;
				}
				id = max(id, d[i]);
			}
		}
		if(flag) {
			puts("-");
			continue;
		}
		id = 0;
		for(int i = 1; i <= n; ++i) {
			if(vis[i] == 2) {
				if(id == 0) {
					id = d[i];
					continue;
				}
				if(d[i] < id) {
					flag = true;
					break;
				}
				id = max(id, d[i]);
			}
		}
		if(flag) {
			puts("-");
			continue;
		}
		for(int i = 1; i <= n; ++i)
			printf("%d", vis[i]);
		puts("");
	}
 
	return 0;
}