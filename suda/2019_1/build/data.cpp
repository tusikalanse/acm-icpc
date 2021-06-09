#include <bits/stdc++.h>
using namespace std;

void input(int id) {
	string in = to_string(id) + ".in";
	ofstream fin(in);
	int n = 100, m = 1000, k = 20;
	fin << n << " " << m << " " << k << endl;
	for (int i = 1; i <= n; ++i) {
		fin << 1 + rand() % 100000 << " ";
	}
	fin << endl;
	for (int i = 1; i <= n; ++i) {
		fin << 1 + rand() % n << " ";
	}
	fin << endl;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		do {
			u = 1 + rand() % n, v = 1 + rand() % n;
		} while (u == v);
		fin << u << " " << v << endl;
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
	for(int i = 9; i <= 10; ++i) {
		input(i);
		output(i);
	}
	return 0;
}
