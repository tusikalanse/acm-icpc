#include <cstdio>
#include <cstring>
#include <vector>
#define max(a, b) (a > b ? a : b)

int dp[25][805], sub[205], add[205];
std::vector<int> path[25][805];


int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int cas = 0, n, m, d, p;
	while(~scanf("%d %d", &n, &m) && n) {
		for(int i = 0; i <= m; i++) {
			for(int j = 0; j < 805; j++) 
				path[i][j].clear();
		}
		memset(dp, -1, sizeof(dp));
		for(int i = 1; i <= n; i++) {
			scanf("%d %d", &p, &d);
			sub[i] = p - d;
			add[i] = p + d;
		}
		int fix = 20 * m;
		dp[0][fix] = 0;
		for(int k = 1; k <= n; k++) {
			for(int i = m; i >= 0; i--) {
				for(int j = 0; j < 2 * fix; j++) {
					if(dp[i][j] >= 0 && j + sub[k] >= 0 && j + sub[k] <= 2 * fix) {
						if(dp[i + 1][j + sub[k]] < dp[i][j] + add[k]) {
							dp[i + 1][j + sub[k]] = dp[i][j] + add[k];
							path[i + 1][j + sub[k]] = path[i][j];
							path[i + 1][j + sub[k]].push_back(k);
						}
					}
				}
			}
		}
		int i;
		for(i = 0; dp[m][fix-i] == -1 && dp[m][fix+i] == -1; i++);
		int temp = (dp[m][fix-i] > dp[m][fix+i]) ? -i : i;
		int sump = dp[m][fix+temp] + temp >> 1;
		int sumd = dp[m][fix+temp] - temp >> 1;
		printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n", ++cas, sump, sumd);
		for(int i = 0; i < m; i++){
			printf(" %d", path[m][fix+temp][i]);
		}
		puts("\n");
	}
	return 0;
}