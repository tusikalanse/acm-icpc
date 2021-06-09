#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	cout << 10 << endl;
	for(int _ = 1; _ <= 10; ++_) {
		cout << 100000 << endl;
		for(int i = 1; i <= 100000; ++i) {
			cout << (char)(rand() % 10 + 'A');
			cout << (char)(rand() % 10 + 'A');
			cout << (char)(rand() % 10 + 'A');
			cout << (char)(rand() % 10 + 'A');
			cout << "/";
			cout << (char)(rand() % 10 + 'A');
			cout << (char)(rand() % 10 + 'A');
			cout << "/";
			cout << (char)(rand() % 10 + 'A');
			cout << (char)(rand() % 10 + 'A');
			cout << endl;
		}
	}
	return 0;
}