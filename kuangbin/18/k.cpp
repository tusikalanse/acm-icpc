#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 110020;
int wa[MAXN], wb[MAXN], r[MAXN], sa[MAXN], c[MAXN], *rnk, height[MAXN];
int vis[MAXN], mn[MAXN], mx[MAXN], id[MAXN], stk[MAXN];
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
		for(k?k--:0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
}

inline void mmax(int &a, int b) {
	if(a == -1 || a < b) 
		a = b;
}

inline void mmin(int &a, int b) {
	if(a == -1 || a > b)
		a = b;
}

bool check(int len, int n, int num) {
	memset(mn, -1, sizeof(mn));
	memset(mx, -1, sizeof(mx));
	memset(vis, 0, sizeof(vis));
	int sum = 0, top = 0;
	for(int i = 0; i < n; ++i) {
		if(height[i] >= len) {
			mmax(mx[id[sa[i]]], sa[i]);
			mmin(mn[id[sa[i]]], sa[i]);
			stk[++top] = id[sa[i]];
			if(mx[id[sa[i]]] - mn[id[sa[i]]] >= len) {
				sum += !vis[id[sa[i]]];
				vis[id[sa[i]]] = 1;
				if(sum >= num) {
					return true;
				}
			}
		}
		else {
			while(top) {
				int t = stk[top--];
				mn[t] = mx[t] = -1;
				vis[t] = 0;
			}
			sum = 0;
			mmax(mx[id[sa[i]]], sa[i]);
			mmin(mn[id[sa[i]]], sa[i]);
			stk[++top] = id[sa[i]];
		}
	}
	return false;
}

int main() {
	int T, n;
	scanf("%d", &T);
	while(T--) {
		int t = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%s", s);
			for(int j = 0; s[j]; ++j)
				r[t] = s[j], id[t++] = i;
			r[t++] = i;
		}
		r[--t] = 0;
		build_sa(r, sa, t + 1, 128);
		get_height(r, sa, t);
		int ans = 0, mid, L = 1, R = 5001;
		while(L <= R) {
			mid = L + R >> 1;
			if(check(mid, t + 1, n)) {
				ans = mid;
				L = mid + 1;
			}
			else
				R = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}