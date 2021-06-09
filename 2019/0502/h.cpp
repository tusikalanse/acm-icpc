#include <bits/stdc++.h>
using namespace std;

int T, n, a[100010], ans, cnt;
int vis[100010];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			vis[i] = 0;
		}
		cnt = 0;
		a[0] = a[n + 1] = INT_MAX;
		for(int i = 1; i <= n; ++i) {
			if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
				vis[i] = 1;
				cnt++;
			}
		}
		ans = cnt;
		for(int i = 2; i < n; ++i) {
			if(vis[i]) {
				if(a[i - 1] != a[i + 1] && a[i - 1] <= a[i - 2] && a[i + 1] <= a[i + 2])
					ans = cnt - 1;
			}
		}
		for(int i = 3; i + 1 < n; ++i) {
			if(vis[i - 1] && vis[i + 1]) {
				if(a[i - 1] == a[i + 1])
					ans = cnt - 2;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}