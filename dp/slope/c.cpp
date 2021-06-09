#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define LL long long

const int N = 10010;
int T[N], que[N], dp[N], F[N], head, tail, n, s;

inline int X(int i) {return T[i];}
inline int Y(int i) {return dp[i];}
inline int A(int i) {return F[i];}
inline int KX(int a, int b) {return X(a) - X(b);}
inline int KY(int a, int b) {return Y(a) - Y(b);}


int main() {
	while(~scanf("%d%d", &n, &s)) {
		head = tail = 0;
		for(int i = 1; i <= n; ++i)
			scanf("%d%d",&T[i],&F[i]);
		for(int i = n-1; i>=1;--i) {
			T[i] += T[i+1];
			F[i] += F[i+1];
		}
		T[n + 1] = dp[n + 1] = F[n + 1] = 0;
		que[tail++] = n + 1;
		for(int i = n; i >= 1; --i) {
			while(head < tail - 1 && KY(que[head + 1], que[head]) <= 1LL * KX(que[head + 1], que[head]) * A(i))
				head++;
			dp[i] = Y(que[head]) - 1LL * A(i) * X(que[head]) + 1LL * A(i) * (s + T[i]);
			while(head < tail - 1 && 1LL * KY(que[tail - 1], que[tail - 2]) * KX(i, que[tail - 1]) >= 1LL * KX(que[tail - 1], que[tail - 2]) * KY(i, que[tail - 1]))
				tail--;
			que[tail++] = i;
		}
		printf("%d\n", dp[1]);
	}
	return 0;
}