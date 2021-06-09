#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 1e6, m = 2e5, k = 1e6;
	cout << n << " " << k << " " << m << endl;
	for(int i = 1; i <= m; ++i) {
		int l = 1 + rand() % n, r = 1 + rand() % n, c = 1 + rand() % n, p = 1 + rand() % n;
		if(l > r)
			swap(l, r);
		cout << l << " " << r << " " << c << " " << p << endl;
	}

	return 0;
}