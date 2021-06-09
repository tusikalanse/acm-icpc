#include <bits/stdc++.h>
using namespace std;

int n, a, b, aa, bb, ans = 1;
int main() {
	cin >> n;
	while(n--) {
		cin >> a >> b;
		ans += max(0, min(a, b) - max(aa, bb) + (aa != bb));
		aa = a;
		bb = b;
	}
	cout << ans << endl;
	return 0;
}