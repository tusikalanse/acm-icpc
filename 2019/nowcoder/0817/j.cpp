#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5010;

struct B {
	int w, h;
	bool operator<(const B &rhs) const {
		return h < rhs.h;
	}
}a[N];

int n, K;
long long dp[N][2010], sum[N], sw[N];
int que[N], head, tail;

inline LL Y(int t, int x) {return dp[x][t - 1] + sw[x] * a[x + 1].h - sum[x];}
inline LL KY(int t, int i, int j) {return Y(t, i) - Y(t, j);}
inline LL X(int x) {return a[x + 1].h;}
inline LL KX(int i, int j) {return X(i) - X(j);}

int main() {
	scanf("%d%d", &n, &K);
	for(int i = 1; i <= n; ++i) 
		scanf("%d%d", &a[i].w, &a[i].h);
	sort(a + 1, a + n + 1);
	a[n + 1].h = a[n + 1].w = 1e7;
	for(int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + 1LL * a[i].h * a[i].w;
		sw[i] = sw[i - 1] + a[i].w;
	}
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= n; ++i) 
		dp[i][1] = sum[i] - a[1].h * sw[i];
	for(int k = 2; k <= K; ++k) {
		head = tail = 0;
		dp[k][k] = 0;
		que[tail++] = k - 1;
		for(int i = k; i <= n; ++i) {
			while(head < tail - 1 && (__int128)KY(k, que[head + 1], que[head]) <= (__int128)sw[i] * KX(que[head + 1], que[head])) head++;
			int j = que[head];
			dp[i][k] = dp[j][k - 1] + sum[i] - sum[j] - (sw[i] - sw[j]) * a[j + 1].h;
			while(head < tail - 1 && (__int128)KY(k, que[tail - 1], que[tail - 2]) * KX(i, que[tail - 1]) >= (__int128)KY(k, i, que[tail - 1]) * KX(que[tail - 1], que[tail - 2])) tail--;
			que[tail++] = i; 
		}
	}
	printf("%lld\n", dp[n][K]);
	return 0;
}