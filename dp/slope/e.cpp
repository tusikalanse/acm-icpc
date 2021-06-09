#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MAXN = 500010;
LL a[MAXN], sum[MAXN], dp[MAXN], que[MAXN];
int n, m, head, tail;


inline LL X(int i) {return sum[i];}
inline LL Y(int i) {return dp[i] + sum[i] * sum[i];}
inline LL KX(int a, int b) {return X(a) - X(b);}
inline LL KY(int a, int b) {return Y(a) - Y(b);}
inline LL A(int i) {return 2 * sum[i];}
inline LL B(int i) {return sum[i] * sum[i] + m;}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		if(n == 0) {
			printf("0\n");
			continue;
		}
		dp[0] = sum[0] = head = tail = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		que[tail++] = 0;
		for(int i = 1; i <= n; ++i) {
			while(head < tail - 1 && KY(que[head + 1], que[head]) <= KX(que[head + 1], que[head]) * A(i))
				head++;
			dp[i] = B(i) + Y(que[head]) - A(i) * X(que[head]);
			while(head < tail - 1 && KY(i, que[tail - 1]) * KX(que[tail - 1], que[tail - 2]) <= KY(que[tail - 1], que[tail - 2]) * KX(i, que[tail - 1]))
				tail--;
			que[tail++] = i;
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}