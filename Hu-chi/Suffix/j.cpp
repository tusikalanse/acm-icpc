#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 200010;
char s1[MAXN], s2[MAXN];
int r[MAXN], wa[MAXN], wb[MAXN], c[MAXN], sa[MAXN], *rnk, height[MAXN], ls1, n;

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

void mmin(int &a, int b) {
	if(a == -1 || a > b)
		a = b;
}

bool check(int len) {
	for(int i = 2; i <= n; ++i) {
		if(height[i] >= len && height[i - 1] < len && height[i + 1] < len)
			if((sa[i] < ls1 && sa[i - 1] > ls1) || sa[i] > ls1 && sa[i - 1] < ls1)
				return true;
	}
	return false;
}


int main() {
	while(~scanf("%s %s", s1, s2)) {
		int L = 1, R;
		for(int i = 0; s1[i] != '\0'; ++i)
			r[n++] = s1[i] - 'a' + 1;
		R = n + 1;
		r[n++] = 28;
		for(int i = 0; s2[i] != '\0'; ++i)
			r[n++] = s2[i] - 'a' + 1;
		r[n] = 0;
		R = min(R, n - R);
		build_sa(r, sa, n + 1, 30);
		get_height(r, sa, n);
		int ans = -1;
		ls1 = strlen(s1);
		for(int i = L; i <= R; ++i)
			if(check(i)) {
				ans = i;
				break;
			}
		printf("%d\n", ans);
	}
	return 0;
}