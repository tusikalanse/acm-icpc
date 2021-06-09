#include <bits/stdc++.h>
#define LL long long
using namespace std;


const int mod = 1e9 + 7;
const int MAXN = 1000010;

LL qp(LL a, LL n) {
	LL res = 1;
	while(n) {
		if(n & 1) 
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

int wa[MAXN], wb[MAXN], c[MAXN], r[MAXN], sa[MAXN], *rnk, height[MAXN], RMQ[MAXN][16];
char s[MAXN];
int a[MAXN];

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
	int n, m, l, num;
	LL ans = 1;
	scanf("%d %d %s", &n, &m, s);
	num = n;
	l = strlen(s);
	for(int i = 0; i < l; ++i)
		r[i] = s[i];
	r[l] = 0;
	build_sa(r, sa, l + 1, 128);
	get_height(r, sa, l);
	RMQ_init(l);
	if(m)
		scanf("%d", &a[0]);
	for(int i = 1; i < m; ++i) {
		scanf("%d", &a[i]);
		if(a[i] - a[i - 1] >= n)
			continue;
		if(query(rnk[0], rnk[a[i] - a[i - 1]]) < l - a[i] + a[i - 1]) {
			puts("0");
			return 0;
		}
	}
	if(m)
		num -= l;
	for(int i = 1; i < m; ++i) {
		num -= a[i] + l - 1 - max(a[i], a[i - 1] + l) + 1;
	}
	ans = qp(26, num);
	printf("%lld\n", ans);
	return 0;
}
