#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	for(int _ = 32; _ <= 33; ++_) {
		string str = "problem3/";
		str += to_string(_);
		str += ".in";
		ofstream fout(str, ios::out);
		int n = 10000, m = 100;
		fout << n << " " << m << endl;
		for(int i = 1; i <= m; ++i) 
			fout << 1 + rand() % 100 << " "  << 1 + rand() % 10000 << endl;
	}
	return 0;
}
