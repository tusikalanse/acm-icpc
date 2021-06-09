#include <bits/stdc++.h>
using namespace std;

char mp[] = {'C', 'P'};
int F[2][2] = {0, 0, 1, 0};

int T, n;

int gao(int i, int j, int base) {
	if(base == 2) return F[i][j];
	base /= 2;
	return gao(i % base, j % base, base) ^ (i >= base && j < base);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < (1 << n); ++i) {
			for(int j = 0; j < (1 << n); ++j) {
				putchar(mp[gao(i, j, 1 << n)]);
			}
			puts("");
		}
	}
	return 0;
}