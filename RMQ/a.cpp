#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 50010;
int arr[MAXN], mx[MAXN][20], mn[MAXN][20];

void RMQ_init(int n) {
	for(int i = 0; i < n; ++i)
		mx[i][0] = mn[i][0] = arr[i];
	for(int j = 1; (1 << j) - 1 < n; ++j) {
		for(int i = 0; i + (1 << j) - 1 < n; ++i) {
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int RMQ_query(int l, int r) {
	int k = log2(r - l + 1);
	return max(mx[l][k], mx[r - (1 << k) + 1][k]) - min(mn[l][k], mn[r - (1 << k) + 1][k]);
}

int main() {
	int n, m, a, b;
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 0; i < n; ++i) 
			scanf("%d", &arr[i]);
		RMQ_init(n);
		while(m--) {
			scanf("%d %d", &a, &b);
			printf("%d\n", RMQ_query(a - 1, b - 1));
		}
	}
	return 0;
}