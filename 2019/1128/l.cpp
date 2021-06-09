#include <bits/stdc++.h>
using namespace std;

bool isprime(long long x) {
	for (long long i = 2; i * i <= x; ++i) {
		if (x % i == 0) return false;
	}
	return true;
}

vector<long long> v;
long long n;
int T, cas;

long long serach(long long &n, int ret) {
	long long x = *--upper_bound(v.begin(), v.end(), n - ret);
	n -= x;
	return x;
}

int main() {
	long long x = 1000000000000 - 10;
	while (x != 1) {
		while (!isprime(x)) x--;
		v.push_back(x);
		cout << x << endl;
		x *= 0.99;
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << "Case " << ++cas << ": ";
		if (n <= 11) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		for (int i = 0; i < 6; ++i) 
			cout << serach(n, 2 * (5 - i)) << (i == 5 ? '\n' : ' ');
	}
	return 0;
}