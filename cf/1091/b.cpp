#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	long long a = 0, b = 0, ta, tb;
	cin >> n;
	for(int i = 1; i <= 2 * n; ++i) {
		cin >> ta >> tb;
		a += ta;
		b += tb;
	}
	a /= n;
	b /= n;
	cout << a << " " << b << endl;


	return 0;
}