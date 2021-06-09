#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;

struct node {
	int v, a;
	LL d;
	bool operator<(const node &rhs) const {
		return v > rhs.v;
	} 
}vege[30010];

int n, m, r, T;
int que[30010], head, tail;
LL dp[11][30010], sum[30010], nsum[30010], sa[30010], L, R, mid, ans, t;

inline LL X(int i) {return i;}
inline LL Y(int t, int i) {return dp[t - 1][i] - nsum[i] + i * sum[i];}
inline LL A(int i) {return sum[i];}
inline LL KX(int a, int b) {return X(a) - X(b);}
inline LL KY(int t, int a, int b) {return Y(t, a) - Y(t, b);}

bool check(LL mid) {
	if(nsum[n] <= t && sa[n] <= mid) 
		return true;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i <= n && sa[i] <= mid; ++i)
		dp[0][i] = nsum[i];
	for(int k = 1; k <= m; ++k) {
		head = tail = 0;
		if(dp[k - 1][k] != -1)
			que[tail++] = k;
		for(int i = k + 1; i <= n; ++i) {
			while(head < tail && sa[i] - sa[que[head]] > mid)
				head++;
			if(head == tail)
				break;
			while(head + 1 < tail && KY(k, que[head + 1], que[head]) <= A(i) * KX(que[head + 1], que[head])) 
				head++;
			dp[k][i] = Y(k, que[head]) - A(i) * X(que[head]) + nsum[i] + r;
			if(dp[k - 1][i] != -1) {
				while(head + 1 < tail && KY(k, que[tail - 1], que[tail - 2]) * KX(i, que[tail - 1]) >= KY(k, i, que[tail - 1]) * KX(que[tail - 1], que[tail - 2]))
					tail--;
				que[tail++] = i;
			}
		}
		if(dp[k][n] != -1 && dp[k][n] <= t)
			return true;
	}
	return false;
}


int main() {
	for(scanf("%d", &T); T; --T) {
		sa[0] = sum[0] = nsum[0] = 0;
		scanf("%d %d %d %lld", &n, &m, &r, &t);
		for(int i = 1; i <= n; ++i){
			scanf("%d %d %lld", &vege[i].v, &vege[i].a, &vege[i].d);
		}
		sort(vege + 1, vege + n + 1);
		for(int i = 1; i <= n; ++i) {
			sum[i] = sum[i - 1] + vege[i].d;
			nsum[i] = nsum[i - 1] + i * vege[i].d;
			sa[i] = sa[i - 1] + vege[i].a;
		}
		L = 1, R = ans = sa[n] + 1;
		while(L <= R) {
			mid = L + R >> 1;
			if(check(mid)) {
				R = mid - 1;
				ans = mid;
			}
			else 
				L = mid + 1;
		}
		if(ans == sa[n] + 1)
			puts("I have no idea");
		else
			printf("%lld\n", ans);
	}
	return 0;
}