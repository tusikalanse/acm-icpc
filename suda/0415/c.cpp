#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
ll dp[100010][12];
int a[100010];

inline int lowbit(int x) {
	return x & -x;
}

void update(int i, int y, ll x) {
	for(; i <= n; i += lowbit(i))
		dp[i][y] += x;
}

ll query(int x, int y) {
	ll ans = 0;
	for(int i = x; i > 0; i -= lowbit(i)) {
		ans += dp[i][y];
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &k);
	if(k == 0) {
		cout << n << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		update(a[i], 1, 1);
		for(int j = 2; j <= min(i, k) + 1; j++) {
			ll temp = query(a[i] - 1, j - 1);
			update(a[i], j, temp);
		}
	}
	printf("%lld\n", query(n, k + 1));
	return 0;
}