#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], b[N], v[N][3], dp[N][3][3], n, T;

int med(int x, int y, int z) {
	static int c[3];
	c[0] = x, c[1] = y, c[2] = z;
	sort(c, c + 3);
	return c[1];
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 2; i < n; ++i) 
			scanf("%d", &b[i]);
		b[0] = b[1] = 2e9;
		b[n] = b[n + 1] = 2e9;
		for(int i = 1; i <= n; ++i) {
			v[i][0] = b[i - 1];
			v[i][1] = b[i];
			v[i][2] = b[i + 1];
			sort(v[i], v[i] + 3);
			a[i] = -1;
		}
		for(int i = 1; i <= n; ++i) 
			for(int j = 0; j < 3; ++j) 
				for(int k = 0; k < 3; ++k)
					dp[i][j][k] = 0;
		dp[2][0][0] = 1; dp[2][1][0] = n > 3;
		for(int i = 3; i <= n; ++i) {
			for(int j = 0; j < 3; ++j)
			for(int k = 0; k < 3; ++k) {
				for(int l = 0; l < 3; ++l) {
					if(med(v[i - 2][l], v[i - 1][k], v[i][j]) == b[i - 1])
						dp[i][j][k] |= dp[i - 1][k][l];
				}
			}
		}
		pair<int, int> f(-1, -1);
		for(int j = 0; j < 1; ++j) {
			for(int k = 0; k < 2; ++k) {
				if(dp[n][j][k]) {
					f.first = j;
					f.second = k;
					a[n] = v[n][j];
					break;
				}
			}
			if(f.first != -1)
				break;
		}
		if(f.first == -1) {
			puts("-1");
			continue;
		}
		for(int i = n - 1; i > 1; --i) {
			for(int k = 0; k < 3; ++k) {
				if(med(v[i - 1][k], v[i][f.second], v[i + 1][f.first]) == b[i] && dp[i][f.second][k]) {
					a[i] = v[i][f.second];
					f.first = f.second;
					f.second = k;
					break;
				}
			}
		}
		a[1] = b[2];
		for(int i = 1; i <= n; ++i) {
			printf("%d%c", a[i], " \n"[i == n]);
		}
	}
	return 0;
}