#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int ans = 0;
	while(a > 0 && b > 0) {
		if(a <= b) {
			a++;
			//a = min(a, 100);
			b -= 2;
		}
		else {
			b++;
			//b = min(b, 100);
			a -= 2;
		}
		ans += (a >= 0 && b >= 0);
	}
	cout << ans << endl;
	return 0;
}