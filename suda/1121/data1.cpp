#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	for(int _ = 31; _ <= 33; ++_) {
		string str = "problem1/";
		str += to_string(_);
		str += ".in";
		ofstream fout(str, ios::out);
		int n = 100;
		fout << n << " " << 1 + rand() % 100 << endl;
		for(int i = 1; i <= n; ++i) 
			fout << (char)('0' + (rand() % 2));
		fout << endl;
	}
	return 0;
}