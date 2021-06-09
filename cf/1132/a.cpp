#include <bits/stdc++.h>
using namespace std;


int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a != d) {
		cout << 0 << endl;
	}
	else {
		if(a == 0 && c > 0) {
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	return 0;
}