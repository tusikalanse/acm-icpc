#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, k, T, now;
char pn[30], nm[20010];
int que[20010], head, tail;
int pos[130];
LL dp[2][20010], sum[20010], nsum[20010], sqrsum[20010];

inline LL X(int i) {return i + 1;}
inline LL Y(int t, int i) {return dp[t ^ 1][i] - nsum[i] + (i + 1) * sum[i] + sqrsum[i];}
inline LL A(int i) {return sum[i];}
inline LL B(int i) {return nsum[i] - sqrsum[i];}
inline LL KX(int a, int b) {return X(a) - X(b);}
inline LL KY(int t, int a, int b) {return Y(t, a) - Y(t, b);}

bool front(int t, int a, int b, int i) {
	return KY(t, a, b) <= KX(a, b) * A(i);
}

bool back(int t, int a, int b, int c) {
	return KY(t, b, c) * KX(a, b) >= KY(t, a, b) * KX(b, c);
}


int main() {
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		scanf("%s%d%s", pn, &k, nm);
		n = strlen(nm);
		for(int i = 0; i < 26; ++i)
			pos[pn[i]] = i;
		sum[0] = nsum[0] = now = 0;
		for(int i = 0; i < n; ++i) {
			int p = pos[nm[i]];
			sqrsum[i] = p * p;
			sum[i] = p;
			nsum[i] = i * p;
		}
		for(int i = 1; i < n; ++i) {
			sum[i] += sum[i - 1];
			sqrsum[i] += sqrsum[i - 1];
			nsum[i] += nsum[i - 1];
		}
		for(int i = 0; i < n; ++i)
			dp[now][i] = nsum[i] - sqrsum[i];
		now ^= 1;
		for(int ii = 1; ii < k; ++ii) {
			head = tail = 0;
			que[tail++] = ii - 1;
			for(int i = ii; i < n; ++i) {
				while(head + 1 < tail && front(now, que[head + 1], que[head], i))
					head++;
				dp[now][i] = Y(now, que[head]) + B(i) - A(i) * X(que[head]);
				while(head + 1 < tail && back(now, i, que[tail - 1], que[tail - 2]))
					tail--;
				que[tail++] = i;
			}
			now ^= 1;
		}
		printf("Case %d: %lld\n", cas, dp[now ^ 1][n - 1]);
	}
	return 0;
}