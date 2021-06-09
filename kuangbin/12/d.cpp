#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 15 + 10;

int dp[MAXN], t[MAXN], pre[MAXN], deadline[20], days[20], n;
char subjects[20][110];

void output(int x) {
	if(!x) 
		return;
	output(x - (1 << pre[x]));
	printf("%s\n", subjects[pre[x]]);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%105s %d %d", subjects[i], &deadline[i], &days[i]);
		}
		int bit = 1 << n;
		for(int i = 1; i < bit; i++) {
			dp[i] = 0x3f3f3f3f;
			for(int j = n - 1; j >= 0; j--) {
				int temp = 1 << j;
				if(!(temp & i)) 
					continue;
				int score = t[i - temp] + days[j] - deadline[j];
				score = max(0, score);
				if(dp[i] > dp[i - temp] + score) {
					dp[i] = dp[i - temp] + score;
					pre[i] = j;
					t[i] = t[i - temp] + days[j];
				}
			}
		}
		printf("%d\n", dp[bit - 1]);
		output(bit - 1);
	}
	return 0;
}