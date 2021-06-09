#include <bits/stdc++.h>
using namespace std;

void input(int id) {
	string in = to_string(id) + ".in";
	ofstream fin(in);
	int n = 100000;
	fin << n << endl;
	fin.close();
}

void output(int id) {
	string in = to_string(id) + ".in";
	string out = to_string(id) + ".out";
	system((string("python3 solution.py < ") + in + " > " + out).c_str());
}

int main() {
	srand(time(NULL));
	for(int i = 11; i <= 11; ++i) {
		input(i);
		output(i);
	}
	return 0;
}
