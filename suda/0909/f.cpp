#include <bits/stdc++.h>
using namespace std;


int T, n, a, b, k;


map<int, map<int, int> > vis[2];

int main() {
	scanf("%d", &T);
	while(T--) {
		vis[0].clear();
		vis[1].clear();
		int c = 0;
		int ans = 0;
		scanf("%d", &n);
		while(n--) {
			scanf("%d", &k);
			c ^= 1;
			vis[c].clear();
			while(k--) {
				scanf("%d%d", &a, &b);
				vis[c][a][b] = vis[c ^ 1][a][b] + 1;
				ans = max(ans, vis[c][a][b]);
			}
		}
		printf("%d\n", ans);
	}	
	return 0;
}