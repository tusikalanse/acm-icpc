#include <bits/stdc++.h>
using namespace std;

inline int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int a, b, c;
	clock_t st = clock();
	cin >> a >> b >> c;
	int d = gcd(a, b);
	a /= d;
	b /= d;
	d = a/b;
	a -= d * b;
	a *= 10;
	int dig = 1;
	while((((double)clock() - st) / CLOCKS_PER_SEC) < 0.95) {
		d = a/b;
		if(d == c) {
			cout << dig << endl;
			return 0;
		}
		a -= d * b;
		a *= 10;
		dig++;
	}
	cout << -1 << endl;
	return 0;
}