#include <bits/stdc++.h>
using namespace std;

const int N = 102;
long long dp[2][N][N][N], ans[N][N];
int n, a[N];
char s[N]; 

long long calcdp(int c, int l, int r, int cnt);

long long calcans(int l, int r) {
	if(l > r) return 0;
	long long &res = ans[l][r];
	if(res != -1) return res;
	res = 0;
	for(int cnt = 1; cnt <= r - l + 1; ++cnt) {
		res = max(res, a[cnt] + calcdp(0, l, r, cnt));
		res = max(res, a[cnt] + calcdp(1, l, r, cnt));
	}
	return res;
}

long long calcdp(int c, int l, int r, int cnt) {
	if(cnt == 0) return dp[c][l][r][cnt] = calcans(l, r);
	long long &res = dp[c][l][r][cnt];
	if(res != -1) return res;
	res = -1e10;
	for(int i = l; i < r; ++i) {
		if(s[i] - '0' == c)
			res = max(res, calcans(l, i - 1) + calcdp(c, i + 1, r, cnt - 1));
	}
	if(cnt == 1 && s[r] - '0' == c)
		res = max(res, calcans(l, r - 1));
	return res;
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	memset(dp, -1, sizeof(dp));
	memset(ans, -1, sizeof(ans));
	int t, a, b, c, d;
	printf("%lld\n", calcans(1, n));
	return 0;
}