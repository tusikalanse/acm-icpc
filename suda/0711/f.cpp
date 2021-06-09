#include <bits/stdc++.h>
using namespace std;

const int MAXN = 310;
int dis[MAXN][MAXN];

int main() {
	int n, k, a, b, c;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &dis[i][j]);
	scanf("%d", &k);
	while(k--) {
		scanf("%d %d %d", &a, &b, &c);
		if(c < dis[a][b]) {
            dis[a][b] = dis[b][a] = c;
			for(int i = 1; i <= n; i++) {
				for(int j = i + 1; j <= n; ++j) {
					dis[i][j] = min(dis[i][j], dis[i][a] + dis[b][j] + c);
					dis[i][j] = min(dis[i][j], dis[i][b] + dis[a][j] + c);
					dis[i][j] = min(dis[i][j], dis[i][a] + dis[a][j]);
					dis[i][j] = min(dis[i][j], dis[i][b] + dis[b][j]);
					dis[j][i] = dis[i][j];
				}
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = i + 1; j <= n; ++j) 
				ans += dis[i][j];
		printf("%lld\n", ans);
	}

	return 0;
}