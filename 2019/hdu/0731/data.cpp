#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << 3 << endl;
	for(int _ = 1; _ <= 3; ++_) {
		cout << 100000 << " " << 100000 << endl;
		for(int i = 1; i <= 100000; ++i) 
			cout << 1 + rand() % 1000000 << " ";
		cout << endl;
		for(int i = 1; i <= 100000; ++i) {
			cout << 1 << " " << 100000 << " " << 1 + rand() % 1000000 << " " << 169 << endl;
		}
	}
	return 0;
}