#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 20010;
int r[MAXN], wa[MAXN], wb[MAXN], c[MAXN], sa[MAXN], *rnk, height[MAXN], n;

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

bool check(int len, int n) {
	int mmin = 0x3f3f3f3f, mmax = -0x3f3f3f3f;
	for(int i = 1; i < n; ++i) {
		if(height[i] >= len) {
			mmin = min(mmin, min(sa[i], sa[i - 1]));
			mmax = max(mmax, max(sa[i], sa[i - 1]));
			if(mmax - mmin > len)
				return true;
		}
		else {
			mmin = 0x3f3f3f3f;
			mmax = -0x3f3f3f3f;
		}
	}
	return false;
}

int main() {
	while(~scanf("%d", &n) && n) {
		for(int i = 0; i < n; ++i)
			scanf("%d", &r[i]);
		if(n == 1) {
			puts("0");
			continue;
		}
		for(int i = 0; i < n - 1; ++i)
			r[i] = r[i + 1] - r[i] + 100;
		r[--n] = 0;
		build_sa(r, sa, n + 1, 200);
		get_height(r, sa, n);
		int ans = 0, mid, L = 1, R = n;
		while(L <= R) {
			mid = L + R >> 1;
			if(check(mid, n + 1)) {
				ans = mid;
				L = mid + 1;
			}
			else
				R = mid - 1;
		}
		printf("%d\n", ans < 4 ? 0 : ans + 1);
	}
	return 0;
}