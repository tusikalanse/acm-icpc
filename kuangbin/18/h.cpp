#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 200010;
char s1[MAXN], s2[MAXN];
int r[MAXN], wa[MAXN], wb[MAXN], c[MAXN], sa[MAXN], *rnk, height[MAXN];

void build_sa(int r[], int sa[], int n, int m) {
	int i, j, p = 0, *x = wa, *y = wb;
	for(i = 0; i < m; ++i) c[i] = 0;
	for(i = 0; i < n; ++i) c[x[i] = r[i]]++;
	for(i = 1; i < m; ++i) c[i] += c[i - 1];
	for(i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
	for(j = 1; p < n; m = p, j <<= 1) {
		p = 0;
		for(i = n - j; i < n; ++i) y[p++] = i;
		for(i = 0; i < n; ++i) if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0; i < m; ++i) c[i] = 0;
		for(i = 0; i < n; ++i) c[x[y[i]]]++;
		for(i = 1; i < m; ++i) c[i] += c[i - 1];
		for(i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
		p = 1, swap(x, y), x[sa[0]] = 0;
		for(i = 1; i < n; ++i)
			x[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + j] == y[sa[i - 1] + j] ? p - 1: p++;
	}
	rnk = x;
}

void get_height(int r[], int sa[], int n) {
	int i, j, k = 0;
	for(i = 0; i < n; height[rnk[i++]] = k) {
		for(k?k--:0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
	}
}

int main() {
	while(~scanf("%s %s", s1, s2)) {
		int n = 0;
		for(int i = 0; s1[i] != '\0'; ++i)
			r[n++] = s1[i] - 'a' + 1;
		r[n++] = 28;
		for(int i = 0; s2[i] != '\0'; ++i)
			r[n++] = s2[i] - 'a' + 1;
		r[n] = 0;
		build_sa(r, sa, n + 1, 30);
		get_height(r, sa, n);
		int mmax = -1, len = strlen(s1);
		for(int i = 1; i < n; ++i) {
			if(height[i] > mmax) {
				if((sa[i] < len && sa[i - 1] > len) || (sa[i - 1] < len && sa[i] > len))
					mmax = height[i];
			}
		}
		printf("%d\n", mmax);
	}
	return 0;
}