#include <bits/stdc++.h>
using namespace std;

int a[100010], s[100010];

int main() {
	int n, p;
	cin >> n >> p;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = a[i] + s[i-1];
		s[i] %= p;
	}
	int ans = 0;
	for(int i = 1; i < n; i++) {
		ans = max(ans, s[i] % p + (s[n] - s[i] + p) % p);
	}
	cout << ans << endl;
	return 0;
}