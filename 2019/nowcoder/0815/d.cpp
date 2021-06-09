#include <bits/stdc++.h>
using namespace std;

int n, p, q;
long long s, a[40];
int to[(1 << 18) + 10];

map<long long, int> pp;

void init() {
	int msk = 2;
	to[1] = 0;
	for(int i = 1; i <= 17; ++i) {
		to[msk] = i;
		msk *= 2;
	}
}

void print(int maskp, int maskq) {
	for(int i = 0; i < p; ++i) 
		printf("%d", 1 & (maskp >> i));
	for(int i = 0; i < q; ++i)
		printf("%d", 1 & (maskq >> i));
	puts("");
}

int main() {
	init();
	cin >> n >> s;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	p = n / 2;
	q = n - p;
	for(int i = 0; i < (1 << p); ++i) {
		long long tmp = 0;
		for(int j = i; j; j -= j & -j)
			tmp += a[to[j & -j]];
		pp[tmp] = i;
	}
	for(int i = 0; i < (1 << q); ++i) {
		long long tmp = 0;
		for(int j = i; j; j -= j & -j) 
			tmp += a[to[j & -j] + p];
		auto it = pp.lower_bound(s - tmp);
		if(it->first + tmp == s) {
			print(it->second, i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}