#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 998244353;

int f[N], n, x, y, T;

int get(int x, int y) {
	if(x == y - 1) {
		if(x != 1 && y != n)
			return 0;
		return 1;
	}
	if(x != 1) x++;
	if(y != n) y--;
	return f[y - x];
}

int main() {
	f[0] = f[1] = f[2] = 1;
	for(int i = 3; i < N; ++i)
		f[i] = (f[i - 1] + f[i - 3]) % mod;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &x, &y);
		printf("%d\n", get(x, y));
	}
	return 0;
}