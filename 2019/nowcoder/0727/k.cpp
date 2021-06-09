#include <bits/stdc++.h>
using namespace std;

long long ans;
char s[100010];
int n, cnt[3];
int sum[100010];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	cnt[0] = 1;
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '0')
			ans++;
		sum[i] = (sum[i - 1] + s[i] - '0') % 3;
		cnt[sum[i]]++;
		if(s[i - 1] == '0' && s[i] == '0')
			ans += cnt[sum[i]] - 2;
	}
	printf("%lld\n", ans);
	return 0;
}