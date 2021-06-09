#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	for(int _ = 23; _ <= 25; ++_) {
		string str = "problem9/";
		str += to_string(_);
		str += ".in";
		ofstream fout(str, ios::out);
		int T = 10;
		fout << T << endl;
		while(T--) {
			int n = 100;
			fout << n << endl;
			for(int i = 1; i <= n; ++i) {
				fout << rand() % 41 - 20;
				if(i != n)
					fout << " ";
				else
					fout << endl;
			}
		}
	}
	return 0;
}