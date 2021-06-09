#include <bits/stdc++.h>
using namespace std;

int a[100000];
int b[100000];

void valid(int id) {
	string in = to_string(id) + ".in";
	ifstream fin(in);
	int n, m;
	fin >> n >> m;
	cout << "id, n, m = " << id  << " " << n << " " << m << endl;
	assert(1 <= n);
	assert(n <= 100);
	assert(1 <= m);
	assert(m <= 1000);
	for (int i = 1; i <= m; ++i) {
		int p, l; string s;
		fin >> p >> s;
		assert(p >= 1);
		assert(p <= n);
		l = s.size();
		assert(l >= 1);
		assert(l <= 50);
	}
}

int main() {
	for (int i = 1; i <= 12; ++i)
		valid(i);
	cout << "DONE" << endl;
	return 0;
}