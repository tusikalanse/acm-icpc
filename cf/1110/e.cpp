#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 1e5 + 10;

int n;
LL c[N], t[N], d[N];
multiset<int> a, b;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &c[i]);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &t[i]);
		if(i == 1 || i == n) {
			if(c[i] != t[i]) {
				puts("No");
				return 0;
			}
		}
		if(i != 1) {
			a.insert(c[i] - c[i - 1]);
			b.insert(t[i] - t[i - 1]);
		}
	}
	if(a != b) {
		puts("No");
	}
	else
		puts("Yes");
	return 0;
}