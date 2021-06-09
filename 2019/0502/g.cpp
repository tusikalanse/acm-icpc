#include <bits/stdc++.h>
using namespace std;


int main() {
	int T, n;
	cin >> T;
	while(T--) {
		cin >> n;
		for(;; ++n) {
			if(n % 7 == 0 && n % 4 != 0) {
				cout << n << endl;
				break;
			}
		}
	}


	return 0;
}