#include <bits/stdc++.h>
using namespace std;

void input(int id) {
	string in = to_string(id) + ".in";
	ofstream fin(in);
	int n = 100000, m = 100000;
	fin << n << " " << m << endl;
	for (int i = 1; i <= n; ++i) {
		fin << rand() % (1000 * min(n + 1 - i, i)) << " ";
	}
	fin << endl;
	for (int i = 1; i <= m; ++i) {
		int l = 1 + rand() % n, r = 1 + rand() % n;
		if (l > r) swap(l, r);
		fin << l << " " << r << endl;
	}
	fin.close();
}

void output(int id) {
	string in = to_string(id) + ".in";
	string out = to_string(id) + ".out";
	system((string("python3 prog.py < ") + in + " > " + out).c_str());
}

int main() {
	srand(time(NULL));
	for(int i = 10; i <= 10; ++i) {
		input(i);
		output(i);
	}
	return 0;
}
