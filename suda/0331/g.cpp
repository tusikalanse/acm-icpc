#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, c, d, m, mm; 
	long long ans = 0;
	cin >> n >> a >> b >> c >> d;
	m = n + min(min(a+b, a+c), min(b+d, c+d));
	mm = max(max(a+b, a+c), max(b+d, c+d));
	ans += 1LL * max(0, m-mm) * n;
	cout << ans << endl;
	return 0;
}