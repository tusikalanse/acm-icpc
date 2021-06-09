#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[2005], a[2005], adja[2005];

int main() {
	int n, k, flag, hour, minute, sec;
	scanf("%d", &n);
	while(n--) {
		flag = 1;
		hour = 8;
		minute = sec = 0;
		scanf("%d", &k);
		for(int i = 1; i <= k; i++) 
			scanf("%d", &a[i]);
		for(int i = 2; i <= k; i++)
			scanf("%d", &adja[i]);
		dp[0] = 0;
		dp[1] = a[1];
		for(int i = 2; i <= k; i++)
			dp[i] = min(dp[i-1] + a[i], dp[i - 2] + adja[i]);
		sec += dp[k];
		minute += sec/60;
		sec %= 60;
		hour += minute/60;
		minute %= 60;
		flag += hour/12;
		hour %= 12;
		printf("%02d:%02d:%02d %cm\n", hour, minute, sec, (flag & 1) ? 'a' : 'p');
	}
	return 0;
}