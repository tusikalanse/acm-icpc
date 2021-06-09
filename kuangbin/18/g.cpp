#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXN = 100010;

int wa[MAXN], wb[MAXN], c[MAXN], r[MAXN], sa[MAXN], *rnk, height[MAXN], RMQ[MAXN][16];
char s[MAXN];

void build_sa(int r[], int sa[], int n, int m) {
	int i, j, k, p = 0, *x = wa, *y = wb;
	for(i = 0; i < m; ++i) c[i] = 0;
	for(i = 0; i < n; ++i) c[x[i] = r[i]]++;
	for(i = 1; i < m; ++i) c[i] += c[i - 1];
	for(i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
	for(k = 1; p < n; k <<= 1, m = p) {
		p = 0;
		for(i = n - k; i < n; ++i) y[p++] = i;
		for(i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i] - k;
		for(i = 0; i < m; ++i) c[i] = 0;
		for(i = 0; i < n; ++i) c[x[y[i]]]++;
		for(i = 1; i < m; ++i) c[i] += c[i - 1];
		for(i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
		swap(x, y), p = 1, x[sa[0]] = 0;
		for(i = 1; i < n; ++i)
			x[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? p - 1 : p++;
	}
	rnk = x;
}

void get_height(int r[], int sa[], int n) {
	int i, j, k = 0;
	for(i = 0; i < n; height[rnk[i++]] = k)
		for(k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
}

void RMQ_init(int n) {
	for(int i = 0; i <= n; ++i)
		RMQ[i][0] = height[i];
	for(int j = 1; (1 << j) <= n + 1; ++j) {
		for(int i = 0; i + (1 << j) <= n + 1; ++i) 
			RMQ[i][j] = min(RMQ[i][j - 1], RMQ[i + (1 << (j - 1))][j - 1]);
	}
}

int query(int l, int r) {
	if(l > r)
		swap(l, r);
	l++;
	int k = log2(r - l + 1);
	return min(RMQ[l][k], RMQ[r - (1 << k) + 1][k]);
}

int main() {
	int T = 0, n;
	while(~scanf("%s", s)) {
		if(s[0] == '#')
			break;
		n = strlen(s);
		printf("Case %d: ", ++T);
		for(int i = 0; i < n; ++i) {
			r[i] = s[i];
		}
		r[n] = 0;
		build_sa(r, sa, n + 1, 128);
		get_height(r, sa, n);
		RMQ_init(n);
		int ans = 1, al = sa[1], ar = sa[1];
		for(int L = 1; L * max(2, ans) <= n; ++L) {
			for(int i = 0; (i + 1) * L < n; ++i) {
				int x = i * L, y = (i + 1) * L;
				if(r[x] != r[y]) continue;
				int z = query(rnk[x], rnk[y]);
				int t1 = y + z - 1, t0;
				for(int j = 0; j < L; ++j) {
					if(x - j < 0 || r[x - j] != r[y - j])
						break;
					t0 = x - j;
					int cur = (t1 - t0 + 1) / L;
					if(ans < cur || (ans == cur && rnk[t0] < rnk[al])) {
						ans = cur;
						al = t0;
						ar = t0 + L * cur - 1;
					}
				}
			}
		}
		for(int i = al; i <= ar; ++i)
			putchar(s[i]);
		puts("");
	}
	return 0;
}