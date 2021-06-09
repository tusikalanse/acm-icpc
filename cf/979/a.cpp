#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if(n == 0)
		cout << 0 << endl;
	else {
		++n;
		int cnt = 0;
		long long cp = n;
		if((cp & 1) == 0) {
			cout << cp/2 << endl;
		}
		else
			cout << n << endl;
	}


	return 0;
}