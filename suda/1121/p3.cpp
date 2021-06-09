#include <bits/stdc++.h>
using namespace std;


int main() {
	for(int i = 1; i <= 33; ++i) {
		string input = "problem3/";
		input += to_string(i);
		string output = input + ".out";
		input += ".in";
		system((string("python3 3py.py < ") + input.c_str() + " > " + output.c_str()).c_str());
	}
	return 0;
}

