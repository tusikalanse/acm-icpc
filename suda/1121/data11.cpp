#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	for(int _ = 21; _ <= 25; ++_) {
		string str = "problem11/";
		str += to_string(_);
		str += ".in";
		ofstream fout(str, ios::out);
		int T = 20;
		fout << T << endl;
		while(T--) {
			fout << 2 * (401 + rand() % 100) << endl;
		}
	}
	return 0;
}