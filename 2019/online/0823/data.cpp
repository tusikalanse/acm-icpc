#include <bits/stdc++.h>
using namespace std;



int main() {
	cout << 5 << endl;
	for(int _ = 1; _ <= 5; ++_) {
		int M = 5e4, base = 1e9 - 6e4;
		cout << M << " " << M << " " << M << endl;
		cout << 1 << " " << 1 << " " << 1 << endl;
		for(int i = 2; i <= M; ++i)
			cout << 1 << " " << i << " " << base + i << endl;
		for(int i = 1; i <= M; ++i)
			cout << M << endl;
	}
	return 0;
}