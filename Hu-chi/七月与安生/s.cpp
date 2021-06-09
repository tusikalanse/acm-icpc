#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 18) + 10;
double dp[N];
double pb[20][20];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%lf", &pb[i][j]);
	dp[(1 << n) - 1] = 1;
	for(int p = (1 << n) - 1; p > 0; --p) {
		int c = __builtin_popcount(p);
		if(c == 1)
			continue;
		for(int i = 0; i < n; ++i) {
			if((1 << i) & p)
			for(int j = 0; j < n; ++j) {
				if(i == j)
					continue;
				if((1 << j) & p) {
					dp[(1 << i) ^ p] += pb[j][i] * dp[p] / c / (c - 1);
					dp[(1 << j) ^ p] += pb[i][j] * dp[p] / c / (c - 1);
				}
			}
		}
	}
	for(int i = 0; i < n; ++i)
		printf("%.6f%c", dp[1 << i], " \n"[i == n - 1]);
	return 0;
}