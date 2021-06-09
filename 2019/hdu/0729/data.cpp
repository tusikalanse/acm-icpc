#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << 5 << endl;
	for(int i = 1; i <= 5; ++i) {
		cout << 2000 << " " << 10 << endl;
		for(int j = 1; j <= 2000; ++j) {
			cout << 1 +rand()%100000 << " ";
		}
		cout << endl;
	}



	return 0;
}