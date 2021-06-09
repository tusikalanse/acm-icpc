#include <bits/stdc++.h>
using namespace std;

long long n, k, ans;

int main() {
	cin >> n >> k;
	if(n + n - 1 < k || n == 1 || k == 1) {
		ans = 0;
	}
	else if(n >= k - 1) {
		ans = (k - 1) / 2;
	}
	else {
		ans = (n - (k - n) + 1) / 2;
	}
	cout << ans << endl;
	return 0;
}