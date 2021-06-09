#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	long long ans = 0;
	while(a && b) {
		ans += a/b;
		a %= b;
		if(a != 0) {
			ans += b/a;
			b %= a;
		}
	}
	cout << ans << endl;
	return 0;
}