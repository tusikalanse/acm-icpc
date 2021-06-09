#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 1000010;
int r[MAXN], wa[MAXN], wb[MAXN], c[MAXN], sa[MAXN], *rnk, height[MAXN], n, m = 128;
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
		swap(x, y);
		p = 1, x[sa[0]] = 0;
		for(i = 1; i < n; ++i) 
			x[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? p - 1 : p++;
	}
	rnk = x;
}

void get_height(int r[], int sa[], int n) {
	int i, j, k = 0;
	for(i = 0; i < n; height[rnk[i++]] = k)
		for(k?k--:0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
}

int main() {
	scanf("%s",s);
	n = strlen(s);
	for(int i = 0; i <= n; ++i)
		r[i] = s[i];
	build_sa(r, sa, n + 1, m);
	get_height(r, sa, n);
	return 0;
}