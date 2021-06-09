#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
const unsigned long long p = 131;

unsigned long long P[N], Hash[2][N];

int n, m;
char s[2][N];

unsigned long long find(int l, int r, int d) {
	//s[l...r]
	return Hash[d][r] - Hash[d][l - 1] * P[r - l + 1];
}

unsigned long long val[N];

bool check(int len) {
	int cnt = 0;
	for (int i = 1, j = i + len - 1; j <= n; ++i, ++j)
		val[cnt++] = find(i, j, 0);
	sort(val, val + cnt);
	for (int i = 1, j = i + len - 1; j <= m; ++i, ++j) {
	unsigned long long now = find(i, j, 1);
		if (binary_search(val, val + cnt, now))
			return true;
	}
	return false;
}

int main() {
	P[0] = 1;
	for (int i = 1; i < N; ++i)
		P[i] = P[i - 1] * p;
	while(scanf("%s%s", s[0] + 1, s[1] + 1) != EOF) {
		n = strlen(s[0] + 1);
		m = strlen(s[1] + 1);
		for (int i = 1; i <= n; ++i) {
			Hash[0][i] = Hash[0][i - 1] * p + s[0][i]; 
		}
		for (int i = 1; i <= m; ++i) {
			Hash[1][i] = Hash[1][i - 1] * p + s[1][i]; 
		}
		int l = 0, r = min(n, m), ans = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid)) {
				l = mid + 1;
				ans = mid;
			}
			else
				r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
