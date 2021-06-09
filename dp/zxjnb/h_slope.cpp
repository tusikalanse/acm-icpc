#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10010;

int a[N], n, m, T, cas;
int dp[2][N], que[N], head, tail, c;

inline int X(int i) {return a[i + 1];}
inline int A(int i) {return 2 * a[i];}
inline int Y(int i) {return dp[c ^ 1][i] + a[i + 1] * a[i + 1];}
inline int B(int i) {return a[i] * a[i];}
inline int KX(int a, int b) {return X(a) - X(b);}
inline int KY(int a, int b) {return Y(a) - Y(b);}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) 
			scanf("%d", &a[i]);
		if(m >= n) {
			printf("Case %d: 0\n", ++cas);
			continue;
		}
		sort(a + 1, a + n + 1);
		c = 0;
		for(int i = 1; i <= n; ++i) {
			dp[c][i] = (a[i] - a[1]) * (a[i] - a[1]);
		}
		for(int i = 2; i <= m; ++i) {
			head = tail = 0;
			que[tail++] = i - 1;
			c ^= 1;
			for(int j = i; j <= n; ++j) {
				while(head + 1 < tail && KY(que[head + 1], que[head]) <= A(j) * KX(que[head + 1], que[head]))
					head++;
				dp[c][j] = Y(que[head]) + B(j) - A(j) * X(que[head]);
				while(head + 1 < tail && KY(que[tail - 1], que[tail - 2]) * KX(j, que[tail - 1]) >= KX(que[tail - 1], que[tail - 2]) * KY(j, que[tail - 1]))
					tail--;
				que[tail++] = j;
			}
		}
		printf("Case %d: %d\n", ++cas, dp[c][n]);
	}
	return 0;
}