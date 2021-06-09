#include <bits/stdc++.h>
using namespace std;

int T, m;
string n;

int main() {
	cin >> T;
	while(T--) {
		cin >> m >> n;
		if(m > 2 || n[0] < n[1]) {
			cout << "YES" << endl << 2 << endl << n[0] << " " << n.substr(1) << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}