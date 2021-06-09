#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

const int N = 50005;

struct people {
	int w, h;
	bool operator<(const people &rhs) const {
		if(w == rhs.w)
			return h > rhs.h;
		return w > rhs.w;
	}
}peo[N], lis[N];

LL dp[102][N];
int que[N], n, k, head, tail, cnt;

inline LL X(int i) {return -lis[i + 1].w;}
inline LL Y(int t, int i) {return dp[t - 1][i];}
inline LL A(int i) {return lis[i].h;}
inline LL KX(int a, int b) {return X(a) - X(b);}
inline LL KY(int t, int a, int b) {return Y(t, a) - Y(t, b);}

int main() {
	while(~scanf("%d%d",&n,&k)) {
		cnt = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; ++i)
			scanf("%d%d",&peo[i].w,&peo[i].h);
		sort(peo + 1, peo + 1 + n);
		lis[++cnt] = peo[1];
		for(int i = 2; i <= n; ++i) {
			if(peo[i].h <= lis[cnt].h)
				continue;
			lis[++cnt] = peo[i];
		}
		n = cnt;
		for(int i = 1; i <= n; ++i)
			dp[1][i] = 1LL * lis[1].w * lis[i].h;
		for(int i = 2; i <= k; ++i) {
			head = tail = 0;
			que[tail++] = 0;
			for(int j = 1; j <= n; ++j) {
				while(head + 1 < tail && KY(i, que[head + 1], que[head]) <= A(j) * KX(que[head + 1], que[head]))
					head++;
				dp[i][j] = Y(i, que[head]) - A(j) * X(que[head]);
				while(head + 1 < tail && KY(i, que[tail - 1], que[tail - 2]) * KX(j, que[tail - 1]) >= KX(que[tail - 1], que[tail - 2]) * KY(i, j, que[tail - 1]))
					tail--;
				que[tail++] = j;
			}
		}
		printf("%lld\n", dp[k][n]);
	}
	return 0;
}