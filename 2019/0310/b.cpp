#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int d[N][N], S[N][N], n, m, a[N];

int main() {
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &a[j]);
			if(a[j] == 0)
				a[j] = 1e7;
		}
		for(int x = 1; x <= m; ++x) {
			for(int y = x + 1; y <= m; ++y) {
				if(a[x] == a[y]) continue;
				if(a[x] < a[y]) d[x][y]++;
				else d[y][x]++;
			}
		}
	}
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(d[i][j] > d[j][i])
				S[i][j] = d[i][j];
		}
	}
	for(int k = 1; k <= m; ++k) {
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(S[i][k] && S[k][j]) {
					S[i][j] = max(S[i][j], min(S[i][k], S[k][j]));
				}
			}
		}
	}
	bool first = 0;
	for(int i = 1; i <= m; ++i) {
		bool flag = 1;
		for(int j = 1; j <= m; ++j) {
			if(i == j) continue;
			if(S[i][j] < S[j][i]) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			if(first)
				printf(" %d", i);
			else {
				printf("%d", i);
				first = 1;
			}
		}
	}
	printf("\n");
	return 0;
}