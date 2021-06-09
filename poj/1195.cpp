#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
const int MAXN = 1030;
int c[MAXN][MAXN];

inline int lowbit(int x) {
	return x & -x;
}

void update(int x, int y, int val) {
	for(int i = x; i <= n; i += lowbit(i)) 
		for(int j = y; j <= n; j += lowbit(j))
			c[i][j] += val;
}

int sum(int x, int y) {
	int ans = 0;
	for(int i = x; i > 0; i -= lowbit(i))
		for(int j = y; j > 0; j -= lowbit(j))
			ans += c[i][j];
	return ans;
}

int main() {
	int X, Y, A, L, B, R, T;
	int t;
	while(~scanf("%d", &t)) {
		scanf("%d", &n);
		memset(c, 0, sizeof(c));
		while(scanf("%d", &t)) {
			if(t == 3) 
				break;
			if(t == 1) {
				scanf("%d %d %d", &X, &Y, &A);
				update(X + 1, Y + 1, A);
			}
			if(t == 2) {
				scanf("%d %d %d %d", &L, &B, &R, &T);
				printf("%d\n", sum(R + 1, T + 1) - sum(R + 1, B) - sum(L, T + 1) + sum(L, B));
			}
		}
	}
	return 0;
}