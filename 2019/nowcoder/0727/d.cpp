#include <bits/stdc++.h>
using namespace std;

int f, n, T;

int main() {
	cin >> T;
	while(T--) {
		cin >> n;
		if(n % 3 == 0) {
			cout << 1 << " " << n << endl;
			continue;
		}
		cout << "2";
		f = 0;
		for(int i = 3; i <= n; i += 3) {
			for(int j = 3; j <= n; j += 3) {
				if((i | j) == n) {
					cout << " " << i << " " << j << endl;
					f = 1;
					break;
				}
			}
			if(f)
				break;
		}
		if(f == 0)
			cout << "-1" << endl;
	}
	return 0;
}