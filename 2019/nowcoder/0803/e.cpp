#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int G[N][N], T, n, cas, ans[N];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		printf("Case #%d: ", ++cas);
		if(n % 4 > 1) {
			puts("No");
			continue;
		}
		puts("Yes");
		int m = n / 4;
		memset(G, 0, sizeof(G));
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < m; ++j) {
				G[i][j] = 1;
				G[j][i] = 1;
				G[m + i][m + j] = 1;
				G[m + j][m + i] = 1;
				G[i][2 * m + j] = 1;
				G[2 * m + j][i] = 1;
				G[m + i][3 * m + j] = 1;
				G[3 * m + j][m + i] = 1;
				G[2 * m + i][3 * m + j] = 1;
				G[3 * m + j][2 * m + i] = 1;
			}
		}
		if(n % 4 == 1) {
			for(int i = 0; i < m; ++i) {
				G[i][n - 1] = G[n - 1][i] = 1;
				G[m + i][n - 1] = G[n - 1][m + i] = 1;
			}
		}
		for(int i = 0; i < 2 * m; ++i) G[i][i] = 0, ans[i] = i + 2 * m;
		for(int i = 2 * m; i < 3 * m; ++i) G[i][i] = 0, ans[i] = i - m;
		for(int i = 3 * m; i < 4 * m; ++i) G[i][i] = 0, ans[i] = i - 3 * m;
		if(n % 4 == 1) G[n - 1][n - 1] = 0, ans[n - 1] = n - 1;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				printf("%d", G[i][j]);
			puts("");
		}
		for(int i = 0; i < n; ++i)
			printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
	}
	return 0;
}