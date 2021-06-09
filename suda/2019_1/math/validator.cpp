#include <bits/stdc++.h>
using namespace std;

void valid(int id) {
	string in = to_string(id) + ".in";
	ifstream fin(in);
	int n, m;
	fin >> n >> m;
	cout << "id, n, m = " << id  << " " << n << " " << m << endl;
	assert(1 <= n);
	assert(n <= 100000);
	assert(1 <= m);
	assert(m <= 100000);
	for (int i = 1; i <= n; ++i) {
		int a;
		fin >> a;
		assert(a >= 0); assert(a <= 1000000000);
	}
	for (int i = 1; i <= m; ++i) {
		int l, r;
		fin >> l >> r;
		assert(1 <= l);
		assert(l <= r);
		assert(r <= n);
	}
}

int main() {
	for (int i = 1; i <= 10; ++i)
		valid(i);
	cout << "DONE" << endl;
	return 0;
}