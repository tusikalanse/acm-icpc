#include <bits/stdc++.h>
using namespace std;



int main() {
	srand(time(NULL));
	for(int _ = 1; _ <= 10; ++_) {
		string str = "problem8/";
		str += to_string(_);
		str += ".in";
		ofstream fout(str, ios::out);
		int n = 1 + rand() % 10, k = 1 + rand() % 100;
		fout << n << endl << k << endl;
		while(n--) {
			fout << fixed << setprecision(2) << ((double)rand() / RAND_MAX) * (1 + rand() % 100000) << endl;
		}
	}
	return 0;
}