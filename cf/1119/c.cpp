#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int n, m, a[N][N], c;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &c);
			a[i][j] ^= c;
		}
	}
	for(int i = 1; i < n; ++i) {
		int cnt = 0;
		for(int j = 1; j <= m; ++j) {
			if(a[i][j] == 1) {
				a[n][j] ^= 1;
				cnt++;
			}
		}
		if(cnt % 2 != 0) {
			puts("No");
			return 0;
		}
	}
	for(int j = 1; j <= m; ++j) 
		if(a[n][j] != 0) {
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}