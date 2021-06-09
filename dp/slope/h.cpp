#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;

const int MAXN = 2010;


int AS[MAXN], BS[MAXN], AP[MAXN], BP[MAXN], head, tail;
int que[MAXN], dp[MAXN][MAXN];
int _, T, MAXP, W;


int main() {
	for(scanf("%d",&_);_;_--) {
		scanf("%d%d%d", &T, &MAXP, &W);
		for(int i = 1; i <= T; ++i) 
			scanf("%d%d%d%d",&AP[i],&BP[i],&AS[i],&BS[i]);
		memset(dp, 0xc0, sizeof(dp));
		dp[0][0] = 0;
		for(int i = 1; i <= W + 1; ++i) {
			for(int j = 0; j <= AS[i]; ++j)
				dp[i][j] = -j * AP[i];
		}
		for(int i = 2; i <= T; ++i) {
			for(int j = 1; j <= MAXP; ++j)
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if(i <= W + 1)
				continue;
			head = tail = 0;
			que[tail++] = 0;
			for(int j = 0; j <= MAXP; ++j) {
				dp[i][j] = dp[i - 1][j];
				while(head < tail && j - que[head] > AS[i])
					head++;
				dp[i][j] = max(dp[i][j], dp[i - W - 1][que[head]] - (j - que[head]) * AP[i]);
				while(head < tail && dp[i - W - 1][que[tail - 1]] + que[tail - 1] * AP[i] <= dp[i - W - 1][j] + j * AP[i])
					tail--;
				que[tail++] = j;
			}
			head = tail = 0;
			que[tail++] = MAXP + 1;
			for(int j = MAXP; j >= 0; --j) {
				while(head < tail && que[head] - j > BS[i])
					head++;
				dp[i][j] = max(dp[i][j], dp[i - W - 1][que[head]] + (que[head] - j) * BP[i]);
				while(head < tail && dp[i - W - 1][que[tail - 1]] + que[tail - 1] * BP[i] <= dp[i - W - 1][j] + j * BP[i])
					tail--;
				que[tail++] = j;
			}
		}
		int ans = 0;
		for(int i = 0; i <= MAXP; ++i)
			ans = max(ans, dp[T][i]);
		printf("%d\n", ans);
	}
	return 0;
}