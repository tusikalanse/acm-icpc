#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

const int BIT = 20, MAXN = (1 << BIT), N = 3e5 + 10;

int a[N], pos[MAXN], n;

int main() {
	scanf("%d", &n);
	memset(pos, 0x3f, sizeof(pos));
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1];
		pos[a[i]] = min(pos[a[i]], i);
	}
	for(int i = 0; i < BIT; ++i) {
		for(int j = 0; j < MAXN; ++j) {
			if(!((1 << i) & j)) {
				pos[j] = min(pos[j], pos[j ^ (1 << i)]);
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		int p = 0;
		for(int j = BIT - 1; ~j; --j) {
			if(!((1 << j) & a[i]) && pos[p ^ (1 << j)] <= i)
				p ^= (1 << j);
		}
		printf("%d\n", (p << 1) + a[i]);
	}
	return 0;
}