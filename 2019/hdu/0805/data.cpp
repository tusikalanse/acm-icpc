#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << 5 << endl;
	for(int _ = 1; _ <= 5; ++_) {
		cout << 100000 << " " << 19328432 << endl;
		for(int i = 1; i <= 100000; ++i) {
			cout << 1 + rand() % 1000 << " " << -1000 + rand() % 2001 << endl;
		}
	}
	return 0;
}
