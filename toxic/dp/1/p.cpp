#include <bits/stdc++.h>
using namespace std;

long long dp[1 << 18][100], n;
int a[20], N, m;

int main() {
	cin >> n >> m;
	dp[0][0] = 1;
	while(n) {
		a[N++] = n % 10;
		n /= 10;
	}
	sort(a, a + N);
	for(int mask = 0; mask < (1 << N); ++mask) {
		for(int i = 0; i < m; ++i) if(dp[mask][i]) {
			long long cnt = dp[mask][i];
			int pre = -1;
			for(int j = N - 1; j >= 0; --j) if((1 << j) & ~mask) {
				if(a[j] == pre) continue;
				if(a[j] == 0 && mask == 0) break;
				dp[mask | (1 << j)][(i * 10 + a[j]) % m] += cnt;
				pre = a[j];
			}
		}
	}
	cout << dp[(1 << N) - 1][0] << endl;
	return 0;
}