#include <bits/stdc++.h>
using namespace std;

int d[4][4] = {
	{1, 1, 1, 1},
	{1, 1, -1, -1},
	{1, -1, 1, -1},
	{1, -1, -1, 1}
};

int m;
int f(int i, int j, int mod) {
	if(mod == 4) return 1;
	mod /= 2;
	return (i >= mod && j >= mod ? -1 : 1) * f(i % mod, j % mod, mod);
}

int main() {
	scanf("%d", &m);
	if(m == 2) {
		puts("1 1\n1 -1");
		return 0;
	}
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < m; ++j) {
			printf("%d\t", f(i, j, m) * d[i % 4][j % 4]);
		}
		puts("");
	}
	return 0;
}