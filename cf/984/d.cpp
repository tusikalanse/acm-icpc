#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
int f[MAXN][MAXN], mmax[MAXN][MAXN], n, nmax[MAXN][MAXN];

void pre() {
	int i, j, k;
	for(i = 2; i < n; i <<= 1) {
		for(k = 1; i + k <= n + 1; ++k)
			f[k][i] = f[k][i >> 1] ^ f[k + i/2][i >> 1];
		for(j = 1; j < i; ++j) {
			for(k = 1; i + j + k <= n + 1; ++k)
				f[k][i+j] = f[k][j] ^ f[k+i][j];
		}
	}
	if(i == n) {
		f[1][n] = f[1][n >> 1] ^ f[1 + (n >> 1)][n >> 1];
	}
}

void getmax() {
	for(int len = 2; len <= n; ++len) {
		for(int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			nmax[i][len] = max(f[i][len], max(nmax[i][len-1], nmax[i+1][len-1]));
		}
	}
}


int main() {
	int q, l, r;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &f[i][1]);	
		nmax[i][1] = f[i][1];
	}
	pre();
	getmax();
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d", &l, &r);
		printf("%d\n", nmax[l][r-l+1]);
	}
	return 0;
}