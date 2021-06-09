#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 998244353;

int pow2[N], pow3[N];
int pos[N], be[N], to[N], rnk[N];
int n, com, x, y, m;

int find(int x) {
	if(pos[x] == x) 
		return x;
	int pre = pos[x];
	pos[x] = find(pos[x]);
	if(pre != pos[x]) {
		be[x] += be[pre];
		rnk[x] += rnk[pre];
		to[x] += to[pre];
	}
	return pos[x]; 
}

int main() {
	pow2[0] = pow3[0] = 1;
	for(int i = 1; i < N; ++i) {
		pow2[i] = 2LL * pow2[i - 1] % mod;
		pow3[i] = 3LL * pow3[i - 1] % mod;
		pos[i] = i;
	}
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d", &com);
		if(com == 1) {
			scanf("%d %d", &x, &y);
			pos[y] = x;
			be[x]++;
			rnk[y] = be[x];
			to[y]++;
		}
		else {
			scanf("%d", &x);
			int t2;
			if(find(x) == x)
				t2 = be[x];
			else
				t2 = be[find(x)] - rnk[x] + be[x];
			int t1 = to[x], t3 = n - t2 - t1;
			printf("%lld\n", 1LL * pow2[t2] * pow3[t3] % mod);
		}
	}
	return 0;
}