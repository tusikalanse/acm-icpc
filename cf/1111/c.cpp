#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a, n, k, A, B, pos[N];

long long cnt(int l, int r) {
	return lower_bound(pos + 1, pos + k + 1, r + 1) - lower_bound(pos + 1, pos + k + 1, l);
}

long long dfs(int l, int r, int len) {
	long long sum = cnt(l, r);
	if(sum == 0)
		return A;
	if(l == r)
		return 1LL * sum * B * len;
	return min(1LL * sum * B * len, dfs(l, l + len / 2 - 1, len / 2) + dfs(l + len / 2, r, len / 2));
}

int main() {
	scanf("%d%d%d%d", &n, &k, &A, &B);
	for(int i = 1; i <= k; ++i) {
		scanf("%d", &pos[i]);
	}
	sort(pos + 1, pos + k + 1);
	printf("%lld\n", dfs(1, (1 << n), (1 << n)));
	return 0;
}