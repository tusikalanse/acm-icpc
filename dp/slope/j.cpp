#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

const int MAXN = 500010;
LL p[MAXN], sum[MAXN], dp[MAXN], que[MAXN];
int n, m, head, tail, _;


inline LL X(int i) {return sum[i];}
inline LL Y(int i) {return dp[i];}
inline LL KX(int a, int b) {return X(a) - X(b);}
inline LL KY(int a, int b) {return Y(a) - Y(b);}
inline LL A(int i) {return p[i];}
inline LL B(int i) {return (sum[i] + 10) * p[i];}

int main() {
	for(scanf("%d",&_);_;_--) {
		scanf("%d", &n);
		dp[0] = sum[0] = head = tail = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%lld %lld", &sum[i], &p[i]);
			sum[i] = sum[i - 1] + sum[i];
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