#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int c[N], p[N], d[N], a[N], T, n;

inline int lowbit(int x) {
	return x & -x;
}

void add(int pos, int val) {
	for(int i = pos; i <= n; i += lowbit(i))
		c[i] += val;
}

int sum(int pos) {
	int res = 0;
	for(; pos; pos -= lowbit(pos))
		res += c[pos];
	return res;
}


int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		c[0] = p[0] = d[0] = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			c[i] = p[i] = d[i] = 0;
		}
		for(int i = 1; i <= n; ++i) {
			int b = a[i];
			if(p[b]) {
				add(p[b], -1);
				add(i, 1);
				d[sum(i) - sum(p[b] - 1)]++;
				p[b] = i;
			}
			else {
				add(i, 1);
				p[b] = i;
			}
		}
		int xx = n;
		for(int i = 1; i <= n; ++i) {
			if(i != 1)
				putchar(' ');
			xx -= d[i];
			printf("%d", xx);
		}
		puts("");
	}
	return 0;
}