#include <bits/stdc++.h>
using namespace std;


int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = a * 3 + 3;
	ans = min(ans, 3 * b);
	ans = min(ans, 3 * c - 3);
	cout << ans << endl;


	return 0;
}