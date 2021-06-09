#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int T, n, w[N];
int ans, tmp;

int vis[22];

bool judge(int x, int y, int z, int d) {
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	for(int i = 1; i <= x; ++i) {
		for(int j = 20; j >= 1; --j)
			vis[j] |= vis[j - 1];
	}
	for(int i = 1; i <= y; ++i) {
		for(int j = 20; j >= 2; --j)
			vis[j] |= vis[j - 2];
	}
	for(int i = 1; i <= z; ++i) {
		for(int j = 20; j >= 5; --j)
			vis[j] |= vis[j - 5];
	}
	for(int i = 1; i <= n; ++i) {
		bool flag = 0;
		int t = w[i] % 10;
		while(t <= 20) {
			if(t + d * 10 >= w[i] && vis[t]) {flag = true; break;}
			t += 10;
		}
		if(!flag) return false;
	}
	return true;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		bool flag = true;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &w[i]);
			if(w[i] % 10)
				flag = false;
			w[i] /= 10;
		}
		if(!flag) {
			puts("-1");
			continue;
		}
		sort(w + 1, w + n + 1);
		tmp = w[n] / 10;
		ans = 1e9;
		for(int a = 0; a <= 10; ++a) {
			for(int b = 0; b <= 5; ++b) {
				for(int c = 0; c <= 2; ++c) {
					for(int d = max(0, tmp - 1); d <= tmp; ++d) {
						if(judge(a, b, c, d)) {
							ans = min(ans, a + b + c + d);
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}