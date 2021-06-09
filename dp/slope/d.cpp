#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define LL long long

const int N = 500010;
LL a[N], sum[N], ans, dp[N];
int n, t, head, tail, que[N], _;

inline LL X(int i) {return a[i + 1];}
inline LL Y(int i) {return i * a[i + 1] + dp[i] - sum[i];}
inline LL KX(int a, int b) {return X(a) - X(b);}
inline LL KY(int a, int b) {return Y(a) - Y(b);}

int main() {
	for(scanf("%d",&_);_;_--) {
		scanf("%d%d", &n, &t);
		dp[0] = a[0] = ans = sum[0] = head = tail = 0;
		for(int i = 1; i <= n; ++i)
			scanf("%lld", &a[i]);
		//sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i)
			sum[i] = sum[i - 1] + a[i];
		for(int i = t; i <= n; ++i) {
			if(i - t == 0 || i - t >= t) {
				while(head < tail - 1 && KY(que[tail - 1], que[tail - 2]) * KX(i - t, que[tail - 1]) >= KX(que[tail - 1], que[tail - 2]) * KY(i - t, que[tail - 1]))
					tail--;
				que[tail++] = i - t;
			}
			while(head < tail - 1 && KY(que[head + 1], que[head]) <= KX(que[head + 1], que[head]) * i)
				head++;
			dp[i] = -i * X(que[head]) + Y(que[head]) + sum[i];
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}