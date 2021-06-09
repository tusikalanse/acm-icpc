#include <bits/stdc++.h>
using namespace std;

int T;
long long k, x;
int main() {
	cin >> T;
	while(T--) {
		cin >> k >> x;
		cout << 9 * (k - 1) + x << endl;
	}
	return 0;
}