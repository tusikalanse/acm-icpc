#include <bits/stdc++.h>
using namespace std;


int main() {
	int T = 2, n = 5e5, m = 5e5;
	freopen("in.txt", "w", stdout);
	cout << T << endl;
	while(T--) {
		cout << n << " " << m << endl;
		for(int i = 1; i <= n; ++i) 
			cout << rand() % (1 << 30) << " ";
		cout << endl;
		for(int i = 1; i <= m; ++i) {
			int op = rand() % 2;
			if(op == 0) {
				cout << op << " " << rand() % (1 << 30) << " " << rand() % (1 << 30) << endl;
			}
			else {
				cout << op << " " << rand() % (1 << 30) << endl;
			}
		}
	}
	return 0;
}