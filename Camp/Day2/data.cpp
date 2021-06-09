#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	int T = 6000;
	cout << T << endl;
	while(T--) {
		int n = 12;
		while(n--) {
			cout << (1 + rand() % (1000000000)) << " ";
		}
		cout << endl;
	}
	return 0;
}