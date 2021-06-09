#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, a[N], b[N], ans, tmp, vis[N];
char s[N];
int main() {
	cin >> n >> s;
	for(int i = 1; i <= n; ++i) {
		vis[i] = s[i - 1] - '0';
		cin >> a[i] >> b[i];
	}
	for(int t = 0; t <= 10000; ++t) {
		tmp = 0;
		for(int i = 1; i <= n; ++i)
			tmp += vis[i];
		ans = max(ans, tmp);
		for(int i = 1; i <= n; ++i) {
			if(t >= b[i] && (t - b[i]) % a[i] == 0)
				vis[i] ^= 1;
		}
	}
	cout << ans << endl;
	return 0;
}