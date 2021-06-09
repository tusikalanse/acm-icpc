#include <bits/stdc++.h>
using namespace std;

int a[100000];
int b[100000];

void valid(int id) {
	string in = to_string(id) + ".in";
	ifstream fin(in);
	int n, m, k;
	fin >> n >> m >> k;
	cout << "id, n, m = " << id  << " " << n << " " << m << endl;
	assert(1 <= n);
	assert(n <= 100);
	assert(0 <= m);
	assert(m <= 1000);
	assert(1 <= k);
	assert(k <= 20);
	for (int i = 1; i <= n; ++i) {
		fin >> a[i];
		assert(a[i] >= 1);
		assert(a[i] <= 100000);
	}
	for (int i = 1; i <= n; ++i) {
		fin >> b[i];
		assert(b[i] >= 1); assert(b[i] <= n);
	}
	for (int i = 1; i <= m; ++i) {
		int x, y;
		fin >> x >> y;
		assert(x >= 1);
		assert(y >= 1);
		assert(x <= n);
		assert(y <= n);
	}
}

int main() {
	for (int i = 1; i <= 10; ++i)
		valid(i);
	cout << "DONE" << endl;
	return 0;
}