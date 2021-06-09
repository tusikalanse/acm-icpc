#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		if (n <= 5) {
			cout << "-1" << endl;
			continue;
		}
		else {
			if (n & 1)
				cout << 3 << " " << n - 3 << endl;
			else
				cout << 2 << " " << n - 2 << endl;
		}
	}


	return 0;
}